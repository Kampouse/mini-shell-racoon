/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:18:35 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/05 22:35:27 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int no_equal(char *cmd)
{
    int i;

    i = 0;
    while (cmd[i])
    {
        if (cmd[i] == '=')
            return (1);
        i++;
    }
    return(0);
}

int last_is_equal(char *cmd)
{
    int i;
    int count;
    
    count = 0;
    i = 0;
    while (cmd[i])
    {
        if (cmd[i] == '=' && cmd[i + 1] != '\0')
            count++;
        if (cmd[i] == '=' && cmd[i + 1] == '\0' && !count)
            return(1);
        i++;
    }
    return (0);
}

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

void print_exprt(int tab_len)
{
    int i;

    i = 0;
    while (i < tab_len)
        printf("%s\n", g_state.exprt[i++]);
}
