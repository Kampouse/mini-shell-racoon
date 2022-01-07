#include "../minishell.h"

int check_bultin(t_jobs *job)
{
    job->cmd = job->eval;

		if(job->cmd_type == -2)
			return(1);
		if (job->cmd_type == 6)
            do_export(job);
    	if (job->cmd_type == 5)
			do_env(job);
    	if (job->cmd_type == 9)
			do_unset(job);
    	if (job->cmd_type == 8)
			do_echo(job);
			//exit =7
//     if (!(ft_strncmp(job->cmd[0], "pwd", ft_strlen(trimed))))
//PATH DANS READLINE
//     if (!(ft_strncmp(job->cmd[0], "cd", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "exit", ft_strlen(trimed))))
	return(0);
}

int check_nb_of_job(t_jobs *job)
{
	int i;

	i = 0;
	while (job != NULL)
	{
		job = job->next;
		i++;
	}
	return (i);
}

int check_nb_of_cmd(t_jobs *job)
{
	int i;

	i = 0;
	if(!job || !job->eval || !job->eval[0])
		return(0);
	while (job->cmd[i])
		i++;
	return (i);
}

/* function that should fork the process and execute what inside 
*  since the process duplicate all the memory in the process
* we should try to clear all the  the memory of the other jobs
* otherwise it will counted as still reachable(leaks)
* */
void start_job(t_jobs *job, t_dlist *lst)
{
	//pid_t child;
	int oldstdin;
	if(job->cmd_type >= 0)
	{
		oldstdin = dup(0);
        redir_handler(job);
		check_bultin(job);
		dup2(oldstdin,0);
		printf("builtin as been handled\n");
		return;
	}
	else if(check_bultin(job) == 1)
            g_state.output = path_resolver(job,lst);
}
