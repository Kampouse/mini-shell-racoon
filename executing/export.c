/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:44 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/14 11:49:14 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

/// Si ny a pas de '=' variable devient valeur
void update_env_exprt(t_jobs *job)
{
    char **variable = NULL;
    char **valeur = NULL;
    int i;
    int j;

    i = 1;
    j = 0;
    variable = malloc(sizeof(job->cmd));
    valeur = malloc(sizeof(job->cmd));
    while (job->cmd[i])
    {
        variable[j] = before_equal(job->cmd[i]);
        valeur[j] = afther_equal(job->cmd[i]);
        j++;
        i++;
    }
    printf("variable = %s\n", variable[j]);
}

void do_export(t_jobs *job)
{
    if (ft_tab_len(job->cmd) == 1)
        print_exprt(ft_tab_len(g_state.exprt));
    if (ft_tab_len(job->cmd) > 1)
    {
        if (export_valider(job))
            printf("Not a valid export\n");
        else 
            update_env_exprt(job);

        
    }
}
