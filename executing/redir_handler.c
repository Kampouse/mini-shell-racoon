/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:50:09 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/21 19:01:36 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "executing.h"
#include "fcntl.h"

int	input_redir(char *temp)
{
	int	fd;

	fd = open(temp, O_RDONLY);
	if (fd < 0)
	{
		perror(temp);
		return (-1);
	}
	dup2(fd, 0);
	close(fd);
	return (0);
}

int	here_redir(char *temp)
{
	int	fd;

	fd = open("/tmp/here_docced", O_RDONLY, 0644);
	(void) temp;
	if (fd < 0)
	{
		fd = open("/tmp/here_docced", O_TRUNC | O_CREAT | O_RDWR, 0644);
		return (-1);
	}
	dup2(fd, 0);
	close(fd);
	return (0);
}

int	out_put_redir(char *temp)
{
	int	fd;

	fd = open(temp, O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (fd < 0)
	{
		perror("filesystem error could not create or open file \n");
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
		perror("filesystem error could not create or open file \n");
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
			if (temp->type == 0 && temp->eval)
				status = out_append(temp->eval);
			else if (temp->type == 1)
				status = here_redir(job->hereduc);
			else if (temp->type == 2 && temp->eval)
				status = input_redir(temp->eval);
			else if (temp->type == 3 && temp->eval)
				status = out_put_redir(temp->eval);
			temp = temp->next;
		}
	}
	return (status);
}
