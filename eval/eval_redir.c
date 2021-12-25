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
const int skipped = skip_over(str + left);

		if(skipped > 0)	
			outcome = lazy_join(outcome,ft_substr(str,left,skipped + 1));
	left += skipped;
	 outcome = lazy_join(outcome,eval_noquote(str,&left,0)); 
	 printf("test %s\n",outcome);
	if(ft_strlen(str + left) > 0)
		return(quote_eval(str,left,outcome,type));
return(outcome);
}

void eval_redir(t_jobs *job)
{
	t_redir *temp;	
	char *temp_b;	
	char *outcome;

	temp = NULL;
	temp_b = NULL;
	outcome = NULL;

	if(job->redir)
	{
		temp = job->redir;
		while(temp)
		{
			if(temp->type == 1)		
			{
				temp_b = readline(">>");
				printf("%s\n",eval_line(temp->cmd,outcome,0,1));
			outcome  =	quote_eval(temp_b,0,outcome,0);
				printf("%s--",outcome);
			free(outcome);
				//expension of what inside of heredocc until it sees the separtor
			}
			else		
			{

				temp->cmd = eval_line(temp->cmd, temp_b,0,0);
			}
				temp = temp->next;
		}
	}
}
