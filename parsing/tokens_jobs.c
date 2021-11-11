#include "../minishell.h"

int token_valid(char **tokens,char *trimed,int type)
{

	if(type == 7)
	{
		exit_please(tokens,trimed);
		exit(0);
	}
	if(type  == 4)
		ft_putstr_fd(trimed,1);
	

return(0);
}
int line_parser(char *trimed,char **environ)
{
	char	**tokens;
	int		type;
	
	type = -2;
	tokens  = ft_split(trimed,' ');
				type = token_scanner(trimed);
			if(type >= 0 )
			{
				token_valid(tokens,trimed,type);
				freelist(tokens);
				free(trimed);
			}
			else
			{
				path_resolver(findpath(environ), tokens, environ);
				free(trimed);
				freelist(tokens);
			}
	return(type);
}

int token_scanner(char *str)
{
	int inc;
	const char *trimed  = ft_substr(str,0,until_space(str));

	char *tokens[9] = { ">", ">>","<", "<<","echo","env","export","exit",NULL};
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
