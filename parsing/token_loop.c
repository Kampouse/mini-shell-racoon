#include "parsing.h"
#include "../minishell.h"

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