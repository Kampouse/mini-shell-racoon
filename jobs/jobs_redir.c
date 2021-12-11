#include "jobs.h"


int valid_redir(t_dlist *redir)
{
		if(redir->type >= 0 &&  redir->type <= 3)
	{
		if(redir->next && !(redir->next->type >=0 && redir->next->type <= 3))
				return(1);
	}
		if(!(redir->type >= 0 &&  redir->type <= 3))
				return(0);
	return (-1);
}

t_redir *redir_creator(t_dlist *redir, int len)
{
	t_dlist *temp;
	t_redir *redir_lst;

	redir_lst = NULL;
	temp = redir;
	len++;

	while (temp)
	{
		if(valid_redir(temp) == 1)		
			  redir_addback(&redir_lst,node_redir(temp->next->content,0));
		else if(valid_redir(temp) < 0)
		{
			printf("erro as occured\n");
				return(NULL);
		}
		if(temp->next)
			temp = temp->next;
		else 
			break;
	}
	return (redir_lst);
}

int  any_heredoc(char **lst)
{
	int count;

	count = 0;
	if(lst)
	{
		while(lst[count])	
		{
				if(atoi(lst[count]) == 1)
				  return (1);
			count += 2;
		}
	}
	return (0);
}

int redirector(char **redirs)
{
	int inc;


	inc = 0;
	while(redirs[inc])
	{
		if(ft_atoi(redirs[inc]) == 0)
	{
			printf("found: >> ");
	}
		if(ft_atoi(redirs[inc]) == 2)
		{
			printf("found: < ");
		}
		if(ft_atoi(redirs[inc]) == 3)
		{
			printf("found: > ");
	}
	inc+= 2;
		}
		if(ft_atoi(redirs[inc]) == 0)
		{
			printf("found: >> ");
			
		}
		inc+= 2;

return(0);
	}




