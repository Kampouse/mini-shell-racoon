/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 02:46:42 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/09 17:33:37 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parsing.h"

void	handle_pipes(t_pipe *pipes, int status)
{
	if (pipes)
	{
		while (pipes->state)
		{
			start_signal(0);
			waitpid(-1, &status, 0);
			status = WEXITSTATUS(status);
			pipes->state--;
		}
		delete_pipe(pipes, 1);
	}
	else
	{
		waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
	}
	if (g_state.error != 0)
	{
		g_state.output = g_state.error;
		g_state.error = 0;
	}
	else
		g_state.output = status;
}

void	async_jobs(t_jobs *job, t_dlist *lst)
{
	t_jobs	*temp;
	t_pipe	*pipes;

	temp = job;
	g_state.output = 0;
	pipes = ft_pipe(job);
	free_list(lst);
	lst = NULL;
	job->piped = pipes;
	while (temp)
	{
		start_job(temp, lst, pipes);
		if (pipes)
			pipes->state++;
		temp = temp->next;
	}
	handle_pipes(pipes, 0);
	free_jobs((t_jobs *)job, 0);
}

void	job_composer(t_dlist *lst)
{
	t_jobs	*job;
	t_jobs	*temp;
	int		inc;

	job = job_lsting(lst);
	temp = NULL;
	temp = job;
	inc = 0;
	if (job)
	{
		pre_val_here(job, lst);
		while (temp)
		{
			eval(temp);
			temp = temp->next;
			inc++;
		}
		async_jobs(job, lst);
	}
}

/* start readline and tokenize the string */
void	quick_parser(char *str)
{
	const char	*trimed = ft_strtrim(str, " ");
	t_dlist		*lst;

	if (trimed && ft_strlen(trimed) > 0)
	{
		lst = parser((char *)trimed);
		if (lst != NULL)
		{
			job_composer(lst);
			exit(g_state.output);
		}
	}	
}

void	igntion_seq(void)
{
	char				*trimed;
	t_dlist				*lst;

	trimed = NULL;
	lst = NULL;
	while (1)
	{
		signal(SIGINT, sig_cc);
		signal(SIGQUIT,SIG_IGN);
		if (prompt(&trimed) && ft_strlen(trimed) > 0)
		{
			signal(SIGINT, sig_chi);
			lst = parser(trimed);
			if (lst != NULL)
				job_composer(lst);
		}
		else if (!trimed)
		{
			freelist(g_state.env);
			freelist(g_state.exprt);
			free(trimed);
			rl_clear_history();
			exit(g_state.output);
		}
	}
}
