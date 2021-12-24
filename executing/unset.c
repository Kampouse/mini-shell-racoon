/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:45:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/23 09:45:09 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int count_equal(t_jobs *job)
// {
//     int i;
    
//     i = 0;
//     while (job->cmd[i])
//     {
//         if (job->cmd[i] == '=')
//             return (i);
//         i++;
//     }
//     return (0);
// }

// void delete_it(char *to_delete, int type)
// {
    
// }

///MARCHE PAS BIEN ENCORE
// void do_unset(t_jobs *job)
// {
//    //besoin de trouver la variable dans la list env et export 
//    //puis de delete de la liste
//    //faire une fonction qui trouve un egal pour la len de strncmp
//     int  i;
//     int j;
//     char *to_delete;
    
//     i = 0;
//     j = 1;
//     to_delete = job->cmd[j];
//     while (to_delete[i])
//     {
//         if (to_delete[i] == '=')
//             printf("Not a valid identifier");
//         i++;
//     }
//     i = 0;
//     // printf("to delete = %s\n", to_delete);
//     while (g_state.env[i])
//     {
//         if (!ft_strncmp(g_state.env[i], to_delete, (ft_strlen(to_delete) + 1)))
//             printf("to delete from env = %s\n", to_delete);
//         j++;
//         i++;
//     }
//     i = 0;
//     j = 1;
//     while (g_state.exprt[i])
//     {
//         if (!ft_strncmp(g_state.exprt[i], to_delete, (ft_strlen(to_delete) + 1)))
//             printf("to delete from export = %s\n", to_delete);
//         j++;
//         i++;
//     }
// }

//passer les liste env et epxport a la recherche de variable a delete
//stncmp de la len de la varible
// void do_unset(t_jobs *job)
// {
//     int i;

//     i = 0;
    
// }

// void search_n_delete(char *var)
// {
    
// }