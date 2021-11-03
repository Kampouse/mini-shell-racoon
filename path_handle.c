#include "libft/libft.h"
#include "minishell.h"
#include <sys/stat.h>


int is_exec(char *env,char *program) 
{
	char **paths;
	char *temp;
	struct  stat stats;

	int inc;

	inc = -1;
	paths = ft_split(env,':');
while(paths[++inc])
	{
	temp = ft_str3join(paths[inc],"/",program);
			if(stat(temp,&stats) &&  S_ISREG(stats.st_mode) == 1)
		{
			if(S_IEXEC)
			{
			printf("yes\n");
			free(temp);
			freelist(paths);
				return 0;
			}
		}
			free(temp);
	}
	printf("command not found %s\n", program);
freelist(paths);
return(1);
}
