/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:45:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/16 16:23:23 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void delete_it(char *to_delete, int type)
// {
    
// }

///MARCHE PAS BIEN ENCORE
void do_unset(t_jobs *job)
{
   //besoin de trouver la variable dans la list env et export 
   //puis de delete de la liste
    int  i;
    int j;
    char *to_delete;
    
    i = 0;
    j = 1;
    to_delete = job->cmd[j];
    while (to_delete[i])
    {
        if (to_delete[i] == '=')
            printf("Not a valid identifier");
        i++;
    }
    i = 0;
    // printf("to delete = %s\n", to_delete);
    while (g_state.env[i])
    {
        if (!ft_strncmp(g_state.env[i], to_delete, (ft_strlen(to_delete) + 1)))
            printf("to delete from env = %s\n", to_delete);
        j++;
        i++;
    }
    i = 0;
    j = 1;
    while (g_state.exprt[i])
    {
        if (!ft_strncmp(g_state.exprt[i], to_delete, (ft_strlen(to_delete) + 1)))
            printf("to delete from export = %s\n", to_delete);
        j++;
        i++;
    }
}
