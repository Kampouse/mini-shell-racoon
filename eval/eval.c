#include "../minishell.h"

char	*find_in_env(char **envp,char *str)
{
	int		inc;
	char *temp;

	inc = 0;
	temp = NULL;
	if(ft_strlen(str) == 1 && str[0] == '$')
	{
		return(str);
	}
		while(envp[inc] != 0)
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
		inc++;
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
	
	until = 0;
	if(!str)
		return(NULL);
	len =	until_this(str,"$");
	if(len == 0 )	
	{
		 until = until_this(str," ");
			if(until < 0)
				until = ft_strlen(str);
		len += until;
		temp = ft_substr(str,0,len);
	}
	else if(len > 0)
		temp = ft_substr(str,0,until);
	else
	{
		len = ft_strlen(str);
		temp = ft_substr(str,0,len);
	}
return(temp);
}


/* catch what inside of a  double quote and return what it  as  made and len */
char *find_var(char *str,int *len)
{
char *temp;
char *temp_b;
	temp = ft_substr(str,1, until_this(str + 2,"\"$") + 1);
	if(until_this(temp,"$") == 0)
	{
		temp_b = find_dollsing(temp);
		*len = ft_strlen(temp_b);
		free(temp);
		return(temp_b);
	}
	else if(until_this(temp,"$") > 0) 
	{
		*len = until_this(temp,"$");
		temp_b = ft_substr(temp,0, until_this(temp,"$"));
		free(temp);
		return(temp_b);	
	}
	else
	{
		*len = ft_strlen(temp);
		//printf("%d\n",*len);
		return(temp);
	}
return(0);
}

char *eval_string(char *str,char *output,int append)
{
int len;
char *temp;
const   int quote = until_this(str,"\"");

len = 0;
			if(quote >= 0 && *( str + quote) == '\"')
			{
				temp = find_var(str,&len);
				if( (str[0] == '\"' && str[1] == '$') || str[1] == '$')
					output = lazy_join(output,find_in_env(g_state.env,temp));
				else
					output = lazy_join(output,temp);
			}
			if(quote != -1 && str + len && !(*(str + len + 1) == '\"'))
				output = eval_string(str + len ,output,append);					
return(output);
}






void eval_cmds(t_jobs *job)
{
	int inc;
	char *outcome;

	outcome = NULL;
	inc = 0;
//	printf("(%s)",g_state.env[0]);
	if(job->cmd)	
	{
		//there will require a  of both quote and non quote ...
		outcome = 	eval_string(job->cmd[inc],outcome,0);
		if(outcome)
			printf("%s\n",outcome);
	}
}
void eval_redir(t_jobs *job)
{
	t_redir *temp;	
	char *temp_b;	

	temp = NULL;
	temp_b = NULL;
	if(job->redir)	{
		temp = job->redir;
		while(temp)
		{
				eval_string(job->redir->cmd,temp_b,0);
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
