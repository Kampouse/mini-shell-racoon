/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:58:34 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/26 17:53:21 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delete_pipe(t_pipe *pipes, int should_delete)
{
	int	inc;

	inc = 0;
	if (pipes)
	{
		while (inc < pipes->pipe_nbr)
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
	pipes->state = 0;
//	pipes->read_location = 0;
	pipe(pipes->test);
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
	if(pipes)
	{

	
	if(pipes->state == 0)
	{
		printf("stdin:%d\n",pipes->state);
		dup2(pipes->test[1],1);
	}
	else
	{
		printf("%d",dup2(pipes->test[0],0));
		close(pipes->test[1]);
	}
	return (0);
	}
	return (0);
}
