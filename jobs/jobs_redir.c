#include "jobs.h"


int valid_redir(t_dlist *redir)
{
		if(redir->type >= 0 &&  redir->type <= 3)
	{
			if(redir->next)	
			{
				if(!(redir->next->type >= 0 &&  redir->next->type <= 3))
					 return(1);
			}
			else
			{
				printf("expected something\n");
				return(-1);
			}
	}
	return (0);
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
			return(-1);
		else 
			counter+= tmp;
		temp = temp->next;
	}
	return(counter);
}

char **redir_creator(t_dlist *redir, int len)
{
	t_dlist *temp;
	char **redir_lst;
	int inc;

	inc = 0;
	temp = redir;
		if (len <= 0)
			return NULL;
		redir_lst = malloc(sizeof(char **) * (len * 2) + 1);
	while (temp && temp->type != 4)
	{
		if (temp->type >= 0 && temp->type <= 3)
		{
			redir_lst[inc] = ft_itoa(temp->type);		
			redir_lst[inc + 1] = temp->next->content;
			inc +=2;
		}
		temp = temp->next;
	}
	redir_lst[inc] = 0;
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

	
		if(ft_atoi(redirs[inc]) == 2)
	{
			printf("found: < ");
	}
		if(ft_atoi(redirs[inc]) == 3)
	{
			printf("found: > ");
	}
		if(ft_atoi(redirs[inc]) == 0)
	{
			printf("found: >> ");
	}
	inc+= 2;
	}
return(0);
}




