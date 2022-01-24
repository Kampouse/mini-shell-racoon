/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:20:57 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/24 14:29:24 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* verify  if the | symbol is  between two element of the right type */
int	pipe_return(int status)
{
	if (status == -1)
	{
		printf("syntax error near unexpected token `|'\n");
		return (-1);
	}
	return (0);
}

int	piping_verif(t_dlist *lst)
{
	t_dlist	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->type == 4)
		{
			if (temp->prev && (temp->prev->type >= 0 && temp->prev->type <= 4))
				return (pipe_return(-1));
			if (temp->next && temp->next->type == 4)
				return (pipe_return(-1));
			if (!temp->prev || !temp->next)
				return (pipe_return(-1));
		}
		temp = temp->next;
	}
	return (0);
}

/* create a jobs with the right element in it */
int	jobs(t_dlist *lst, t_jobs **output)
{
	t_redir		*redir;
	t_dlist		*cmd_head;
	int			status;
	char		**commands;

	commands = NULL;
	cmd_head = NULL;
	status = 0;
	redir = redir_creator(lst, &status);
	if (status < 0)
		return (-1);
	if (lst && lst->content)
		commands = jobs_lst_creator(lst, &cmd_head);
	*output = job_new_lst(commands, redir, cmd_head);
	return (0);
}

/* function that  create a list of (jobs) break on failure */
t_jobs	*jobs_tail(t_dlist *lst, t_jobs *currjobs)
{
	t_dlist		*temp;
	t_jobs		*tempjob;

	temp = job_find_pipe(lst);
	if (temp)
	{
		if (jobs(temp, &tempjob) >= 0)
		{
			jobs_addback(&currjobs, tempjob);
			return (jobs_tail(temp, currjobs));
		}
		else
		{
			if (currjobs)
				free_jobs(currjobs, 1);
			return (NULL);
		}
	}
	return (currjobs);
}

t_jobs	*job_lsting(t_dlist *lst)
{
	t_jobs	*joblst;

	joblst = NULL;
	if (piping_verif(lst) == 0 && jobs(lst, &joblst) == 0)
		return (jobs_tail(lst, joblst));
	else
		return (NULL);
	return (joblst);
}
