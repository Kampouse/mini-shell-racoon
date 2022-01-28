/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 02:46:42 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/28 14:33:01 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parsing.h"

/* loop that  evalute   entire  line that it as read */


void copy_pipe(t_pipe *pipes)
{
	pipes->old_pipe[1] = pipes->piped[1];
	pipes->old_pipe[0] = pipes->piped[0];
}
void close_pipe(t_pipe *pipes)
{
	close(pipes->piped[1]);
	close(pipes->piped[0]);
}
void refresh_pipe(t_pipe *pipes,int pipe0,int pipe1)
{
	pipes->piped[0] = pipe0;
	pipes->piped[1] = pipe1;
}




void	parser_muduled(t_jobs *job, t_dlist *lst)
{
	t_jobs		*temp;
	t_pipe 			*pipes;
	int counter;
	
	counter = 0;
	temp = job;
	pipes = ft_calloc(sizeof(t_pipe ),1);
	if(pipes)
	{
		pipes->state = 0;
		pipes->old_pipe[1] = -1;
		pipes->old_pipe[0] = -1;
		pipe(pipes->piped);
	}
		while (temp)
	{
			if(pipes->state == 1)
		{

			//close(pipes->piped[0]);
			//close(pipes->piped[1]);
		}
		start_job(temp, lst, pipes);
		temp = temp->next;
		pipes->state++;
	}
	int inc;

	inc = 0;
	while(inc < pipes->state)
	{
	
		wait(&counter);
		inc++;


	}
	if(pipes)
		{
			printf("%d\n",pipes->state);
		}
		counter++;
	
	delete_pipe(pipes,1);
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
		free_nodes(lst);
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
			parser_core(lst);
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
		if (parsing_start(&trimed) && ft_strlen(trimed) > 0)
		{
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
