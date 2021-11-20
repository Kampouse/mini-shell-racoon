#include "../minishell.h"
#include <stdio.h>
char *line_handler(char *str,size_t *len);

char *find_partner(char *str,size_t *len);
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
char *find_single(char *str,size_t *len)
{
 char *last;
 int inc;

 inc  = 0;
		last   = ft_strchr(str + 1,39);
		if(last)	
		{
			while(&str[inc + 1] != last)
				inc++;
			last = ft_substr(str,0,inc + 2);
			*len += ft_strlen(last) -  3;
			return(last);
		}
		len = NULL;
return(last);
}

char *find_dquoted(char *str,size_t *len)
{
	char *last;
	 size_t inc;

	last = NULL;
	inc = 0;
	if(ft_strchr(str + 1,34))
	{
		last = ft_strchr(str + 1,34);	
		if(last)
		{
				while(str[inc + 1] != *last)
					inc++;	
			*len += ft_strlen(last) - 3;
			return(ft_substr(str,0,inc + 2));
		}
	}
return(0);
}

char *find_partner(char *str,size_t *len)
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
			temp = find_single(&str[inc],len);
			break;
		}
		else if(first && first[0] == 34)
		{
			temp = 	find_dquoted(&str[inc],len);
			break;
		}
	}
		if(!temp)
			printf("missid a (%c) \n",first[0]);
		len = NULL;
	return (temp);
}




/* join and free ?*/
char *line_no_string(char *str,size_t *len)
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

char  *line_handler(char *str,size_t *len )
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
		*len = ft_strlen(temp);
			return(temp);
		}
	}
	*len = 0;
	return  0;
}


 int token_bool(char *str, size_t *len)
{

	const char *temp = (const char *)line_handler(str,len);
		
	if(temp)
	{
		free((void *)temp);

		return(1);
	}
	if(!len)
		printf("broked");

	return(0);

}
/* loop that create token until it find space or string end 
* currently	this implentation does not look 
*
* */
char *token_loop(char *result, char *str, size_t len, size_t offset)
{
char *sub_token;
char *temp;

	while(1)
	{
		sub_token = line_handler(str + offset, &len);

		offset += len;	
		if(len == 0)
			break;
		temp = ft_strjoin(result, sub_token);		
				free(sub_token);	
	if (result) 
		free(result);
	result = temp;	
		if(ft_strlen(str + offset ) == 0 || token_bool(str + offset, &len) == 0)
			break;
	}
		if(!len)
		{
			if(result)
				free(result);
			return(NULL);
		}
	return (result);	
}
/* function that currently set the pace in where the loop stop going 
 *  that create the token until it find space or a delimter...;
*	currently <>| inside a token break it :(
*
* */
char *until_separator(char *str)
{

	int inc;
		char *created;
		char *result;
	result = NULL;
	inc = 0;
	if(!str)
		return(NULL);
	while(!ft_strchr("<>|",str[inc]))
	{
		inc++;
	}
	until_space(str);
	if(inc == 0 || until_space(str) < inc)
		return(NULL);
	created = ft_strchr("<>|",str[inc]);
	printf("%d",token_scanner(created));
	created = ft_substr(str,0,inc);
	result = token_loop(result,created,0,0);
	free(created);
	return result;

return(0);
}

/* chop the string into token */
int line_parser(char *trimed,char **environ)
{
	char	**tokens;
	char *stuff;
	int		type;
	type = -2;
	
	tokens  = ft_split(trimed,' ');
	type = token_scanner(trimed);
	//  stuff = token_loop(stuff,trimed,0,0);
			stuff = until_separator(trimed);
			printf("%s",stuff);
			free(stuff);
		//ft_lstdclear(&lst,free);
			if(type >= 0)
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
