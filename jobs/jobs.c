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


char **jobs_lst_creator(t_dlist *lst,char **redir,int count)
{
 char	**commands;
t_dlist	 *temp;
int		inc;

	temp  = NULL;
	if (redir)
		printf("%s",redir[0]);
	else
		temp = lst;
	inc = 0;
	commands = malloc(sizeof(char *) * count + 1);
	commands[count] = 0;
	while(count != 0)
	{
		commands[inc] = temp->content;
		temp = temp->next;
		inc++;
		count--; 
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
	printf("(%d)\n",redir_counter(lst));
	commands = jobs_lst_creator(lst,redir,counter);	

return (0);
}

