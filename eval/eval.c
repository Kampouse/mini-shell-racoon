#include "../minishell.h"
char	*find_in_env(char **envp,char *str)
{
	int		inc;

	char *temp;

	temp = NULL;
	inc = 0;

		while(envp[inc])
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
int until_this(char *str,char *this)
{
	int inc;

	inc = 0;
	while(str[inc])
	{
		if(ft_strchr(this,str[inc]))
			return(inc);
		inc++;
	}
return(-1);
}


char *find_dollsing(char *str)
{
	int len;
	char *temp;
len =	until_this(str + 1,"$");
	if(len < 0)	
	temp = ft_substr(str,0,ft_strlen(str));
	else
		temp = ft_substr(str,0,len + 1);
return(temp);
}


/* catch what inside of a  double quote and return what it  as  made and len */
char *find_var(char *str,int *len)
{
char *temp;
char *temp_b;

	temp = ft_substr(str,1, until_this(str + 2,"\"") + 1);
	if(until_this(temp,"$") == 0)
	{
		temp_b =find_dollsing(temp);
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
		return(temp);
	}
return(0);
}









char *eval_string(char *str,char *output)
{
int inc;
int len;
char *temp;

len = 0;
const   int quote = until_this(str,"\'\"");
inc = 0;
			if(*( str + quote) == '\"')
			{
				temp = find_var(str,&len);
				if(*(str + len) == '$')
					output = find_in_env(g_state.env,temp);
				else
					output = temp;

			}
			if(ft_strlen(str + len + 1) == 1)
				printf("red est NULL");

return(str);
}






void eval_cmds(t_jobs *job)
{
	int inc;
	char *outcome;

	outcome = NULL;
	inc = -1;
//	printf("(%s)",g_state.env[0]);
	if(job->cmd)	
	{
		while(job->cmd[++inc])
			eval_string(job->cmd[inc],outcome);
	}
}
void eval_redir(t_jobs *job)
{
	int inc;
	t_redir *temp;	
	char *temp_b;	

	temp = NULL;
	temp_b = NULL;
	inc = -1;
	if(job->redir)	
	{
		temp = job->redir;
		while(temp)
		{
				eval_string(job->redir->cmd,temp_b);
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








