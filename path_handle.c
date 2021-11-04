#include "libft/libft.h"
#include "minishell.h"
#include <sys/stat.h>


int path_trigger(char *path,char **env )
{
int pid;
int status;

pid = fork();
	if(pid < 0)
		perror("FORK  ERROR");
	if(pid > 0)
	{
		printf(" execve failed ;( %d",execve(path,env,env));
		

	}
	waitpid(pid, &status, WEXITED);


return(0);
}
int path_resolver(char *path_bin,char *program , char **env) 
{
	char **paths;
	char *temp;
	int inc;
	int pid;
	int status;

	inc = -1;
	paths = ft_split(path_bin,':');
	pid = fork();
	if(pid < 0)
		return(-1);
	if(pid == 0)
	{

	
while(paths[++inc])
	{
	temp = ft_str3join(paths[inc],"/",program);
			if(execve(temp,NULL,env) == -1) 
			{
						free(temp);
						temp = NULL;			
			}
		if(temp)
			free(temp);
	}
	printf("command not found %s\n", program);
	exit(0);
	}
	if(pid > 0)
		waitpid(pid,&status,1);
freelist(paths);
return(1);
}
