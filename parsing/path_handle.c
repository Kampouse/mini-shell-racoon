#include "../libft/libft.h"
#include "../minishell.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
t_jobs	*ft_firstjob(t_jobs *currlist)
{
	if(currlist->prev == NULL)
		return(currlist);
	while (currlist)
	{
		if (currlist->prev == NULL)
			return (currlist);
		currlist = currlist->prev;
	}
	return (currlist);
}

/* last stage of execution of the command if not built in */
int exec_the_bin(char **paths,t_jobs *job, char **envp,t_dlist *lst)
{
	int inc;
	char *temp;
	inc = -1;
	execve(job->eval[0],job->eval,envp);
	while(paths[++inc])
	{
		temp = ft_str3join(paths[inc],"/",job->eval[0]);
		if(execve(temp,job->eval,envp) == -1) 
		{
			free(temp);
			temp = NULL;
		}
		if(temp)
			free(temp);
	}
	printf("command not found %s\n", job->eval[0]);
	freelist(g_state.exprt);
	freelist(g_state.env);
	free_list(lst);
	free_jobs(job,0);
	exit(127);
	return(0);
}

/* fork the process  before exectuion  and wait for the child */
int path_resolver(t_jobs *job,t_dlist *lst) 
{
	char **paths;
	int pid;
	int status;

	paths = ft_split(findpath(g_state.env),':');
	(void)job;
	pid = fork();
	if(pid < 0)
		return(-1);
	if(pid == 0)
	{
		exec_the_bin(paths, job, g_state.env,lst);
	}
	freelist(paths);
	waitpid(pid,&status,0);
	return(WEXITSTATUS(status));
}

