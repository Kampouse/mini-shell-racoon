
#include "libft/libft.h"
#include "minishell.h"
/* should clean all the data structures left
 on the  heap also return a status?*/

int	exit_please(char **tokens, char *trimed)
{
	if (trimed && tokens)
	{
		if (find_token(tokens[0], "exit"))
		{
			printf("exit\n");
			free(trimed);
			freelist(tokens);
			return (1);
		}
	}
	return (0);
}

int ft_isspace(char elm)
{
if(!elm)
	return(0);
if(elm == ' ' || elm == '\t' )
	return(1);
else if(elm == '\n' || elm == '\v' || elm == '\v' || elm == '\f' || elm == '\r')
	return(1);
return(0);
}

int until_space(char *str)
{
	int inc;
	inc = 0;
	if(!str)
		return(0);
	while(!ft_isspace(str[inc]) && str[inc])
	{
		inc++;

	}
	
return(inc);
}

int is_reddir(char *str)
{
	int inc;
	const char *trimed  = ft_substr(str,0,until_space(str));

	char *tokens[8] = { ">", ">>","<", "<<","echo","env","export",NULL};
	inc = 0;
	if(!str)
		return(-1);
	while(tokens[inc])
	{
			 if(ft_strncmp(trimed,(char *)tokens[inc],ft_strlen(str)) == 0)
		{
				free((char *) trimed);
			 return(inc);
		}
		 inc++;
	}
	free((char *) trimed);
	return(-2);
}

char	freelist(char **list)
{
	int	index;

	index = 0;
	while (list[index])
	{
		free((void *) list[index]);
		index++;
	}
	free(list);
	return (0);
}
