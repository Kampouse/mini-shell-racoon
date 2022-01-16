/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblink_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:46:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/16 01:05:40 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_dlist	*ft_lst_lastnode(t_dlist *currlist)
{
	if (currlist && currlist->next)
	{
		while (currlist->next)
		{
			if (!currlist->next)
				return (currlist);
			currlist = currlist->next;
		}
	}
	return (currlist);
}

t_dlist	*ft_lst_firstnode(t_dlist *currlist)
{
	while (currlist)
	{
		if (!currlist->prev)
			return (currlist);
		currlist = currlist->prev;
	}
	return (currlist);
}

t_dlist	*ft_lst_nextnode(t_dlist *currlist)
{
	currlist = currlist->next;
	return (currlist);
}

void	free_list(t_dlist *head)
{
	t_dlist	*next;

	if (head && head->content)
		free(head->content);
	if (head != NULL)
	{
		next = head->next;
		free(head);
		free_list(next);
	}
}
