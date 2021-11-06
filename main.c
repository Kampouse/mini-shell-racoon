#include "stdio.h"
#include "readline/readline.h"
#include "libft/libft.h"
#include "minishell.h"
#include "readline/history.h"
#define GREEN "\002\e[0;32m\002"
#define RESET   "\001\e[0m\002"
extern char ** environ;
char **line_parser(char *line)
{
char **tokens;


	tokens  = ft_split(line,' ');

return(tokens);
}

int find_token(char *line, char *token) 
{
const int len = ft_strlen(line);

if(ft_strnstr(line,token,len))
	return(1);

return(0);
}
int exit_please(char **tokens,char *trimed)
{
	if(trimed && tokens)
	{
	if(find_token(tokens[0],"exit"))
	{
				printf("exit\n");
				free(trimed);
				freelist(tokens);
				return(1);
	}
	}
return(0);
}
 char	freelist(char **list )
{
	int index;
	index = 0;
	while (list[index])
	{
		free((void *) list[index]);
		index++;
	}
	free(list);
	return (0);
}


int read_wrapper(void)
{

char *line;
char *trimed;
char **tokens;

while(1)
	{
		line = readline(GREEN"minishell:>"RESET);
		trimed = ft_strtrim(line," ");
	    free(line);	
		if(trimed && ft_strlen(trimed) > 0)
		{
				tokens = line_parser(trimed);	
				if(exit_please(tokens,trimed) == 1)
					return (1);
			path_resolver(findpath(environ),tokens,environ);
		free(trimed);
		freelist(tokens);
		}
		else if(trimed)
			free(trimed);
}
return (0);
}



int main (void)
{
		if(read_wrapper() == 1)
			printf("delete squense");
}
