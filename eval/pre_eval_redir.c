/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_eval_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:30:49 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/15 18:32:37 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "fcntl.h"
#include "../minishell.h"
#include "../readline/readline.h"

char	*eval_docc(t_redir *temp);

void	squash_delete(t_jobs *job, t_redir *temp, int fd, char *str)
{
	job->eval = job->cmd;
	signal(SIGINT, SIG_DFL);
	str = eval_docc(temp);
	start_signal(1);
	job->eval = job->cmd;
	if (str != NULL)
	{
		fd = open("/tmp/here_docced", O_TRUNC | O_CREAT | O_RDWR, 0644);
		write(fd, str, ft_strlen(str));
		free(str);
		free_jobs(job, 0);
		freelist(g_state.env);
		freelist(g_state.exprt);
		close(fd);
		exit(0);
	}
	else
	{
		free_jobs(job, 0);
		freelist(g_state.env);
		freelist(g_state.exprt);
		exit(130);
	}
}

void	docc_out(t_jobs *job, t_redir *temp)
{
	int		pid;
	int		status;
	char	*str;
	int		fd;

	fd = 0;
	str = NULL;
	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0)
		squash_delete(job, temp, fd, str);
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

void	pre_val_redir(t_jobs *jobs)
{
	t_redir	*temp;

	temp = NULL;
	if (jobs && jobs->redir)
	{
		temp = jobs->redir;
		while (temp)
		{
			if (temp->type == 1 && jobs->status == 0)
			{
				docc_out(jobs, temp);
			}
			temp = temp->next;
		}
		if (jobs && jobs->next)
			pre_val_redir(jobs->next);
	}
}
