#include "jobs.h"


int valid_redir( t_dlist *redir)
{
	if(redir->type >= 0 &&  redir->type <= 3)
	{
		if(redir->next && !(redir->next->type >=0 && redir->next->type <= 4))
			return(1);
	}
	if(!(redir->type >= 0 &&  redir->type <= 3))
		return(0);
	return (-1);
}

t_redir *redir_creator(t_dlist *redir, int *status)
{
	t_dlist *temp;
	t_redir *redir_lst;

	redir_lst = NULL;
	temp = redir;
	while (temp)
	{
		if(valid_redir(temp) == 1)		
			  redir_addback(&redir_lst,node_redir(temp->next->content,temp->type));
		else if(valid_redir(temp) < 0)
		{
			*status = -1;
			printf("error as newLine\n");
			free_redir(redir_lst);
			return(NULL);
		}
		if(temp->next && temp->next->type != 4)
			temp = temp->next;
		else 
			break;
	}
	return (redir_lst);
}
