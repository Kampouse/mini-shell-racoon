#include "jobs.h"
s_jobs	*node_job(char **cmd,char **redir)
{
	s_jobs	*link;

	link = (s_jobs *)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->prev = NULL;
	link->next = NULL;
	link->cmd = cmd;
	link->cmd = redir;
	// link->nb_dolla = check_cashtoken(link);
	// printf("nb  de dollar = %d\n", link->nb_dolla);
	return (link);
}

s_jobs	*last_jobs(s_jobs *currlist)
{
	if( currlist && currlist->next)
	{

		while (currlist->next)
		{
			if (!currlist->next)
				return (currlist);
			currlist = currlist->next;
		}
	}
	return (currlist);
}
void	jobs_addfront(s_jobs **currlist, s_jobs *newnode)
{
	if (currlist)
	{
		if (*currlist)
			newnode->next = *currlist;
		*currlist = newnode;
	}
}

void	jobs_addback(s_jobs **currlist, s_jobs *node)
{
	s_jobs	*last;

	if (currlist)
	{
		if (*currlist)
		{
			last = last_jobs(*currlist);
			node->prev = last;
			last->next = node;
		}
		else
			*currlist = node;
	}
}

s_jobs	*job_new_lst(char **cmd,char **redir)
{
	s_jobs	*link;

	link = (s_jobs *)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->next = NULL;
	link->cmd = cmd;
	link->redir = redir;
	return (link);
}
t_dlist	*job_find_pipe(t_dlist *lst)
{
	t_dlist *temp;
if(lst)
	{
		temp = lst;
		while(temp)
		{

			if(temp->type == 4)
			{
				return(temp->next);
			}
			temp = temp->next;	
		}
	}
return(NULL);
}
