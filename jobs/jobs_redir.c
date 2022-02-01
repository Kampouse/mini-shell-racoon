/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:52:17 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/01 17:41:52 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:23:22 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/24 14:52:15 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "../minishell.h"

int	valid_redir( t_dlist *redir)
{
	if (redir->type >= 0 && redir->type <= 3)
	{
		if (redir->next && !(redir->next->type >= 0 && redir->next->type <= 4))
			return (1);
	}
	if (!(redir->type >= 0 && redir->type <= 3))
		return (0);
	g_state.output = 2;
	return (-1);
}

t_dlist	*redir_tail(t_redir **redir_lst, t_dlist *lst)
{
	t_dlist	*temp;
	int		type;

	temp = lst;
	if (!(temp && temp->next && temp->next->next))
		return (temp);
	else if (!(temp->type >= 0 && temp->type <= 3) || temp->type == 1)
		return (temp);
	else
	{
		type = temp->type;
		temp = temp->next->next;
	}
	while (temp && !(temp->type >= 0 && temp->type <= 4))
	{
		redir_addback(redir_lst,
			node_redir(temp->content, type));
		temp = temp->next;
	}
	return (temp);
}

t_redir	*redir_creator(t_dlist *redir, int *status)
{
	t_dlist	*temp;
	t_redir	*redir_lst;

	redir_lst = NULL;
	temp = redir;
	while (temp)
	{
		if (valid_redir(temp) == 1)
			redir_addback(&redir_lst, node_redir(temp->next->content,
					temp->type));
		else if (valid_redir(temp) < 0)
		{
			*status = -1;
			ft_putstr_fd("error at newLine\n", 2);
			free_redir(redir_lst);
			return (NULL);
		}
		redir_tail(&redir_lst, temp);
		if (temp && temp->next && temp->next->type != 4)
			temp = temp->next;
		else
			break ;
	}
	return (redir_lst);
}
