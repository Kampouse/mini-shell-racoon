/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_valider.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:51:42 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/07 19:09:14 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int got_good_args(t_jobs *job)
{
    int i;
    char *temp;

    i = 0;
    while (job->cmd[i])
    {
        temp = job->cmd[i];
        //reguarde si les premiere lettre des cmd est un chiffre ou un =
        if ((ft_isdigit(temp[0])) || temp[0] == '=')
            return (1);
        //reguarde si = est seul ex: (a = b)
        if (!(ft_strncmp(job->cmd[i], "=", ft_strlen(job->cmd[i]))))
            return (1);
        i++;
    }
    return (0);
}

int export_valider(t_jobs *job)
{
    if (got_good_args(job))
        return (1);
    //besoin de reflechir comment trouver variable avant [=]
    //et valeur apres les [=]
    return (0);
}