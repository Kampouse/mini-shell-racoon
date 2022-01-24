/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:23:22 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/22 00:51:22 by jemartel         ###   ########.fr       */
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
	return (-1);
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
			  redir_addback(&redir_lst,
				node_redir(temp->next->content, temp->type));
		else if (valid_redir(temp) < 0)
		{
			*status = -1;
			ft_putstr_fd("error at newLine\n", 2);
			g_state.output = 2;
			free_redir(redir_lst);
			return (NULL);
		}
		if (temp->next && temp->next->type != 4)
			temp = temp->next;
		else
			break ;
	}
	return (redir_lst);
}
