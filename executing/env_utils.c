/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:50:08 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/20 16:46:13 by olabrecq         ###   ########.fr       */
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
