#include "jobs.h"
t_dlist *ft_lst_nextnth(t_dlist *node,int nth)
{
	t_dlist *temp;
    temp = NULL;
	if(node)
	{
		temp = node;
		while(temp && nth > 0)
		{
			nth--;
			temp = temp->next;
		}
	}
	return (temp);
}

int jobs_lst_counter(t_dlist *lst)
{
	t_dlist *temp;
	int count;

	count = 0;
	temp = lst;
	while(temp && temp->type == -2)
	{
		count++;
		temp = temp->next;
	}
return(count);
}


char **jobs_lst_creator(t_dlist *lst,char **redir)
{
 char	**commands;
t_dlist	 *temp;
int		inc;

	temp  = NULL;
	if (redir &&  lst->type >= 0 &&  lst->type <= 3 && lst->next->next )
		temp = lst->next->next;
	else if(redir && !lst->next->next)
			return(NULL);
	else
		temp = lst;
	inc = 0;
	commands = malloc(sizeof(char *) * jobs_lst_counter(temp) + 1);
	while(temp && (temp->type > 4  || temp->type == -2))
	{
		commands[inc] = temp->content;
		temp = temp->next;
		inc++;
	}

	commands[inc] = 0;
	{
	int tested;

	tested = 0;

	while(commands[tested])
		{
		printf("%s\n",commands[tested]);
		tested++;
		}
	}
return (commands);
}


/*  function  that make a job (get a job) */


int print_tokens(t_dlist *lst)
{
	t_dlist *temp;
	temp = lst;
		while(temp)
	{
		printf("%s\n",temp->content);
		temp = temp->next;
	}
	return(0);
}




int jobs(t_dlist *lst) 
{
	char **redir;
	char **commands;
	int counter;
	t_dlist *temp;

	temp = NULL;
	temp = lst;
	counter = jobs_lst_counter(lst);
	if(redir_counter(lst) < 0)
	{
		printf("error -1 \n");
		return(-1);
	}
	redir = redir_creator(lst,redir_counter(lst));
	commands = jobs_lst_creator(lst,redir);	

return (0);
}

