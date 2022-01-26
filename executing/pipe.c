/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:58:34 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/25 18:56:28 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delete_pipe(t_pipe *pipes, int should_delete)
{
	int	inc;

	inc = 0;
	if (pipes)
	{
		while (inc <= pipes->pipe_nbr)
		{
			free(pipes->pipes[inc]);
			inc++;
		}
		free(pipes->pipes);
	}
	if (pipes && should_delete == 1)
		free(pipes);
}

t_pipe	*init_pipes(t_pipe *pipes, int len)
{
	int	inc;

	inc = 0;
	pipes->pipe_nbr = 0;
	while (inc != len)
	{
		if (pipe(pipes->pipes[inc]) < 0)
		{
			delete_pipe(pipes, 1);
			return (NULL);
		}
		inc++;
	}
	return (pipes);
}

t_pipe	*ft_pipe(t_jobs *jobs)
{
	t_pipe	*data;
	int		inc;
	int		len;

	len = job_count(jobs);
	inc = 0;
	if (!jobs || len <= 0)
	{
		return (NULL);
	}
	data = malloc(sizeof(t_pipe));
	data->pipe_nbr = len;
	data->pipes = malloc(sizeof(int **) * (len));
	while (inc != len)
	{
		data->pipes[inc] = ft_calloc(2, sizeof(int));
		inc++;
	}
	return (init_pipes(data, len));
}

int	pipe_handler(t_pipe *pipes)
{
//	ft_pipe(job);
	//if (state < -1)
		//return (0);
	(void)pipes;

	//if (state == 0)
		//dup2(pipe[1], 1);
	//if (state == 1)
		//dup2(pipe[0], 0);
	return (0);
}
