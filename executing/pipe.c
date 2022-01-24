/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:58:34 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/22 17:57:21 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_pipe(t_jobs *jobs)
{
    t_pipe *data;

    data = malloc(sizeof(t_pipe));
    data->pipe_nb = job_count(jobs);
    printf("nb de pipe = %d\n",data->pipe_nb);
    free(data);
}

int pipe_handler(int pipe[], int state, t_jobs *job)
{
    ft_pipe(job);
    if(state < -1)
        return(0);

    if(state == 0)
        dup2(pipe[1], 1);
    if(state == 1) 
        dup2(pipe[0], 0);
    return(0);
}   
