/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblink_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:46:47 by jemartel          #+#    #+#             */
/*   Updated: 2021/11/17 10:47:13 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_dlist	*ft_lst_lastnode(t_dlist *currlist)
{
	while (currlist->next)
	{
		if (!currlist->next)
			return (currlist);
		currlist = currlist->next;
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
/*
int	ft_lst_lenght(t_dlist *currlist)
{
	int	len;

	len = 0;
	while (currlist)
	{
		currlist = currlist->next;
		len++;
	}
	return (len);
}
*/
t_dlist	*ft_lstnewl(void *content)
{
	t_dlist	 *link;

	link = (t_dlist *)malloc(sizeof(*link));
	if (!link)
		return (NULL);
	link->content = content;
	link->next = NULL;
	return (link);
}

void	free_list(t_dlist *head)
{
	t_dlist	*next;

	if (head != NULL)
	{
		next = head->next;
		free(head->content);
		free(head);
		free_list(next);
	}
}


