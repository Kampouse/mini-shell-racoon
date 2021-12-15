#include "eval.h"
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






char *find_var(char *str,int *len)
{
int inc;	
int unt_doll;	
char *temp;
char *temp_b;
		//return the len of the string evaluated in  "?;
	inc =	until_this(str + 2,"\"");
	temp = ft_substr(str,1,inc + 1);
	unt_doll = until_this(temp,"$");
	if(unt_doll == 0)
	{
		*len = ft_strlen(temp);
		temp_b =find_dollsing(temp);
		free(temp);
		return(temp_b);
	}
	else if(unt_doll > 0) 
	{
		*len = unt_doll;
		temp_b = ft_substr(temp,0,unt_doll);
		free(temp);
		return(temp_b);	
	}
	else
		return(temp);
return(0);
}











char *eval_string(char *str)
{
int inc;
int len;

len = 0;
const   int quote = until_this(str,"\'\"");
inc = 0;
			if(*( str + quote) == '\"')
			{
				printf("%s\n",find_var(str + quote,&len));
			}

return(str);
}
void eval_cmds(t_jobs *job)
{
	int inc;
	inc = -1;
	if(job->cmd)	
	{
		while(job->cmd[++inc])
			eval_string(job->cmd[inc]);
	}
}
void eval_redir(t_jobs *job)
{
	int inc;
	t_redir *temp;	

	temp = NULL;
	inc = -1;
	if(job->redir)	
	{
		temp = job->redir;
		while(temp)
		{
				eval_string(job->redir->cmd);
				temp = temp->next;
		}
	}
}

int eval(t_jobs *jobs)
{
	t_jobs *temp;

	if(jobs)
	{
		temp = jobs;
		while(temp)
		{
			eval_cmds(temp);
			eval_redir(temp);
			temp = temp->next;
		}
	
	}
return(0);
}








