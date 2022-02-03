/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:30:42 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/02 23:21:19 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

/* count how many item there is in a 2d array excluding redir */
int	jobs_lst_counter(t_dlist *lst)
{
	t_dlist		*temp;
	int			count;

	count = 0;
	temp = lst;
	while (temp)
	{
		if (temp->type > 4 || temp->type == -2)
			count++;
		temp = temp->next;
	}
	return (count);
}

/* might breaks something */
void	ft_anything(t_dlist *temp, int inc, char**commands)
{
	if (temp && temp->next && temp->next->next)
	{
		if (temp->type == 4)
			return ;
		temp = temp->next->next;
		while (temp)
		{
			if(valid_redir(temp) == 1)
				temp = temp->next->next;
			else
			{
				commands[inc++] = temp->content;
				temp = temp->next;
			}
		}
	}
}

/* function that create a lst of  args for exceve */
char	**jobs_lst_creator(t_dlist *lst, t_dlist **lst_head)
{
	char		**commands;
	t_dlist		*temp;
	int			inc;

	inc = 0;
	temp = NULL;
	commands = NULL;
	temp = lst;
	while(valid_redir(temp) == 1)
		temp = temp->next->next;
	if (temp && temp->content && !(temp->type >= 0 && temp->type <= 3))
	{
		*lst_head = temp;
		commands = ft_calloc((size_t)jobs_lst_counter(temp) + 1,
				sizeof(char **));
		while (temp && (temp->type > 4 || temp->type == -2))
		{
			commands[inc++] = temp->content;
			temp = temp->next;
		}
		ft_anything(temp, inc, commands);
	}
	return (commands);
}
