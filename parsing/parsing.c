/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 02:46:42 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/01 10:48:34 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parsing.h"

/* loop that  evalute   entire  line that it as read */

void	parser_muduled(t_jobs *job, t_dlist *lst)
{
	t_jobs			*temp;
	t_pipe 			*pipes;

	temp = job;
	pipes = ft_pipe(job);
		while (temp)
		{
			start_job(temp, lst, pipes);
			if(pipes)
				pipes->state++;
			temp = temp->next;
		}
	if(pipes)
	{
		while(pipes->state)
		{
			start_signal(0);
			wait((int *)&g_state.output);
			pipes->state--;
		}
		delete_pipe(pipes,1);
	}
	else
		wait((int *)&g_state.output);
	free_list(lst);
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
		job->lst = lst;
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
			//freelist(g_state.env);
			//freelist(g_state.exprt);
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
			signal(SIGQUIT, SIG_IGN);
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
