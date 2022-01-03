/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 22:49:52 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/03 12:43:42 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int parse_echo(char **old_cmd)
{
    for (int i = 0; old_cmd[i]; i++)
		printf("cmd[%d] = %s\n", i, old_cmd[i]);
    return (1);
}

void do_echo(t_jobs *jobs)
{
    int n;

    n = 0;
    if (ft_tab_len(jobs->cmd) > 1)
    {
        if (jobs->cmd[1])
        jobs->cmd++;
        n = parse_echo(jobs->cmd);
    }
    if (n == 1)
        write(1, "\n", 1);
}