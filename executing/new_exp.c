/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_exp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:05:22 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/05 13:20:01 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void create_export(char **envp)
{
    int i;
    
    g_state.exprt = alloc_tab(envp);
    envp = ft_sort_tab(envp);

    i = -1;
    while (envp[++i])
    {
        g_state.exprt[i] = ft_strdup(envp[i]);
    }
}