/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 22:49:52 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/04 04:56:36 by jemartel         ###   ########.fr       */
/*   Updated: 2022/01/03 21:36:26 by olabrecq         ###   ########.fr       */
/*                                                                            */
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
        if (!ft_strncmp(jobs->eval[1], "-n", (size_t)(sizeof(char) * 2)))
    if (ft_tab_len(jobs->eval) > 1)
    {
        if (!ft_strncmp(jobs->cmd[1], "-n", (size_t)(sizeof(char) * 2)))
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
    if (!n)
        printf("\n");
    
	}
}
}
