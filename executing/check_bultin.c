/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bultin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:44:05 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/08 14:38:18 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void check_bultin(t_jobs *job)
{
    if (!(ft_strncmp(job->cmd[0], "export", ft_strlen(job->cmd[0]))))
            do_export(job);
//     if (!(ft_strncmp(job->cmd[0], "echo", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "env", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "pwd", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "cd", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "unset", ft_strlen(trimed))))
//     if (!(ft_strncmp(job->cmd[0], "exit", ft_strlen(trimed))))
}
