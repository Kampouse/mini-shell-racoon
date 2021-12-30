#include "../minishell.h"

char *eval_noquote(char *str, int *append, int type)
{
int len;
char *middle;

len = until_this(str + *append,"\n $\'\"");
if(len == 0)
	{
		if(until_this(str + *append + 1,"\n $\'\"") < 0 )
			len = ft_strlen(str + *append);
		else if(len == 0 && ft_strlen(str + *append) == 1)
			len++;
		else
			len = until_this(str + *append + 1, "\n \'\"$") + 1; 
	}
	if(len > 0)
		 middle = ft_substr(str + *append, 0, len);
	if(len < 0)
	{
		len = ft_strlen(str + *append);
		 middle = ft_substr(str + *append, 0, len);
	}
	*append += len;
	if(middle[0] == '$'&& type == 0 ) 
	 return(find_env(g_state.env, middle, type));
return(middle);
}

char *eval_dquote(char *str,char *output,int *append,int type)
{
int len;
char *temp;

len = 0;
		if(until_this(str + *append,"\"") != -1)
		{
			temp = find_var(str + *append,&len);
			*append += len;
			if(temp && temp[0] == '$' &&  type == 0)
				output = lazy_join(output,find_env(g_state.env,temp,type));
			else
				output = lazy_join(output,temp);
			output = eval_dquote(str,output,append,type);					
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


char *eval_line(char *str,char *output,int lon,int type)
{
int len;
char *outcome;
char *temp;

outcome = NULL;
len = 0;
	if( str[lon] == '\"')
	{
		temp = ft_substr(str + lon,1,until_this(str + lon + 1,"\"") + 1);
		 output = lazy_join(output,eval_dquote(temp,outcome,&len,type));
		 lon+= until_this(str + lon + 1,"\"") + 2;
		 free(temp);
	}
	if(str && ft_strlen(str + lon) != 0 && str[lon] == '\'')
	{
		output = lazy_join(output, eval_squote(str + lon,&len));
		lon+=until_this(str + lon + 1,"\'") + 2;
	}
	if(str[lon] != '\'' && str[lon] != '\"' && ft_strlen(str + lon) > 0)
		output = lazy_join(output,eval_noquote(str,&lon,type));
	if(ft_strlen(str + lon) > 0)
		return(eval_line(str,output,lon,type));
return(output);
}

int eval(t_jobs *jobs)
{
	t_jobs *temp;
	char **temp_b;
	
	if(jobs)
	{
		temp = jobs;
		{
			if(temp->cmd)
			{
				temp->hereduc = NULL;
			  temp_b = eval_cmds(temp);
			  printf("%d",temp->cmd_type);
			  temp->cmd  = temp_b;
			}
			if(temp->redir)
				eval_redir(temp);
			temp = temp->next;
		}
	}
return(0);
}
