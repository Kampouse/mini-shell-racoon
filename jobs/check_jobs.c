#include "../minishell.h"



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
