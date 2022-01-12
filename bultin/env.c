/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:57:52 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/11 14:03:59 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "../minishell.h"

char **alloc_tab(char **old_tab)
{
    char **tab;
    int i;

    i = 0;
    while (old_tab[i])
    {
        i++;
    }
	tab = ft_calloc(i + 1, sizeof(char**));
    return (tab);
}

void create_env(char **envp)
{
    int i;

    g_state.env = alloc_tab(envp);

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

int do_env(t_jobs *job)
{
    if (ft_tab_len(job->cmd) != 1)
        return (1);
    print_env(ft_tab_len(g_state.env));
    return (0);
}

void update_env_list(char *var, char *val, int type)
{
    char *new_env;

    if (type == 1)
    {
        new_env = var;
        g_state.env = add_to_list(new_env, g_state.env, 0);
    }
    if (type == 3)
    {
        new_env = ft_strjoin(var, val);
        g_state.env = add_to_list(new_env, g_state.env, 0);
        free(new_env);
    }
}

