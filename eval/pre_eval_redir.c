/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_eval_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:30:49 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/08 17:59:41 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "fcntl.h"
#include "../minishell.h"
#include "../readline/readline.h"

char	*eval_docc(t_redir *temp);

void	squash_output(t_jobs *job, t_redir *temp, t_dlist *lst, char *str)
{
	int	fd;

	signal(SIGINT, SIG_DFL);
	str = eval_docc(temp);
	if (str != NULL)
	{
		fd = open("/tmp/here_docced", O_TRUNC | O_CREAT | O_RDWR, 0644);
		write(fd, str, ft_strlen(str));
		free(str);
		while (job)
		{
			job->eval = job->cmd;
			job = job->prev;
		}
		free_jobs(job, 0);
		free_nodes(lst);
		freelist(g_state.env);
		freelist(g_state.exprt);
		rl_clear_history();
		exit(g_state.output);
	}
	freelist(g_state.env);
	freelist(g_state.exprt);
	exit(130);
}

void	here_process(t_jobs *job, t_redir *temp, t_dlist *lst)
{
	int		pid;
	int		status;
	char	*str;

	str = NULL;
	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0)
		squash_output(job, temp, lst, str);
	waitpid(pid, &status, 0);
	g_state.output = status;
}

char	*eval_docc(t_redir *temp)
{
	char	*docc;
	char	*outcome;
	char	*line;

	line = NULL;
	outcome = NULL;
	g_state.output = 130;
	if (temp->type == 1)
	{
		docc = eval_line(temp->cmd, outcome, 0, 1);
		while (redir_poll(line, docc) == 1)
		{
			if (line)
			{
				outcome = quote_eval(line, 0, outcome, 0);
				free(line);
			}
			line = lazy_join(readline(">>"), ft_strdup("\n"));
		}
		free(docc);
	}
	return (outcome);
}

void	pre_val_here(t_jobs *jobs, t_dlist *lst)
{
	t_redir	*temp;

	temp = NULL;
	jobs->status = 0;
	if (jobs && jobs->redir)
	{
		temp = jobs->redir;
		while (temp)
		{
			if (temp->type == 1 && jobs->status == 0)
				here_process(jobs, temp, lst);
			temp = temp->next;
		}
		if (jobs && jobs->next)
			pre_val_here(jobs->next, lst);
	}
}
