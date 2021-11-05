#include "libft/libft.h"
#include "minishell.h"
#include <stdio.h>
#include <sys/stat.h>



int exec_the_bin(char **paths,char **program, char **env)
{
	int inc;
	char *temp;

	inc = -1;

	while(paths[++inc])
	{
	temp = ft_str3join(paths[inc],"/",program[0]);
			if(execve(temp,program,env) == -1) 
				
			{
						free(temp);
						temp = NULL;			
			}
		if(temp)
			free(temp);
	}
	printf("command not found %s\n", program[0]);
	exit(0);


return(0);
}

int path_resolver(char *path_bin,char **program_args , char **env) 
{
	char **paths;
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
		exec_the_bin(paths,program_args,env);
		printf("\n");
	}
		waitpid(pid,&status,0);
freelist(paths);
return(1);
}

