/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 22:49:52 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/03 19:56:16 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void do_echo(t_jobs *jobs)
{
    int n;
    int i;

    n = 0;
    i = 0;
    jobs->cmd++;
    if (ft_tab_len(jobs->cmd) > 1)
    {
        if (ft_strncmp(jobs->cmd[1], "\n", ft_strlen(jobs->cmd[1])))
        {
            printf("ENDL\n");
            jobs->cmd++;
            n = 1;
        }
        while (jobs->cmd[i])
        {
            printf("%s", jobs->cmd[i++]);
        }
    }
    if (n == 0)
        write(1, "\n", 1);
}