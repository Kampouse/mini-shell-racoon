#include "eval.h"
char	*find_env(char **envp,char *str)
{
	int		inc;
	char *temp;

	inc = -1;
	if(!str)
		return(NULL);
	if(ft_strlen(str) == 1 && str[0] == '$')
		return(str);
	while(envp[++inc] != 0)
	{
		if(ft_strncmp(envp[inc],str + 1,ft_strlen(str + 1)) == 0)
		{
			if(	*(envp[inc] + ft_strlen(str + 1)) == '=')	
			{
				temp =  ft_strdup(envp[inc] + ft_strlen(str + 1) + 1);
					free(str);
				return(temp);	
			}
		}
	}
	return(NULL);
}

char *lazy_join(char *first,char *second)
{
	char		*output;
	size_t		len;
	size_t		len2;

	if(!first && second)
	{
		output = ft_strdup(second);
		free(second);
		return(output);
	}
	if(!second)
		return(first);
	len = ft_strlen(first);
	len2 = ft_strlen(second);
	output = malloc(sizeof(char) * len + len2 + 1);
	if (output)
	{
		ft_memcpy(output, first, len);
		ft_memcpy(output + len, second, len2 + 1);
		free(first);
		free(second);
	}
	return (output);
}

int until_this(char *str,char *this)
{
	int inc;

	inc = -1;
	if(!str)
		return(-1);
	while(str[++inc])
	{
		if(ft_strchr(this,str[inc]))
		{
			return(inc);
		}
	}
return(-1);
}

/* catch what inside of a  double quote and return what it  as  made and len */
char *find_varutil(char *str,int **len,int until)
{

	if(until < 0 )
	{
		**len += until_this(str,"\"") + 1;
		return( ft_substr(str ,0,until_this(str,"\"")));
	}
	if( until > 0 )
	{
		**len += until_this(str + 1," $") + 1;
		return(ft_substr(str,0, until_this(str + 1," $") + 1)); 
	}

return(NULL);
}

char *find_var(char *str,int *len)
{
int until;
int **temp;

temp = &len;
		until = until_this(str,"$");
	if( until > 0  || until  < 0 )
		return(find_varutil(str,temp,until));
	if(until == 0 &&  until_this(str + 1,"$") != -1)
	{
		*len += until_this(str + 1,"$ ") + 1;
		return(ft_substr(str,0,until_this(str + 1,"$ ") + 1)); 
	}
	if(until == 0  &&  until_this(str + 1," $") != -1)
	{
		*len += until_this(str + 1," \"$") + 1;
		return(ft_substr(str,0,until_this(str + 1," \"$") + 1)); 
	}
	else
	{
		*len += until_this(str + 1," \'\"") + 1;
		return( ft_substr(str,0,until_this(str + 1," \'\"") + 1)); 
	}
return(0);
}
