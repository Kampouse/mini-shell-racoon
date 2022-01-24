/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:47:23 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/24 15:35:41 by jemartel         ###   ########.fr       */
/*   Updated: 2022/01/21 13:33:28 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "../minishell.h"
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

/* fork the process  before exectuion  and wait for the child */

int	path_resolver(t_jobs *job, t_dlist *lst, int pipes[], int state)
{
	int			pid;
	int			status;
	const char	*local = make_executable(job);

	if (!local || is_folder(job, (char *)local))
		return (g_state.output);
	pid = fork();
	if (pid < 0)
		return (-1);
	start_signal(1);
	if (pid == 0)
	{
		(void)pipes;
		(void)state;
		redir_handler(job);
		start_signal(2);
		pipe_handler(pipes, state, job);
		exec_the_bin((char *)local, job, lst);
	}
	waitpid(pid, &status, 0);
	free((char *)local);
	start_signal(1);
	return (WEXITSTATUS(status));
}
