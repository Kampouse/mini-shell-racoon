#include "../minishell.h"

char *line_handler(char *str,unsigned int *len);

char *find_partner(char *str,unsigned int *len);
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
char *find_single(char *str,unsigned int *len)
{
 char *last;
 int inc;

 inc  = 0;
		last   = ft_strchr(str,39);
		if(last)	
		{
			while(&str[inc] != last)
				inc++;
			last = ft_substr(str,0,inc);
			*len = ft_strlen(last) + 2;
			return(last);
		}
		len = NULL;
return(last);
}

char *find_dquoted(char *str,unsigned int *len)
{
	char *last;
	 unsigned int inc;

	last = NULL;
	inc = 0;
	if(ft_strchr(str,34))
	{
		last = ft_strchr(str,34);	
		if(last)
		{
				while(str[inc] != *last)
					inc++;	
			*len  += (inc  + 2);
			//this just a   filler;
			return(ft_substr(str,0,inc));
		}
	}
return(0);
}
char *find_partner(char *str,unsigned int *len)
{
	int inc;
	char *first;
	char *temp;

	temp = NULL;
	inc  = -1;
	while(str[++inc])
	{
		if(until_space(&str[inc]) == 0)
			return NULL;
		first = ft_strchr("\'\"",str[inc]);
		if(first && first[0] == 39)
		{
			temp = find_single(&str[inc + 1],len);
			break;
		}
		else if(first && first[0] == 34)
		{
			temp = 	find_dquoted(&str[inc + 1],len);
			break;
		}
	}
		if(!temp)
			printf("missid a (%c) \n",first[0]);
	return (temp);
}
/* join and free ?*/
char *line_no_string(char *str,unsigned int *len)
{
	char *quoted;

	 quoted  = token_builder(str);
	 if(quoted)
	 {
		 *len = ft_strlen(quoted);
		
	 }
		else 
			return(NULL);
	return(quoted);
}

char *line_handler(char *str,unsigned int *len )
{
	char *temp;

	temp = line_no_string(str,len);
	if(temp)	
	{
		*len = ft_strlen(temp);
		return(temp);
	}
	else
	{
		 temp = find_partner(str,len);	
		 if(temp)
		{
		*len = ft_strlen(temp) + 2;
			return(temp);
		}
	}
	*len = 0;
	return  0;
}


 int line_handler_bool(char *str,unsigned int *len)
{

	const char *temp = (const char *)line_handler(str,len);
		
	if(temp)
	{
		free((void *)temp);

		return(1);
	}

	return(0);

}

char *line_handler_util(char *folded,char *str,unsigned len,unsigned int tempon)
{
char *stuff;
char *temp;

	while(1)
	{
		stuff = line_handler(str + tempon,&len);
		if(!len)
		{
			if(folded)
				free(folded);
			return(NULL);
		}
			tempon += len;	
		if(len == 0)
			break;
		temp = ft_strjoin(folded,stuff);		
				free(stuff);	
	if(folded) 
		free(folded);
	folded = temp;	
	if(ft_strlen(str + tempon ) == 0 || line_handler_bool(str + tempon, &len) == 0)
			break;
	}
	return(folded);	
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
	stuff = line_handler_util(stuff,trimed,0,0);
	printf("%s\n",stuff);
		free(stuff);
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
