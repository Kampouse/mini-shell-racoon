#include "../minishell.h"

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
	//bad stuff here
		if(!first)
	{
			printf("missid a (%c) \n",str[inc]);
		len = NULL;
		first = NULL;
		return(NULL);
	}
		len = NULL;
	return (first);
}
