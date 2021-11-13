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


char *find_second(char *str, int state)
{
 char *last;
 int inc;
 inc  = 0;
		last   = ft_strchr(str,state);
		if(last)	
		{
			while(&str[inc] != last)
				inc++;
			//this malloc the string....
			last = ft_substr(str,0,inc);
		//printf("\n output:%s \n",last);
		}
		//printf("(%s)",str);
return(last);
}

char *find_partner(char *str)
{
	int inc;
	char *first;

	inc  = -1;
	while(str[++inc])
	{
		first = ft_strchr("\'\"",str[inc]);
		if(first && first[0] == 39)
			return find_second(&str[inc + 1],39);
		else if(first && first[0] == 34)
			return find_second(&str[inc + 1],34);
	}
	return (0);
}




/* chop the string into token */
int line_parser(char *trimed,char **environ)
{
	char	**tokens;
	int		type;
	
	type = -2;
	tokens  = ft_split(trimed,' ');
	type = token_scanner(trimed);
	printf("%s \n",find_partner(trimed));
			if(type >= 0 )
			{
				token_valid(tokens,trimed,type);
				freelist(tokens);
				free(trimed);
			}
			else
			{
				//path_resolver(findpath(environ), tokens, environ);
				//printf("%s: is  not a good student\n",trimed);
				environ++;
				free(trimed);
				freelist(tokens);
			}
	return(type);
}

int token_scanner(char *str)
{
	int inc;
	const char *trimed  = ft_substr(str,0,until_space(str));
	char *tokens[10] = { ">", ">>","<", "<<","echo","env","export","exit","|",NULL};
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
