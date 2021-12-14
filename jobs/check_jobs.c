#include "../minishell.h"

void check_bultin(t_jobs *job)
{
	// Condiotion useless que je vais srm delete
	if(job && job->cmd)
	{
		if (job->cmd_type == 6)
            do_export(job);
    	if (!(ft_strncmp(job->cmd[0], "env", ft_strlen(job->cmd[0]))))
			do_env(job);
//     if (!(ft_strncmp(job->cmd[0], "echo", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "pwd", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "cd", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "unset", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "exit", ft_strlen(trimed))))
	}
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
	while (job->cmd[i])
		i++;
	return (i);
}
/*L'idee derriere parse_job est de type chaque caractere et chaque espace quo'on m'envois 
dans job->cmd  */
// void parse_job(t_jobs *job)
// {
// 	int i;
// 	int j;
// 	int **type_arr;

// 	i = 0;
// 	type_arr = (char **)malloc(sizeof(job->cmd));
// 	while (job->cmd[i])
// 	{
// 		j = 0;
// 		while (job->cmd[i][j])
// 		{
// 			if (ft_isalpha(job->cmd[i][j]))
// 				type_arr[i][j] = CHAR;
// 			if (job->cmd[i][j] == ' ')
// 				type_arr[i][j] = DELIM;
// 			j++;
// 		}
// 		i++;
// 	}
// }

void check_jobs(t_jobs *job)
{
	// printf("number of job = %d\n", check_nb_of_job(job));
	printf("number of cmd = %d\n", check_nb_of_cmd(job));

	// parse_job(job);
	check_bultin(job);
}
