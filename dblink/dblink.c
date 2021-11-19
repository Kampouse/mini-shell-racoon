/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:43:39 by jemartel          #+#    #+#             */
/*   Updated: 2021/11/18 14:17:19 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"
t_dlist	*node_init(void *content)
{
	t_dlist	*link;

	link = (t_dlist *)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->content = content;
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
			last->next = node;
			node->prev = last;
		}
		else
			*currlist = node;
	}
}

void	ft_clearnode(t_dlist *currlist, void (*del)(void *))
{
	if (currlist)
	{
		(*del)(currlist->content);
		free(currlist);
	}
}

void	ft_cleart_dlist(t_dlist **currlist, void (*del)(void *))
{
	t_dlist	*iter;

	if (!del || !currlist || !*currlist)
		return ;
	  while (currlist && *currlist)
	{
		iter = (*currlist)->next;
		*currlist = iter;
		ft_clearnode(*currlist, del);
	}
}

