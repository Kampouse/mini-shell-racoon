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
void start_job(t_jobs *job, t_dlist *lst,t_jobs *head)
{
	//pid_t child;
	//int status;
    (void)lst;
    (void)head;
	if(check_bultin(job) == 0)
	{
        printf("%d\n",redir_handler(job));
		printf("builtin as been handled\n");
		return;
	}
	else if(check_bultin(job) == 1)
	{

		//find_env(g_state.env,
	//	child = fork();
		//(void)lst;
		//if(child == 0)
		//{
          //  redir_handler(job);
            //does not work on nixos
            path_resolver(findpath(g_state.env),job->cmd,g_state.env);
			//free_nodes(lst);
			//free_jobs(head,0);
			//freelist(g_state.env);
			//exit(0);
		//}
		//waitpid(-1,&status,0);
	}
}
