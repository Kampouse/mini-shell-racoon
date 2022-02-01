/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:46:19 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/01 17:46:30 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executing.h"

void	handle_fd(t_pipe *pipes)
{
	if (pipes && pipes->state < pipes->pipe_nbr)
	{
		dup2(pipes->pipes[pipes->state][1], 1);
		close(pipes->pipes[pipes->state][1]);
		close(pipes->pipes[pipes->state][0]);
	}
	if (pipes && pipes->state != 0)
	{
		dup2(pipes->pipes[pipes->state - 1][0], STDIN_FILENO);
		close(pipes->pipes[pipes->state - 1][1]);
		close(pipes->pipes[pipes->state - 1][0]);
	}
}

void	handle_fd_main(t_pipe *pipes)
{
	if (pipes && pipes->state > 0)
	{
		close(pipes->pipes[pipes->state - 1][0]);
		close(pipes->pipes[pipes->state - 1][1]);
	}
}
