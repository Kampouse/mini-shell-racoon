/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:44 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/07 17:50:01 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_tab_len(char **tab)
{
    int i;
    
    i = 0;
    while (tab[i])
        i++;
    return (i);
}

char **ft_sort_tab(char **tab)
{
    int i;
    int j;
    char **temp_tab = NULL;
    char **tab_sorted;
    
    temp_tab = alloc_tab(tab);
    tab_sorted = tab;
    i = 0;
    while (i < ft_tab_len(tab))
    {
        j = 0;
        while (j < ft_tab_len(tab))
        {
            if (ft_strncmp(tab_sorted[i], tab[j], ft_strlen(tab_sorted[i])) < 0)
            {
                temp_tab[i] = tab_sorted[i];
                tab_sorted[i] = tab[j];
                tab[j] = temp_tab[i];
            }
            j++;
        }
        i++;
    }
    return (tab_sorted);
}

void create_export(char **envp)
{
    g_state.exprt = ft_sort_tab(envp);
}

void print_exprt(int tab_len)
{
    int i;

    i = 0;
    while (i < tab_len)
        printf("%s\n", g_state.exprt[i++]);
}

void do_export(t_jobs *job)
{
    if (ft_tab_len(job->cmd) == 1)
        print_exprt(ft_tab_len(g_state.exprt));
    if (ft_tab_len(job->cmd) > 1)
    {
        if (export_valider(job))
            printf("Not a valid export\n");
    }
}