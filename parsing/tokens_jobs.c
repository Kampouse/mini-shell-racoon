#include "parsing.h"
#include <stdio.h>

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
	if(len > 0)
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
	if(!output && type == -2)
		output = until_separator(trimed + offset);
		//should return len type and string of  the token
	
	if(!output)
		return(NULL);
	printf("%s\n",output);
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

