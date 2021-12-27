/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:50:08 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/27 16:15:19 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Cette fonction ajoute un element a la liste ENV
void  add_new_env(char *new_env)
{
    char **new_list;
    int i;

    new_list = NULL;
    new_list = malloc(sizeof(char **) * (ft_tab_len(g_state.env) + ft_tab_len(&new_env) + 1));
    i = 0;
    while (g_state.env[i])
    {
        new_list[i] = ft_strdup(g_state.env[i]);
        i++;
    }
    new_list[i] = ft_strdup(new_env);
    g_state.env = new_list;
    // print_exprt(ft_tab_len(g_state.exprt));
}

void remove_env(char *to_remove)
{
    char **new_list;
    int i;
    int j;

    new_list = NULL;
    new_list = malloc(sizeof(char **) * (ft_tab_len(g_state.env)));
    i = 0;
    j = 0;
    while (g_state.env[j])
        {
            if (!ft_strncmp(g_state.env[j], to_remove, ft_strlen(to_remove)))
            {
                printf("found\n");
                j++;
            }
            else
            {
                new_list[i] = ft_strdup(g_state.env[j]);
                i++;
                j++;
            }
			new_list[i] = 0;
        }
        g_state.env = new_list;
}
