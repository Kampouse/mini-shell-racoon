#include "../minishell.h"

/* evaluate each job one after the  other */
void parser_core(t_dlist *lst)
{
	t_jobs *job;
	t_jobs *temp;
	
	job = NULL;
	temp = NULL;
	job = job_lsting(lst);
				temp = job;
			pre_val_redir(job);
			while(temp)
			{
				eval(temp);
				check_jobs(temp);
				temp = temp->next;
			}
			if(job)
				free_jobs(job,0);
}
/* start readline and tokenize the string */
void parsing(void)
{
	char *line;
	char *trimed;
	t_dlist *lst;

    lst = NULL;
	while(1)
	{
		line = readline(GREEN"minishell:>"RESET);
		trimed = ft_strtrim(line," ");
	    free(line);
		if(trimed && ft_strlen(trimed) > 0)
		{
			lst = line_parser(trimed);
			if(lst != NULL)
			{
				parser_core(lst);			
				free(trimed);
				free_nodes(lst);
			}
				
		else if (trimed)
			free(trimed);
		}
		else
			free(trimed);
	}
}
