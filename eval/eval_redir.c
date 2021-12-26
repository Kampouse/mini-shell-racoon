#include "eval.h"
#include "../readline/readline.h"




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

 outcome = NULL;
	if(!line)
		return(1);
outcome =eval_line(line,outcome,0,1);
	if(ft_strncmp(outcome,cmp,ft_strlen(cmp))== 0)
	{
		//if(line)
		free(line);
		free(outcome);
		return(0);
	}
	else 
	{
		//free(line);
		free(outcome);
		return(1);
	}
}






void eval_redir(t_jobs *job)
{
	t_redir *temp;	
	char *line;	
	char *outcome;
	char *docc;

	temp = NULL;
	line = NULL;
	outcome = NULL;

	if(job->redir)
	{
		temp = job->redir;
		while(temp)
		{
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
				printf("%s--",outcome);
				free(outcome);
				line = NULL;
				outcome = NULL;
				//expension of what inside of heredocc until it sees the separtor
			}
			else		
			{

				temp->cmd = eval_line(temp->cmd, line,0,0);
			}
				temp = temp->next;
		}
	}
}
