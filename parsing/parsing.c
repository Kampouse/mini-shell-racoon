#include "../minishell.h"

/* main  entry point of minishell where jobs  
will be created(yet to be implemented) and  (executed WORKING)  */
void parsing(t_exec *g_state)
{
	char *line;
	char *trimed;
	t_dlist *lst;
	t_jobs *job;
	t_jobs *temp;

	job = NULL;
    lst = NULL;
	temp = NULL; 	
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
				job = job_lsting(lst);
				temp = job;
			while(temp)
			{
				eval(temp,g_state);
				check_jobs(temp);
				temp = temp->next;
			}
			if(job)
			{
				free_jobs(job);
				free_nodes(lst);
			}
				else
					free_nodes(lst);
			}
		}
		else if (trimed)
			free(trimed);
	}
}
