/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 02:46:42 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/17 16:41:10 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"
#include "parsing.h"

/* evaluate each job one after the  other */

int	pipe_counter(t_dlist *lst)
{
	t_dlist	*tmp;
	int		count;

	count = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->type == 4)
			count += 2;
		tmp = (t_dlist *)tmp->next;
	}
	return (count);
}

void	parser_muduled(t_jobs *job, t_dlist *lst, int inc)
{
	t_jobs		*temp;
	int			pipes[2];
	int			state;

	state = 0;
	temp = job;
	if (inc > 1)
		pipe(pipes);
	else
		state = -1;
	while (temp)
	{
		start_job(temp, lst, pipes, state);
		temp = temp->next;
	}
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
		parser_muduled(job, lst, inc);
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



char *prompt_eval(void)
{

	char *str;
	char *out;
	int  inc;

	inc = 0;
	str = NULL;
	str = eval_line("$PWD",str,0,0);
	inc = ft_strlen(str);
	inc--;
	while(str[inc] != '/')
		inc--;
	inc++;
	out = ft_strdup(&str[inc]);
	free(str);
	str = ft_strjoin(out,":>");
	free(out);
	out  = ft_str3join(GREEN,str,RESET);
	free(str);
	return(out);
}

char *parsing_start(void)
{
	char	*trimed;
	char	*line;
	char	*prompt;
	

		prompt =prompt_eval();
		g_state.redraw = 0;
		start_signal(0);
		line = readline(prompt);
		free(prompt);
		trimed = ft_strtrim(line, "\n ");
		add_history(trimed);
		free(line);
		return(trimed);
}


void	parsing(void)
{
	char				*trimed;
	t_dlist				*lst;

	lst = NULL;
	while (1)
	{
			trimed = parsing_start();	

		if (trimed && ft_strlen(trimed) > 0)
		{
			lst = line_parser(trimed);
			free(trimed);
			if (lst != NULL)
				parser_core(lst);
		}
		else
			free(trimed);
	}
}
