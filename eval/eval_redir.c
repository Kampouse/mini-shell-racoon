#include "eval.h"
#include "../readline/readline.h"
#include <sys/types.h>


int skip_over(char *str)
{
int skiped;

skiped = 0;

	while(until_this(&str[skiped] ,"\'\"") == 0)	
			skiped++;
return(skiped);
}

char *quote_eval(char *str,int left,char *outcome,int type)
{
const char *duped = str;
const int skipped = skip_over((char*)duped  + left);

		if(skipped > 0)	
			outcome = lazy_join(outcome,ft_substr(duped,left,skipped));
	left += skipped;
			 outcome = lazy_join(outcome,eval_noquote((char*)duped,&left,0)); 
	if((unsigned int)left < ft_strlen(duped))
		return(quote_eval((char*)duped,left,outcome,type));
return(outcome);
}

int redir_poll(char *line,char *cmp)
{
 char *outcome;
 char *no_nl;
 int len;

 outcome = NULL;
	if(!line)
		return(1);
	outcome = eval_line(line,outcome,0,1);
	no_nl = ft_strtrim(outcome,"\n");
	len = (int)ft_strlen(no_nl) - ft_strlen(cmp);
	if(ft_strncmp(outcome,cmp,ft_strlen(no_nl))== 0 && len  == 0)
	{
		free(line);
		free(outcome);
		free(no_nl);
		return(0);
	}
	else 
	{
		free(outcome);
		free(no_nl);
		return(1);
	}
}


char *eval_docc(t_redir *temp,char *heredoc)
{
char *docc;
char *outcome;
char *line;

line = NULL;
outcome = NULL;
				if(heredoc)
					free(heredoc);
			if(temp->type == 1)		
			{
			    docc = eval_line(temp->cmd,outcome,0,1);
				while(redir_poll(line,docc))
				{
					if(line)
					{
						outcome  =	quote_eval(line,0,outcome,0);
						free(line);
					}
					line = lazy_join(readline(">>"),ft_strdup("\n"));
				}
				free(docc);
			}
return(outcome);
}

void eval_redir(t_jobs *job)
{
	t_redir *temp;	
	char *outcome;

	if(job->redir)
	{
		job->hereduc = NULL;
		temp = job->redir;
		while(temp)
		{
		outcome = eval_docc(temp,job->hereduc);
		if(outcome)			
			job->hereduc = outcome;
		else
			temp->eval = eval_line(temp->cmd,outcome,0,0);
				temp = temp->next;
		}
	}
}

