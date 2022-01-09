#include "../minishell.h"
t_jobs	*node_job(char **cmd)
{
	t_jobs	*link;

	link = (t_jobs *)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->prev = NULL;
	link->next = NULL;
	link->hereduc = NULL;
	link->redir = NULL;
	link->cmd = cmd;
	link->eval = NULL;
	link->cmd_type = -3;
	link->status = 0;
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

t_jobs	*job_new_lst(char **cmd,t_redir *redir,t_dlist *cmd_head)
{
	t_jobs	*link;

	if(!cmd && !redir)
		return(NULL);
	link = (t_jobs *)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->next = NULL;
	link->hereduc = NULL;
	link->status = 0;
	link->cmd = cmd;
	if(redir)
		link->redir = redir;
	else
			link->redir = NULL;
	if(cmd_head && cmd_head->type != 4)
		link->cmd_type = cmd_head->type;
	else
		link->cmd_type = -3;
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
				return(temp->next);
			temp = temp->next;	
		}
	}
	return(NULL);
}


void	free_jobs(t_jobs *head,int type)
{

	t_jobs	*next;
		next = NULL;
	if (head)
	{
		next = head->next;
		if(head->redir)
			free_redir(head->redir);
		if(head->eval&& head->eval[0] && type == 1)
		{
			free(head->eval);
		}
		else if(head->eval)
		{
			freelist(head->eval);
		}
		if(head->hereduc)
			free(head->hereduc);

		free(head);
		free_jobs(next, type);
	}
}
