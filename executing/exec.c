/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:49:42 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/03 19:50:33 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <sys/wait.h>
// Cette fonction cree et init la struct s_exec: ENV & EXPORT
void init_exec(char **envp)
{
    create_env(envp);
    create_export(envp);
}
int check_bultin(t_jobs *job)
{
	if(job)
	{
		if (job->cmd_type == -2)
			return(1);	
		if (job->cmd_type == 6)
            do_export(job);
    	if (job->cmd_type == 5)
			do_env(job);
    	if (job->cmd_type == 9)
			do_unset(job);
	return(0);
	}
		//missing pwd echo  cd exit
return(0);
}
/* function that should fork the process and execute what inside 
*  since the process duplicate all the memory in the process
* we should try to clear all the  the memory of the other jobs
* otherwise it will counted as still reachable(leaks)
* */

void start_job(t_jobs *job,t_dlist *lst,t_jobs *head)
{
pid_t child;
int status;
if(check_bultin(job) == 0)
	{
		printf("not forked \n");
		return;
	}
else if(check_bultin(job) == 1)
{
	child = fork();
	(void)lst;
	if(child == 0)
		{
			//free_redir(job->redir);
			free_nodes(lst);
			free_jobs(head,0);
			freelist(g_state.env);
			exit(0);
		}
	waitpid(-1,&status,0);
}
else
	return;

}
