/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblink_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:46:47 by jemartel          #+#    #+#             */
/*   Updated: 2021/11/20 01:54:55 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_dlist	*ft_lst_lastnode(t_dlist *currlist)
{
	if( currlist && currlist->next)
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
	t_dlist	*link;

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


	if(head && head->content)
		free(head->content);
	if (head != NULL)
	{
		next = head->next;
		free(head);
		free_list(next);
	}
}
void	ft_lstddelone(t_dlist *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

void	ft_lstdclear(t_dlist **lst, void (*del)(void*))
{
	t_dlist	*clear;

	if (!lst || !*lst || !del)
		return ;
	while (lst && *lst)
	{
		clear = (*lst)->next;
		ft_lstddelone(*lst, del);
		*lst = clear;
	}
}
