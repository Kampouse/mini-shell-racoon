#include "../minishell.h"

char	*find_env(char **envp,char *str)
{
	int		inc;
	char *temp;

	inc = -1;
	if(!str)
		return(NULL);
	if(ft_strlen(str) == 1 && str[0] == '$')
	{
		return(str);
	}
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


char *find_dollsing(char *str)
{
	int len;
	int until;
	char *temp;
	
	temp = NULL;
	until = 0;
	if(!str)
		return(NULL);
	len =	until_this(str,"$");
	if(len == 0 )	
	{
		 until = until_this(str," $");
			if(until <= 0)
		{
				until = ft_strlen(str);
		}
		len = until;
		temp = ft_substr(str,0,len);
		return(temp);
	}
	else if(len > 0)
		return(ft_substr(str,1,until + 1));
	else
	{
		len = ft_strlen(str);
	if(str[0] == '\"')
		return(ft_substr(str + 1,0,len - 2));

	}
return(temp);
}


/* catch what inside of a  double quote and return what it  as  made and len */
char *find_var(char *str,int *len)
{
int until;

	if(str)
		until = until_this(str,"$");
	if(until < 0 )
	{
		*len += until_this(str,"\"") + 1;
		return( ft_substr(str ,0,until_this(str,"\"")));
	}
	if( until > 0 )
	{
		*len += until_this(str + 1," $") + 1;
		return(ft_substr(str,0, until_this(str + 1," $") + 1)); 
	}
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

char *find_varno(char *str,int *len)
{

int until;
char *temp;
until = 0;
if(str + *len  && ft_strlen(str + *len) != 0)
	{
		printf("(%d)--\n",(int)ft_strlen(str));
	}
	if(str[0] == '$')
	{
	if(until >= 0)
	{
		 temp = find_env(g_state.env, ft_substr(str,0,until + 1));
			*len += until + 1;
	}
	else
	{
		 temp = find_env(g_state.env, ft_substr(str ,0,ft_strlen(str)));
		*len += ft_strlen(str) + 1;
	}
	return(temp);
	}
	else
	{
	if(until == -1)		
	{
			temp = ft_strdup(str);
			*len += (int)ft_strlen(str);
	}
		else
		{
			 temp = ft_substr(str,0,until + 1);
				*len += until;
		}
	}
return(temp);
}

char *eval_noquote(char *str,int *append)
{
int len;
char *middle;

len = until_this(str + *append,"$\'\"");
if(len == 0)
	{
		if(until_this(str + *append + 1,"$\'\"") < 0 )
			len = ft_strlen(str  + *append);
		else if(len == 0 && ft_strlen(str + *append) == 1)
			len++;
		else
			len = until_this(str + *append + 1,"\'\"$") + 1; 
	}
	if(len > 0)
		 middle = ft_substr(str + *append,0,len);
	if(len < 0)
	{
		len = ft_strlen(str + *append);
		 middle = ft_substr(str + *append,0,len);
	}
	*append += len;
	if(middle[0] == '$') 
	 return(find_env(g_state.env,middle));
return(middle);
}

char *eval_dquote(char *str,char *output,int *append)
{
int len;
char *temp;

len = 0;
		if(until_this(str + *append,"\"") != -1)
		{
			temp = find_var(str + *append,&len);
			*append += len;
			if(temp && temp[0] == '$')
				output = lazy_join(output,find_env(g_state.env,temp));
			else
				output = lazy_join(output,temp);
			output = eval_dquote(str,output,append);					
		}
return(output);
}

char *eval_squote(char *str, int *append)
{
const   int quote = until_this(str + 1 , "\'");

	if(str && str[0] == '\'')
	{
		*append += (int)quote + 2;
		 return (ft_substr(str,1,quote));	
	}
return(0);
}


char *eval_line(char *str,char *output,int lon)
{
int len;
char *outcome;
char *temp;

outcome = NULL;
len = 0;
	if( str[lon] == '\"')
	{
		temp = ft_substr(str + lon,1,until_this(str + lon + 1,"\"") + 1);
		 output = lazy_join(output,eval_dquote(temp,outcome,&len));
		 lon+= until_this(str + lon + 1,"\"") + 2;
		 free(temp);
	}

	if(str && ft_strlen(str + lon) != 0 && str[lon] == '\'')
	{
		output = lazy_join(output, eval_squote(str + lon,&len));
		lon+=until_this(str + lon + 1,"\'") + 2;
	}
	if(str[lon] != '\'' && str[lon] != '\"' && ft_strlen(str + lon) > 0)
		output = lazy_join(output,eval_noquote(str,&lon));
	if(ft_strlen(str + lon) > 0)
		return(eval_line(str,output,lon));
return(output);
}





void eval_cmds(t_jobs *job)
{
	int inc;
	char *output;	

	output = NULL;
	inc = 0;
//	printf("(%s)",g_state.env[0]);
	if(job->cmd)	
	{
		//there will require a  of both quote and non quote ...
		//
		output = eval_line(job->cmd[inc],output,0);
		if(output)
		{
			printf("%s\n",output);
			free(output);
		}
	}
}
void eval_redir(t_jobs *job)
{
	t_redir *temp;	
	int len;
	char *temp_b;	
	len  = 0;
	temp = NULL;
	temp_b = NULL;
	if(job->redir)	{
		temp = job->redir;
		while(temp)
		{
				eval_dquote(job->redir->cmd,temp_b,&len);
				temp = temp->next;
		}
	}
}

int eval(t_jobs *jobs,t_exec *g_state)
{
	t_jobs *temp;

	(void)g_state;
	if(jobs)
	{
		temp = jobs;
		while(temp)
		{
		eval_cmds(temp);
		//	eval_redir(temp);
			temp = temp->next;
		}
	
	}
return(0);
}
