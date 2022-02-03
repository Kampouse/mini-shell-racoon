/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 02:46:42 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/03 00:49:11 by jemartel         ###   ########.fr       */
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

void	parser_muduled(t_jobs *job, t_dlist *lst)
{
	t_jobs	*temp;
	t_pipe	*pipes;

	temp = job;
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

void	parser_core(t_dlist *lst)
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
		pre_val_redir(job);
		while (temp)
		{
			eval(temp);
			temp = temp->next;
			inc++;
		}
		parser_muduled(job, lst);
	}
}

/* start readline and tokenize the string */
void	quick_parser(char *str)
{
	const char	*trimed = ft_strtrim(str, " ");
	t_dlist		*lst;

	if (trimed && ft_strlen(trimed) > 0)
	{
		lst = line_parser((char *)trimed);
		free((char *)trimed);
		if (lst != NULL)
		{
			parser_core(lst);
			free_list(lst);
		}
	}	
}

void	parsing(void)
{
	char				*trimed;
	t_dlist				*lst;

	trimed = NULL;
	lst = NULL;
	while (1)
	{
		signal(SIGINT, sig_cc);
		if (parsing_start(&trimed) && ft_strlen(trimed) > 0)
		{
			signal(SIGINT, sig_chi);
			lst = line_parser(trimed);
			free(trimed);
			if (lst != NULL)
				parser_core(lst);
		}
		else if (!trimed)
		{
			freelist(g_state.env);
			freelist(g_state.exprt);
			rl_clear_history();
			free(trimed);
			exit(g_state.output);
		}
	}
}
