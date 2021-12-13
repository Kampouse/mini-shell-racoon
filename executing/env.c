/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:23 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/13 15:31:06 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char **alloc_tab(char **envp)
{
    char **tab;
    int i;

    i = 0;
    while (envp[i])
        i++;
	tab = ft_calloc( i + 1,sizeof(char**));
    return (tab);
}

void create_env(char **envp)
{
    g_state.env = alloc_tab(envp);
    int i;

    i = 0;
    while (envp[i])
    {
        g_state.env[i] = ft_strdup(envp[i]);
        i++;
    }
}

void print_env(int tab_len)
{
    int i;

    i = 0;
    while (i < tab_len)
        printf("%s\n", g_state.env[i++]);
}
