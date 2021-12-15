#include "../minishell.h"

/* main  entry point of minishell where jobs  
will be created(yet to be implemented) and  (executed WORKING)  */
void parsing()
{
	char *line;
	char *trimed;
	t_dlist *lst;
	t_jobs *job;

	job = NULL;
    lst = NULL;
	while(1)
	{
		line = readline(GREEN"minishell:>"RESET);
		trimed = ft_strtrim(line," ");
	    free(line);
	
		if(trimed && ft_strlen(trimed) > 0)
		{
			lst = line_parser(trimed); 	
			job = job_lsting(lst);
			if(job && job->cmd)
				check_jobs(job);
			//eval(job);			
				ft_lstdclear(&lst,free);
			free_jobs(job);
		}
		else if (trimed)
			free(trimed);
	}
}

//void add_at
//void delete_at