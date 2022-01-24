/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:14:16 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/24 15:02:24 by jemartel         ###   ########.fr       */
/*   Updated: 2022/01/20 16:22:57 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_bultin(t_jobs *job)
{
	job->cmd = job->eval;
	if (job->cmd_type == -2)
		return (1);
	if (job->cmd_type == 5)
		do_env(job);
	if (job->cmd_type == 6)
		do_export(job);
	if (job->cmd_type == 8)
		do_echo(job);
	if (job->cmd_type == 9)
		do_unset(job);
	if (job->cmd_type == 10)
		do_pwd(job->cmd);
	if (job->cmd_type == 11)
		do_cd(job->cmd);
	return (0);
}

int	job_count(t_jobs *job)
{
	int		i;
	t_jobs	*temp;

	i = 0;
	temp = job;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	check_nb_of_cmd(t_jobs *job)
{
	int	i;

	i = 0;
	if (!job || !job->eval || !job->eval[0])
		return (0);
	while (job->cmd[i])
		i++;
	return (i);
}

/*function that should fork the process and execute what inside 
* since the process duplicate all the memory in the process
* we should try to clear all the  the memory of the other jobs
* otherwise it will counted as still reachable(leaks)
* */
void	start_job(t_jobs *job, t_dlist *lst, int pipes[], int state)
{
	if (job->cmd_type >= 0)
	{
		redir_handler(job);
		check_bultin(job);
		return ;
	}
	if (redir_handler(job) >= 0)
		g_state.output = path_resolver(job, lst, pipes, state);
}
