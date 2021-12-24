#include "eval.h"
#include "../readline/readline.h"

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
			if(temp->type == 1)		
			{
				temp->cmd = eval_line(temp->cmd,temp_b,0,1);
				temp_b = readline("hereduck");
				//expension of what inside of heredocc until it sees the separtor
			}
			else		
				temp->cmd = eval_line(temp->cmd, temp_b,0,0);
			//printf("%s %d\n",temp->cmd,temp->type);
				temp = temp->next;
		}
	}
}
