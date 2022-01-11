#include "../libft/libft.h"
#include "../minishell.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>

char * local_exec(t_jobs *job );

int any_executable(char **path, t_jobs *job)
{
	char *temp;
	int inc;
	struct stat sa; 

	inc = 0;
	while(path[inc])
	{
		temp = ft_str3join(path[inc], "/", job->eval[0]);
		if (stat(temp, &sa) == 0 && sa.st_mode & S_IXUSR)
			{
				free(temp);
				return(inc);
			}
        free(temp);
		inc++;
	}
	freelist(path);
	return(-1);
}

/* last stage of execution of the command if not built in */
int exec_the_bin(char *paths, t_jobs *job, t_dlist *lst)
{
	free_list(lst);
	freelist(g_state.exprt);
	execve(paths,job->eval, g_state.env);
    free_jobs(job, 0);
	free(paths);
	freelist(g_state.env);
	exit(127);
	return(0);
}

void command_not_found(t_jobs *job)
{
    ft_putstr_fd("command not found:",2);
    ft_putstr_fd(job->eval[0],2);
    ft_putstr_fd("\n", 2);
}

char *make_executable(t_jobs *job)
{
const char **paths = (const char **)ft_split(findpath(g_state.env), ':');
int location;
char *temp;

    location = 0;
    if(any_executable((char **)paths, job) == -1)
        return(local_exec(job));
    location = any_executable((char **)paths,job);
    temp = ft_str3join(paths[location], "/", job->eval[0]);
    if(strncmp(job->eval[0], "./", 2) == 0)
    {
        freelist((char **)paths);
        command_not_found(job);
        free(temp); 
        return(NULL);
    }
    freelist((char **)paths);
return (temp);
}

char * local_exec(t_jobs *job)
{
    char cwd[1024];
    char *temp;
    struct stat sa; 

getcwd(cwd,1024);
if(ft_strncmp(job->eval[0],"./", 2) == 0)    
    {
        temp = job->eval[0];
        temp = ft_str3join(cwd, "/", temp);
        if (stat(temp, &sa) == 0 && sa.st_mode & S_IXUSR)
            return(temp);
        free(temp);
    }
    command_not_found(job);
    return(NULL);
}

int is_folder(t_jobs *jobs, char *local)
{
    struct stat stats;
    if(local)
    {
        stat(local, &stats);
        if(S_ISREG(stats.st_mode) == 0) 
        {
            ft_putstr_fd("IS a directory: ", 2);
            ft_putstr_fd(jobs->eval[0], 2);
            ft_putstr_fd("\n", 2);
            free(local);
            return(1);
        }
    }
    return(0);
}

/* fork the process  before exectuion  and wait for the child */
int path_resolver(t_jobs *job, t_dlist *lst, int pipes[], int state) 
{
	int pid;
	int status;
    const char *local = make_executable(job);

	if(!local || is_folder(job, (char *)local))
		return(127);
	pid = fork();
	if(pid < 0)
		return(-1);
	if(pid == 0)
	{
        pipe_handler(pipes, state);
        //handle pipe ?
		if(redir_handler(job) == -1)
			exit(1);
		exec_the_bin((char *)local, job, lst);
	}
	waitpid(pid,&status,0);
	free((char *)local);
	return(WEXITSTATUS(status));
}

