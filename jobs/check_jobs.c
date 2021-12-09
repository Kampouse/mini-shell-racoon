#include "../minishell.h"

void check_bultin(t_jobs *job)
{
	if( job && job->cmd)
	{
		if (! (ft_strncmp(job->cmd[0], "export", ft_strlen(job->cmd[0]))))
            do_export(job);
		}
//     if (!(ft_strncmp(job->cmd[0], "echo", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "env", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "pwd", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "cd", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "unset", ft_strlen(trimed))))
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

void check_jobs(t_jobs *job)
{
	if(job)
		printf("number of job = %d\n", check_nb_of_job(job));
	check_bultin(job);
}
