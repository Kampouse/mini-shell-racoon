/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 22:49:52 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/04 11:47:20 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void do_echo(t_jobs *jobs)
{
    int n;
    int i;

    n = 0;
    i = 1;
    if (ft_tab_len(jobs->cmd) > 1)
    {
        if (!ft_strncmp(jobs->cmd[1], "-n", (size_t)(sizeof(char) * 2)) && \
        ft_strlen(jobs->cmd[1]) == 2)
        {
            n++;
            i++;
        }
        while (jobs->cmd[i])
        {
            if (jobs->cmd[i + 1])
                printf("%s ", jobs->cmd[i++]);
            else
                printf("%s", jobs->cmd[i++]);
        }
    }
    if (!n)
        printf("\n");
}
