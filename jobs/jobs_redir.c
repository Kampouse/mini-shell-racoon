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

int redir_counter(t_dlist *redir)
{
	
	t_dlist *temp;
	int counter;
	int tmp;
	
	temp = redir;
	counter = 0;
	while(temp && temp->type != 4)
	{
		 tmp  = valid_redir(temp);
		if(tmp == -1)	
		{
			printf("syntax error near unexpected token `newline'\n");
			return(-1);
		}
		else 
			counter+= tmp;
		if(temp->next && temp->next->next)
			temp = temp->next->next;
		else
			break;
	}
	return(counter);
}

t_redir *redir_creator(t_dlist *redir, int len)
{
	t_dlist *temp;
	t_redir *redir_lst;

	redir_lst = NULL;
	temp = redir;
		printf("%d",len);	
		if (len <= 0)
			return (NULL);
	while (temp)
	{
		if(temp->next)
		{
		  redir_addback(&redir_lst,node_redir(temp->next->content,0));
			temp = temp->next->next;
		}
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




