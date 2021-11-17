#include "../minishell.h"



//len
int string_noquote_type(char *str)
{
	int inc;
		inc = 0;
		char *created;
//find element until its not a space noar a quote 
//also  create a string  of that size try to join the quoted element that might be there 
//the same fonctionallity could be applied on the quoted side.....
	if(!str)
		return(-1);
	while(!ft_strchr("\'\" \n\v\f\r",str[inc]))
		inc++;
	if(inc == 0)
	return(-1);
		created = ft_substr(str,0,inc);
	if (ft_strchr(created,'$'))
	{
			free(created);
			return(0);
	}
	else
	{
		free(created);
		return(1);
	}
return -1;
}

/* len  */
int type_string(char *str,size_t *len)
{
 int  inc;
 char *first;
 char *temp;

	inc  = -1;
	while(str[++inc])
	{
		if(until_space(&str[inc]) == 0)
			return -1;
		first = ft_strchr("\"",str[inc]);
		if(first)
		{
			temp = 	find_dquoted(&str[inc + 1],len);
			if(temp && ft_strchr(temp,'$'))
					return(1);
			else if(temp)
			{
				free(temp);
				return(0);
			}
			else
				return(-1);
		}
	}
return(-2);
}
