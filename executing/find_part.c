/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:16:10 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/08 18:06:50 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "../minishell.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>

char	*find_part(char *first, char *str, int inc, size_t **len)
{
	(void)len;
	(void)inc;
	(void)str;
	if (!first)
	{
		ft_putstr_fd("you should learn how to type! :rage: \n", 2);
		len = NULL;
		first = NULL;
		g_state.output = 130;
		return (NULL);
	}
	len = NULL;
	return (first);
}

int	same_len(char *str, char *str2)
{
	if (str && str2)
	{
		if (ft_strlen(str) == ft_strlen(str2))
			return (0);
		else
			return (1);
	}
	return (-1);
}

int	is_folder(t_jobs *jobs, char *local)
{
	struct stat	stats;

	if (local)
	{
		stat(local, &stats);
		if (S_ISREG(stats.st_mode) == 0 && ft_strlen(jobs->eval[0]) != 0)
		{
			ft_putstr_fd("IS a directory: ", 2);
			ft_putstr_fd(jobs->eval[0], 2);
			ft_putstr_fd("\n", 2);
			free(local);
			g_state.output = 126;
			return (1);
		}
	}
	return (0);
}

void	delete_builtin(t_jobs *job, t_pipe *pipes, const char *local)
{
	if (job->cmd_type >= 0)
	{
		check_bultin(job);
		job->status = g_state.output;
		while (job->prev)
			job = job->prev;
		free_jobs(job, 0);
		freelist(g_state.exprt);
		freelist(g_state.env);
		rl_clear_history();
		delete_pipe(pipes, 1);
		free((void *) local);
		exit(g_state.output);
	}
}

int	path_resolver(t_jobs *job, t_dlist *lst, t_pipe *pipes)
{
	int			pid;
	int			status;
	const char	*local = make_executable(job);

	if (!local || is_folder(job, (char *)local))
		return (g_state.output);
	status = 0;
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		handle_fd(pipes);
		rl_clear_history();
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		delete_builtin(job, pipes, local);
		job->status = g_state.output;
		exec_the_bin((char *)local, job, lst, pipes);
	}
	handle_fd_main(pipes);
	free((char *)local);
	dup2(g_state.stdin, 0);
	return (WEXITSTATUS(status));
}
