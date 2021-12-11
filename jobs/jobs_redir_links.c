#include "jobs.h"

t_redir	*node_redir(char *cmd,int type)
{
	t_redir	*link;

	link = (t_redir *)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->prev = NULL;
	link->next = NULL;
	link->cmd = cmd;
	link->type = type;
	// link->nb_dolla = check_cashtoken(link);
	// printf("nb  de dollar = %d\n", link->nb_dolla);
	return (link);
}

t_redir	*last_redir(t_redir *currlist)
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
void	redir_addback(t_redir **currlist, t_redir *node)
{
	t_redir	*last;

	if (currlist)
	{
		if (*currlist)
		{
			last = last_redir(*currlist);
			node->prev = last;
			last->next = node;
		}
		else
			*currlist = node;
	}
}

void	free_redir(t_redir *head)
{
	t_redir	*next;

	if(head && head->cmd)
		free(head->cmd);
	if (head != NULL)
	{
		next = head->next;
		free(head);
		free_redir(next);
	}
}
