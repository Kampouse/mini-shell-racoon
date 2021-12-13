
#include "libft/libft.h"
#include "minishell.h"
/* should clean all the data structures left
 on the  heap also return a status?*/
/*
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
*/
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
		return(-1);
	while(!ft_isspace(str[inc]) && str[inc])
	{
		inc++;

	}
	
return(inc);
}

char	freelist(char **list)
{
	int	index;

	index = 0;
	if(list)
	{
		while (list[index])
	{
		if(list[index])
			free((void *) list[index]);
		index++;
	}
	free(list);
	}
	return (0);
}
