#include "jobs.h"
t_jobs	*node_job(char **cmd,char **redir)
{
	t_jobs	*link;

	link = (t_jobs *)malloc(sizeof(*link));
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

t_jobs	*last_jobs(t_jobs *currlist)
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
void	jobs_addfront(t_jobs **currlist, t_jobs *newnode)
{
	if (currlist)
	{
		if (*currlist)
			newnode->next = *currlist;
		*currlist = newnode;
	}
}

void	jobs_addback(t_jobs **currlist, t_jobs *node)
{
	t_jobs	*last;

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

t_jobs	*job_new_lst(char **cmd,t_redir *redir)
{
	t_jobs	*link;


	if(!cmd && !redir)
		return(NULL);
	link = (t_jobs *)malloc(sizeof(*link));
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

void	free_jobs(t_dlist *head)
{
	t_dlist	*next;

	if(head && head->content)
		free(head->content);
	if (head != NULL)
	{
		next = head->next;
		free(head);
		free_jobs(next);
	}
}
