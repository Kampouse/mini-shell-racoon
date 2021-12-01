#include "jobs.h"


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


char **jobs_lst_creator(t_dlist *lst,int count)
{
 char **commands;
t_dlist *temp;
int inc;

inc = 0;
	temp =  lst;
  commands = malloc(sizeof(char *) * count + 1);
  commands[count] = 0;
	while(count != 0)
	{
		commands[inc] = temp->content;
		temp = temp->next;
		inc++;
		count--; 
	}
return(commands);
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

	counter = 0;
	redir = redir_creator(lst,redir_counter(lst));
		if(redir && lst->type >= 0 && lst->type <= 3)
		commands = jobs_lst_creator(lst->next->next,jobs_lst_counter(lst->next->next));
		else
			commands = jobs_lst_creator(lst,jobs_lst_counter(lst));
	if(commands)
	{
		while(commands[counter])
		{
			printf("%s\n",commands[counter]);
			counter++;
		}
		printf("-->\n");
		print_tokens(lst);
		printf("<--\n");
	}
	return (0);
}

