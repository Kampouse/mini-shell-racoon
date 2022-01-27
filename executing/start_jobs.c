/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:14:16 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/27 13:49:29 by jemartel         ###   ########.fr       */
/*   Updated: 2022/01/20 16:22:57 by olabrecq         ###   ########.fr       */
/*   Updated: 2022/01/25 13:20:34 by olabrecq         ###   ########.fr       */
/*   Updated: 2022/01/26 14:20:22 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_bultin(t_jobs *job)
{
	job->cmd = job->eval;
	if (job->cmd_type == -2)
		return (1);
	else if (job->cmd_type == 5)
		g_state.output = do_env(job);
	else if (job->cmd_type == 6)
		g_state.output = do_export(job);
	else if (job->cmd_type == 7)
		g_state.output = do_exit(job->cmd);
	else if (job->cmd_type == 8)
		g_state.output = do_echo(job);
	else if (job->cmd_type == 9)
		g_state.output = do_unset(job);
	else if (job->cmd_type == 10)
		g_state.output = do_pwd(job->cmd);
	else if (job->cmd_type == 11)
		g_state.output = do_cd(job->cmd);
	return (g_state.output);
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
void	start_job(t_jobs *job, t_dlist *lst, t_pipe *pipes)
{
	
	if (job->cmd_type >= 0)
	{
		//pipe_handler(pipes);
		redir_handler(job);
		check_bultin(job);
		//start_signal(0);
		pipes->state++;
		return ;
	}
	if (redir_handler(job) >= 0)
	{
		g_state.output = path_resolver(job, lst, pipes);
	}
}
