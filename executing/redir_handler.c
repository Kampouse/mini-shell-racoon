/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:50:09 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/12 15:42:08 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "../minishell.h"

int	input_redir(char *temp)
{
	int	fd;

	fd = open(temp, O_RDONLY);
	if (fd < 0)
	{
		perror(temp);
		g_state.output = 1;
		return (-1);
	}
	dup2(fd, 0);
	close(fd);
	return (0);
}

int	here_redir(void)
{
	int	fd;

	fd = open("/tmp/here_docced", O_RDONLY, 0644);
	if (fd < 0)
	{
		dup2(fd, 0);
		close(fd);
		fd = open("/tmp/here_docced", O_TRUNC | O_CREAT | O_RDWR, 0644);
		return (0);
	}
	else
	{
		dup2(fd, 0);
		close(fd);
	}
	return (0);
}

int	out_put_redir(char *temp)
{
	int	fd;

	fd = open(temp, O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (fd < 0)
	{
		perror(temp);
		return (-1);
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}

int	out_append(char *temp)
{
	int	fd;

	fd = open(temp, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd < 0)
	{
		perror(temp);
		return (-1);
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}

int	redir_handler(t_jobs *job)
{
	t_redir		*temp;
	int			status;

	temp = NULL;
	status = 0;
	if (job->redir)
	{
		temp = job->redir;
		while (temp && status == 0)
		{
				status = here_redir();
			if (temp->type == 0 && temp->eval)
				status = out_append(temp->eval);
			else if (temp->type == 2 && temp->eval)
				status = input_redir(temp->eval);
			else if (temp->type == 3 && temp->eval)
				status = out_put_redir(temp->eval);
			temp = temp->next;
		}
	}
	return (status);
}
