/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_valider.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:51:42 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/07 18:54:14 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int equal_alone(t_jobs *job)
{
    int i;

    i = 0;
    while (job->cmd[i])
    {
        if (!(ft_strncmp(job->cmd[i], "=", ft_strlen(job->cmd[i]))))
            return (1);
        i++;
    }
    return (0);
}

int got_good_args(t_jobs *job)
{
    int i;
    char *temp;

    i = 0;
    while (job->cmd[i])
    {
        temp = job->cmd[i];
        if ((ft_isdigit(temp[0])))
            return (1);
        i++;
    }
    return (0);
}

int export_valider(t_jobs *job)
{
    if (equal_alone(job) || got_good_args(job))
    {
        printf("Not a valid export\n");
        return (1);
    }
    return (0);
}
