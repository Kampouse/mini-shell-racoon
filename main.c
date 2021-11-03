#include "stdio.h"
#include "readline/readline.h"
#include "libft/libft.h"
#include "minishell.h"
#include "readline/history.h"

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
int main (void)
{

char *line;
char *trimed;
char **tokens;
while(1)
	{
		line = readline("minishell:>");
		trimed = ft_strtrim(line," ");
	    free(line);	
		if(trimed && ft_strlen(trimed) > 0)
		{
				
				tokens = line_parser(trimed);	
				printf("%d",is_exec(findpath(environ),tokens[0]));
				if(find_token(trimed,"exit"))
			{
				free(trimed);
				freelist(tokens);
				return(0);
			}
		free(trimed);
		freelist(tokens);
		}
		else if(trimed)
			free(trimed);
}


	


}
