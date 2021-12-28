/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:50:08 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/27 14:05:42 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Cette fonction ajoute un element a la liste ENV
// void  add_new_env(char *new_env)
// {
//     char **new_list;
//     int i;

//     new_list = NULL;
//     new_list = malloc(sizeof(char *) * (ft_tab_len(g_state.env) + ft_tab_len(&new_env) + 2));
//     i = 0;
//     while (g_state.env[i])
//     {
//         new_list[i] = ft_strdup(g_state.env[i]);
//         i++;
//     }
//     new_list[i] = ft_strdup(new_env);
//     i++;
//     new_list[i] = NULL;
//     g_state.env = new_list;
// }

// void remove_env(char *to_remove)
// {
//     char **new_list;
//     int i;
//     int j;

//     new_list = NULL;
//     new_list = malloc(sizeof(char *) * (ft_tab_len(g_state.env) + 1));
//     i = 0;
//     j = 0;
//     while (g_state.env[j])
//     {
//         if (!ft_strncmp(g_state.env[j], to_remove, ft_strlen(to_remove)))
//         {
//             printf("found\n");
//             j++;
//         }
//         if (g_state.env[j])
//         {
//             new_list[i] = ft_strdup(g_state.env[j]);
//             i++;
//             j++;
//         }
//     }
//     new_list[i] = NULL;
//     g_state.env = new_list;
// }