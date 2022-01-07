/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 22:49:52 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/07 12:36:08 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "../minishell.h"

void do_echo(t_jobs *jobs)
{
    int n;
    int i;

    n = 0;
    i = 1;
    if (ft_tab_len(jobs->eval) > 1)
    {
        if (!ft_strncmp(jobs->eval[1], "-n", (size_t)(sizeof(char) * 2)) && \
        ft_strlen(jobs->eval[1]) == 2)
        {
            n++;
            i++;
        }
        while (jobs->eval[i])
        {
            if (jobs->eval[i + 1])
                printf("%s ", jobs->eval[i++]);
            else
                printf("%s", jobs->eval[i++]);
        }
    }
    if (!n)
        printf("\n");
}
