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
	char *created;

	inc = 0;
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
	if (last)	
	{
		while (&str[inc + 1] != last)
			inc++;
		last = ft_substr(str, 0, inc + 2);
		*len += ft_strlen(last) -  3;
		return(last);
	}

		len = NULL;
return (last);
}

char *find_dquoted(char *str, size_t *len)
{
	char *last;
	 size_t inc;

	last = NULL;
	inc = 0;
	if(ft_strchr(str + 1, 34))
	{
		last = ft_strchr(str + 1,34);	
		if(last)
		{
				while(str[inc + 1] != *last)
					inc++;	
			*len += ft_strlen(last) - 3;
			return(ft_substr(str, 0, inc + 2));
		}
	}
return (0);
}

char *find_partner(char *str, size_t *len)
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
			first = find_single(&str[inc],len);
			break;
		}
		else if(first && first[0] == 34)
		{
			first = find_dquoted(&str[inc],len);
			break;
		}
	}
		if(!first)
			printf("missid a (%c) \n",str[inc]);
		len = NULL;
	return (first);
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

char  *line_handler(char *str, size_t *len)
{
	char *temp;

	temp = line_no_string(str, len);
	if (temp)	
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
	if (ft_strlen(str + offset ) == 0 || token_bool(str + offset, &len) == 0)
			break;
	}
	if (!len)
	{
		if (result)
			free(result);
		return (NULL);
	}
	return (result);	
}
/* return the lenght of what the token   (current implementation  fail when seperaro;*/
int is_quoted(char *str)
{
	int inc;
	int state;

	state = 0;
	inc = 0;
	while(str[inc])
	{
		if(str[inc] == '\''	|| str[inc] == '\"')
			 state = !state;
		if(state == 0 && ft_strchr("<>|\n\v\f\r ",str[inc]))
			return(inc);
		inc++;
	}
	return (inc);
}
/* there should be function  that deal with seperator separatly */
char *until_separator(char *str)
{
	int inc;
	char *created;
	size_t len;
	char *result;

	result = NULL;
	len  = 0;
	inc = 0;
	if(str)
	 inc = is_quoted(str);
	else
		return(NULL);
	created = ft_substr(str, 0, inc);
	result = token_loop(result, created, len, 0);
	free(created);
return (result);
}
char *separtor_token(char *str,int *type)
{
	size_t len;

	len = 0;
	 *type = token_scanner(str,&len);
	if(type >= 0)
		return(ft_substr(str, 0, len));
	return(0);
}
/* determine when it should stop going forward when is see a  space*/
int handle_space(char *trimed)
{
	int inc;

	inc = 0;
	if(!trimed)
		return(-1);
	while(trimed[inc])
	{
		if(!ft_isspace(trimed[inc]))
			break;
		inc++;
	}
return(inc);
}

char *token_nodes(char *trimed ,size_t total_len)
{
	char  *output;
	int type;
	size_t len;
	const int  offset =  handle_space(trimed);

	len = 0;
	type = -2;
	output = separtor_token(trimed + offset,&type);
	if(ft_strlen(output) == 0 && type == -2)
		output = until_separator(trimed + offset);
		//should return len type and string of  the token
	printf("%s\n",output);
	if(!output)
		return(NULL);
	len = ft_strlen(output);	
	if(len == 0 && type > 0)
		len++;
	total_len -= (len + offset);
	if(total_len == 0)
		return(NULL);
	else
		return(token_nodes(trimed + len + offset,total_len));
return (0);
}

int line_parser(char *trimed, char **environ)
{
	char	**tokens;
	char *stuff;
	//int		type;

	stuff = NULL;
	tokens  = ft_split(trimed,' ');
	//stuff = separtor_token(trimed,&type);
	//stuff = until_separator(trimed,stuff);

	//printf("%s\n",stuff);
	token_nodes(trimed,ft_strlen(trimed));
	free(stuff);
	/*if(type >= 0)
	{
		//token_valid(tokens,trimed,type);
		freelist(tokens);
		free(trimed);
	}
	*/
		//path_resolver(findpath(environ), tokens, environ);
		//printf("%s: is  not a good student\n",trimed);
		environ++;
		free(trimed);
		freelist(tokens);
	return(0);
}
/* some funny busness in this function when the type << or >> so maybe a strnstr be better */
int token_scanner(char *str,size_t *token_size)
{
	int inc;
	const char *trimed  = ft_substr(str,0,until_space(str));
	char *tokens[10] = { ">>", "<<","<", ">","|","env","export","exit","echo",NULL};
	inc = 0;
	if(!str)
		return(-1);
	while(tokens[inc])
	{
		 if(ft_strncmp(trimed,(char *)tokens[inc],ft_strlen(tokens[inc])) == 0)
		{
				free((char *) trimed);
				*token_size = ft_strlen(tokens[inc]);
			 return(inc);
		}
		 inc++;
	}
	*token_size = 0;
	free((char *) trimed);
	return(-2);
}
