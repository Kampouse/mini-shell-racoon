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

int pipe_counter(t_dlist *lst)
{
	t_dlist *tmp;
	int count;

	count = 0;
	tmp = lst;
	while(tmp)
	{
		if(tmp->type == 4)
		count += 2;
		tmp = tmp->next;
	}
	return(count);
}



void parser_core(t_dlist *lst)
{
	t_jobs *job = job_lsting(lst);
	t_jobs *temp;

	temp = NULL;	
	temp = (t_jobs*)job;
	if(job)
	{
		pre_val_redir((t_jobs*)job);
		while(temp)
		{
			eval(temp);
			temp = temp->next;
		}
		temp = (t_jobs *)job;
		while(temp)
		{
			start_job(temp,lst,job);
			temp = temp->next;
		}
		free_jobs((t_jobs *)job,0);
	}
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
