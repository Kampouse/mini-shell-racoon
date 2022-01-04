#include "../minishell.h"

/* evaluate each job one after the  other */
int same_len(char *str ,char *str2)
{
	if(str && str2)
	{
		if(ft_strlen(str) == ft_strlen(str2))
			return(0);
		else
			return(1);
	}
	return(-1);
}

void parser_core(t_dlist *lst)
{
	t_jobs *job;
	t_jobs *temp;
	t_jobs *head;
	
	job = NULL;
	temp = NULL;
	job = job_lsting(lst);
	temp = job;
	head = job;
	pre_val_redir(job);
	while(temp)
	{
		eval(temp);
		temp = temp->next;
	}
	temp = job;
	while(temp)
	{
		start_job(temp,lst,head);
		temp = temp->next;
	}
	free_jobs(job,0);
}
/* start readline and tokenize the string */


void quick_parser(char *str)
{
	const char *trimed = ft_strtrim(str," ");
	t_dlist *lst;

	if(trimed && ft_strlen(trimed) > 0)
	{
		lst = line_parser((char *)trimed);
		free((char *)trimed);
		if(lst != NULL)
		{
			parser_core(lst);			
			free_nodes(lst);
		}
	}	
}

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
			free(trimed);
			if(lst != NULL)
			{
				parser_core(lst);			
				free_nodes(lst);
			}
		}
		else
			free(trimed);
	}
}
