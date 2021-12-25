/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:45:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/23 20:34:51 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Cette fonction parse la commande unset et retourne une liste des variable a "unset"
// char **parse_unset(t_jobs *job)
// {
    
// }

//passer les liste env et epxport a la recherche de variable a delete
//stncmp de la len de la varible
void do_unset(t_jobs *job)
{
    int     i;
    char    *to_delete;
    
    // to_delete dois etre char ** car peu avoir plus qu'un a la fois
    to_delete = job->cmd[1];
    i = 0;
    while (g_state.env[i])
    {
        if (!ft_strncmp(g_state.env[i], to_delete, ft_strlen(job->cmd[1])))
        {
            printf("On supprime ca tabarnak!!! \n");
            // remove_from_list();
        }
        i++;
    }
    i = 0;
    while (g_state.exprt[i])
    {
        if (!ft_strncmp(g_state.exprt[i], to_delete, ft_strlen(job->cmd[1])))
        {
            printf("On supprime ca tabarnak!!! \n");
            // remove_from_list();
        }
        i++;
    }
}

// void search_n_delete(char *var)
// {
    
// }