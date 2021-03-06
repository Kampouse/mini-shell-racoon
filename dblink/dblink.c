/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:43:39 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/02 11:41:52 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parsing/parsing.h"

t_dlist	*node_init(void *content, int type)
{
	t_dlist	*link;

	link = (t_dlist *)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->content = content;
	link->len = ft_strlen((char *)content);
	link->type = type;
	link->prev = NULL;
	link->next = NULL;
	return (link);
}

void	ft_add_frontd(t_dlist **currlist, t_dlist *newnode)
{
	if (currlist)
	{
		if (*currlist)
			newnode->next = *currlist;
		*currlist = newnode;
	}
}

void	ft_lst_add_backd(t_dlist **currlist, t_dlist *node)
{
	t_dlist	*last;

	if (currlist)
	{
		if (*currlist)
		{
			last = ft_lst_lastnode(*currlist);
			node->prev = last;
			last->next = node;
		}
		else
			*currlist = node;
	}
}

void	free_nodes(t_dlist *head)
{
	t_dlist	*next;

	if (head)
	{
		next = head;
		while (next->prev)
			next = next->prev;
		free_list(next);
	}
}
