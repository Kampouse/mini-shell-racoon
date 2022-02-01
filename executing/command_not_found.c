/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_not_found.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:02:07 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/01 16:14:37 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minishell.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>

void	command_not_found(t_jobs *job)
{
	struct stat		sa;

	if (job->eval)
	{
		if (strncmp(job->eval[0], "./", 2) == 0 || strncmp(job->eval[0],
				"../", 2) == 0)
		{
			if (stat(job->eval[0], &sa) == 0 && !(sa.st_mode & S_IXUSR))
			{
				ft_putstr_fd(job->eval[0], 2);
				ft_putstr_fd(": Permission Denied", 2);
				ft_putstr_fd("\n", 2);
				g_state.output = 126;
				return ;
			}
			perror(job->eval[0]);
			g_state.output = 126;
			return ;
		}
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(job->eval[0], 2);
		ft_putstr_fd("\n", 2);
		g_state.output = 127;
	}
}

int	is_file_exec(t_jobs *job)
{
	struct stat	stats;

	g_state.output = 0;
	if (job->eval)
	{
		if (!(strncmp(job->eval[0], "./", 2)))
		{
			if (stat(job->eval[0], &stats) == 0 && stats.st_mode & S_IXUSR)
				return (0);
		}
		if (stat(job->eval[0], &stats) == 0 && stats.st_mode & S_IXUSR)
		{
			return (0);
		}
		if (check_bultin(job) == 1)
			command_not_found(job);
		return (1);
	}
	return (0);
}
