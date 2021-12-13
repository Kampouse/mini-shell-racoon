/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:44 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/13 16:11:23 by olabrecq         ###   ########.fr       */
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

void update_env_exprt(t_jobs *job)
{
    char **variable;
    char **valeur;
    int i;
    int j;

    i = 1;
    j = 0;
    variable = malloc(sizeof(job->cmd[i]));
    while (job->cmd[i])
    {
        variable[j] = before_equal(job->cmd[i]);
        valeur[j++] = afther_equal(job->cmd[i++]);
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
