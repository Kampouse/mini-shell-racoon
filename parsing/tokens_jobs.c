#include "../minishell.h"

char *find_partner(char *str);
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


char *token_builder(char *str)
{
	int inc;
		inc = 0;
		char *created;
//find element until its not a space noar a quote 
//also  create a string  of that size try to join the quoted element that might be there 
//the same fonctionallity could be applied on the quoted side.....
if(!str)
	return(NULL);
while(!ft_strchr("\'\" \n\v\f\r",str[inc]))
	inc++;
if(inc == 0)
	return(NULL);
created = ft_substr(str,0,inc);
return created;
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
		else
		{
			//printf("unclosed %c",state);
			//this could leak mem if it return null :(
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
		if(until_space(&str[inc]) == 0)
			return NULL;
		first = ft_strchr("\'\"",str[inc]);
		if(first && first[0] == 39)
		{
			first = find_second(&str[inc + 1],39);
			break;
		}
		else if(first && first[0] == 34)
		{
			first =  find_second(&str[inc + 1],34);
			break;
		}
	}
	return (first);
}

/* join and free ?*/
char *line_handler(char *str,char *storage)
{
	char *quoted;
	  char *temp;
	 quoted  = token_builder(str);
	 if(quoted)
	 {
		temp = ft_strjoin(storage,quoted);
		if(storage)
			free(storage);
		//free quote ;
		storage = temp;
		if(ft_strlen(quoted) == ft_strlen(str))
			return storage;
		return line_handler(str + ft_strlen(quoted),storage);

	 }
	 else
	 {
		 quoted = find_partner(str);
		 if(quoted)
		 {
			temp = ft_strjoin(storage,quoted);
			if(storage)
				free(storage);
			storage = temp;
		if(ft_strlen(quoted) + 2 == ft_strlen(str))
			return storage;
		return line_handler(str + ft_strlen(quoted) + 2,storage);
		 }
	 }
	return  storage;
}


/* chop the string into token */
int line_parser(char *trimed,char **environ)
{
	char	**tokens;
	int		type;
	char *stuff;
	stuff  = NULL;
	type = -2;
	tokens  = ft_split(trimed,' ');
	type = token_scanner(trimed);
	//printf("%s\n",find_partner(trimed));
	printf("----%s\n",line_handler(trimed,stuff));
	//printf("%ld \n",ft_strlen(find_partner(trimed)));
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
