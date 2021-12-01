/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:49:42 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/01 14:26:29 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Cette fonction cree et init la struct s_exec: ENV & EXPORT
void init_exec(char **envp)
{
    create_env(envp);
    create_export(envp);
}
/*
t_jobs init_jobs()
{
    t_jobs *jobs;

    jobs = NULL;
    jobs = (t_jobs*)malloc(sizeof(t_jobs));

    jobs->args = {"ls", "-l"};
    
    return (jobs);
    
}

void jobs_analizer(t_jobs *jobs)
{
    jobs = init_jobs();
    execve()
}
*/
