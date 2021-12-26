#include "../minishell.h"

void check_bultin(t_jobs *job)
{
	if(!job)
	{
		return;
	}
		printf("cmd type = %d\n", job->cmd_type);
		if (job->cmd_type == 6)
            do_export(job);
    	if (job->cmd_type == 5)
			do_env(job);
    //	if (job->cmd_type == 9)
		//	do_unset(job);
//     if (!(ft_strncmp(job->cmd[0], "echo", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "pwd", ft_strlen(trimed))))
//PATH DANS READLINE
//     if (!(ft_strncmp(job->cmd[0], "cd", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "exit", ft_strlen(trimed))))
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
	if(!job || !job->cmd || !job->cmd[0])
		return(0);
	while (job->cmd[i])
		i++;
	return (i);
}

void check_jobs(t_jobs *job)
{
	// printf("number of job = %d\n", check_nb_of_job(job));
	printf("number of cmd = %d\n", check_nb_of_cmd(job));
	check_bultin(job);

	// parse_job(job);
}
