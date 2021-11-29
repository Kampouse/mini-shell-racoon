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

/* create the list of token and wrap it into a linked list */
char *token_nodes(char *trimed ,size_t total_len,t_dlist **token_lst)
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
	if(!output)
		return(NULL);
	ft_lst_add_backd(token_lst,node_init(output, type));
	len = ft_strlen(output);	
	if(len == 0 && type > 0)
		len++;
	total_len -= (len + offset);
	if(total_len == 0)
		return(NULL);
	else
		return(token_nodes(trimed + len + offset,total_len,token_lst));
return (0);
}

int line_parser(char *trimed, char **environ)
{
	t_dlist *lst;

	lst  = NULL;
	token_nodes(trimed,ft_strlen(trimed),&lst);
	free(trimed);
	tokens_peek(lst);
	ft_lstdclear(&lst,free);
	//printf( "%s %d\n",lst->next->content ,lst->type);

	//free(stuff);
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
		//freelist(tokens);
	return(0);
}
/* some funny busness in this function when the type << or >> so maybe a strnstr be better */

