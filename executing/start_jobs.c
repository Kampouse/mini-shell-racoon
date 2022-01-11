#include "../minishell.h"

int check_bultin(t_jobs *job)
{
    job->cmd = job->eval;

	if(job->cmd_type == -2)
		return(1);
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
//PATH DANS READLINE
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

void add_his(t_jobs *job)
{
	int i;

	i = 0;
	while (job->eval[i])
	{
		add_history(job->eval[i]);
		printf("%s\n", job->eval[i++]);
	}
	history_list();
}

/*function that should fork the process and execute what inside 
* since the process duplicate all the memory in the process
* we should try to clear all the  the memory of the other jobs
* otherwise it will counted as still reachable(leaks)
* */
void start_job(t_jobs *job, t_dlist *lst)
{
	//pid_t child;
	int oldstdin;

    (void)oldstdin;
	if(job->cmd_type >= 0)
	{
		printf("cmd type = %d\n", job->cmd_type);
        redir_handler(job);
		check_bultin(job);
		printf("builtin as been handled\n");
		return;
	}
	else if(check_bultin(job) == 1)
        g_state.output = path_resolver(job,lst);
}
