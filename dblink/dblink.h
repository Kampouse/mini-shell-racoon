/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblink.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:42:53 by jemartel          #+#    #+#             */
/*   Updated: 2021/12/23 09:48:09 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DBLINK_H
# define  DBLINK_H 

typedef struct t_dlist
{
	void			*content;
	struct t_dlist	*next;
	struct t_dlist	*prev;
}		t_dlist;

void	ft_add_frontd(t_dlist **currlist, t_dlist *newnode);
void	ft_add_backd(t_dlist **currlist, t_dlist *node);
t_dlist	*ft_lst_lastnode(t_dlist *currlist);
t_dlist	*ft_lstnewl(void *content);
t_dlist	*node_init(void *content);
void	ft_clearnode(t_dlist *currlist, void (*del)(void *));
void	ft_cleart_dlist(t_dlist **currlist, void (*del)(void *));
t_dlist	*ft_lst_lastnode(t_dlist *currlist);
t_dlist	*ft_lst_firstnode(t_dlist *currlist);
t_dlist	*ft_lst_nextnode(t_dlist *currlist);
t_dlist	*ft_lstnewl(void *content);
void	free_list(t_dlist *head);
t_dlist	*node_init(void *content);

# endif
