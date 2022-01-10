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


char *make_executable(t_jobs *job,int *status)
{
const char **paths = (const char **)ft_split(findpath(g_state.env), ':');
int location;
char *temp;

location = 0;
temp = NULL;
    if(any_executable((char **)paths, job) == -1)
    {
        *status = 127;
        return(NULL);
    }
    location = any_executable((char **)paths,job);
    temp = ft_str3join(paths[location], "/", job->eval[0]);
    freelist((char **)paths);
return (temp);
}
/* fork the process  before exectuion  and wait for the child */
int path_resolver(t_jobs *job, t_dlist *lst,int pipes[],int state) 
{
	int pid;
	int status;
	char *temp;

    status = 0;
    temp = make_executable(job, &status);
	if(status == 127)
		return(127);
	pid = fork();
	if(pid < 0)
		return(-1);
	if(pid == 0)
	{
        pipe_handler(pipes,state);
        //handle pipe ?
		if(redir_handler(job) == -1)
			exit(1);
		exec_the_bin(temp, job,lst);
	}
	waitpid(pid,&status,0);
	free(temp);
	return(WEXITSTATUS(status));
}

