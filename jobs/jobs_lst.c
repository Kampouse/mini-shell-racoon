#include "jobs.h"

/* count how many item there is in a 2d array excluding redir */
int jobs_lst_counter(t_dlist *lst)
{
	t_dlist *temp;
	int count;

	count = 0;
	temp = lst;
	while(temp)
	{
		if(temp->type > 4 || temp->type == -2)
			count++;
		temp = temp->next;
	}
	return(count);
}

/* function that create a lst of  args for exceve */
char **jobs_lst_creator(t_dlist *lst,t_dlist **lst_head)
{
	char	**commands;
	t_dlist	 *temp;
	int		inc;

	inc = 0;
	temp  = NULL;
	commands = NULL;
	if ((lst->type >= 0 &&  lst->type <= 3 && lst->next && lst->next->next))
		temp = lst->next->next;
	else
		temp = lst;
	if(temp->content &&  !(temp->type >= 0 && temp->type <= 3))
	{
		*lst_head = temp;
	 	commands  = ft_calloc( (size_t)jobs_lst_counter(temp) + 1,sizeof(char **));
		while(temp && (temp->type > 4  || temp->type == -2))
		{
			commands[inc++] = temp->content;
			temp = temp->next;
		}
	}
	return (commands);
}
