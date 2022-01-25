/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:54:06 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/25 12:03:54 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

t_dlist	*job_find_pipe(t_dlist *lst)

{
	t_dlist	*temp;

	if (lst)
	{
		temp = lst;
		while (temp)
		{
			if (temp->type == 4)
				return (temp->next);
			temp = temp->next;
		}
	}
	return (NULL);
}

void	free_jobs(t_jobs *head, int type)
{
	t_jobs	*next;

	next = NULL;
	if (head)
	{
		next = head->next;
		if (head->redir)
			free_redir(head->redir);
		if (head->eval && head->eval[0] && type == 1)
		{
			free(head->eval);
		}
		else if (head->eval)
		{
			freelist(head->eval);
		}
		if (head->hereduc)
			free(head->hereduc);
		free(head);
		free_jobs(next, type);
	}
}
