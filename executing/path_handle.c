/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:22:52 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/12 16:09:25 by jemartel         ###   ########.fr       */
/*   Updated: 2022/02/12 15:47:16 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minishell.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>

char	*local_exec(t_jobs *job);

int	any_executable(char **path, t_jobs *job)
{
	char			*temp;
	int				inc;
	struct stat		sa;

	inc = 0;
	if (path)
	{
		while (path && path[inc] && job->eval)
		{
			temp = ft_str3join(path[inc], "/", job->eval[0]);
			if (stat(temp, &sa) == 0 && sa.st_mode & S_IXUSR)
			{
				free(temp);
				return (inc);
			}
			free(temp);
		inc++;
		}
	}
	if (path)
		freelist(path);
	return (-1);
}

/* last stage of execution of the command if not built in */
int	exec_the_bin(char *paths, t_jobs *job, t_dlist *lst, t_pipe *pipes)
{
	freelist(g_state.exprt);
	free_list(lst);
	lst = NULL;
	delete_pipe(pipes, 1);
	rl_clear_history();
	if (redir_handler(job) >= 0 && g_state.error != 2)
	{
		if (g_state.env)
		{
			signal(SIGQUIT, SIG_DFL);
			execve(paths, job->eval, g_state.env);
		}
		command_not_found(job);
	}
	free_jobs(job, 0);
	free(paths);
	freelist(g_state.env);
	rl_clear_history();
	exit(127);
	return (0);
}

char	*make_executable(t_jobs *job)
{
	const char	**paths = (const char **)ft_split(findpath(g_state.env), ':');
	int			location;
	char		*temp;

	location = 0;
	if (any_executable((char **)paths, job) == -1)
	{
		if (is_file_exec(job))
			return (NULL);
		return (local_exec(job));
	}
	location = any_executable((char **)paths, job);
	temp = ft_str3join(paths[location], "/", job->eval[0]);
	if (strncmp(job->eval[0], "./", 2) == 0)
	{
		freelist((char **)paths);
		command_not_found(job);
		free(temp);
		return (NULL);
	}
	freelist((char **)paths);
	return (temp);
}

char	*local_exec(t_jobs *job)
{
	char			cwd[4096];
	char			*temp;
	struct stat		sa;

	getcwd(cwd, 4096);
	if (job->eval && ft_strncmp(job->eval[0], "./", 2) == 0)
	{
		temp = job->eval[0];
		temp = ft_str3join(cwd, "/", temp);
		if (stat(temp, &sa) == 0 && sa.st_mode & S_IXUSR)
			return (temp);
		free(temp);
	}
	if (job->eval && stat(job->eval[0], &sa) == 0 && sa.st_mode & S_IXUSR)
	{
		return (ft_strdup(job->eval[0]));
	}
	command_not_found(job);
	return (NULL);
}
