#include "../libft/libft.h"
#include "../minishell.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>

	int any_executable(char **path,t_jobs *job)
{
	char *temp;
	int inc;
	struct stat sa; 

	temp = NULL;	
	inc = 0;
	while(path[inc])
	{
		temp = ft_str3join(path[inc],"/",job->eval[0]);
		if (stat(temp, &sa) == 0 && sa.st_mode & S_IXUSR)
			{
				free(temp);
				return(inc);
			}
		free(temp);
		inc++;
	}
	freelist(path);
	printf("command not found %s\n", job->eval[0]);
	return(-1);
}



/* last stage of execution of the command if not built in */
int exec_the_bin(char *paths,t_jobs *job,t_dlist *lst)
{

	free_list(lst);
	freelist(g_state.exprt);
	if(execve(paths,job->eval,g_state.env) == -1) 
        free_jobs(job,0);
	free(paths);
	freelist(g_state.env);
	exit(127);
	return(0);
}

/* fork the process  before exectuion  and wait for the child */
int path_resolver(t_jobs *job,t_dlist *lst) 
{
	char **paths;
	int pid;
	int status;
	char *temp;

	paths = ft_split(findpath(g_state.env),':');
	if(any_executable(paths,job) == -1)
		return(127);
	else
	{
		temp = ft_str3join(paths[any_executable(paths,job)], "/", job->eval[0]);
		freelist(paths);
	}
	pid = fork();
	if(pid < 0)
		return(-1);
	if(pid == 0)
	{
		if(redir_handler(job) == -1)
		{
			exit(-1);
		}
		exec_the_bin(temp, job,lst);
	}
	waitpid(pid,&status,0);
	free(temp);
	return(WEXITSTATUS(status));
}

