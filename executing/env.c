/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:23 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/16 14:48:31 by olabrecq         ###   ########.fr       */
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


void do_env(t_jobs *job)
{
    if (ft_tab_len(job->cmd) == 1)
        print_env(ft_tab_len(g_state.env));
}

void update_env_list(char *var, char *val, int type)
{
    char *new_env;

    if (type == 1)
    {
        new_env = var;
        printf("new env =  %s\n", new_env);
        add_new_env(new_env);
        // jean="" = export et jean= = env
    }
    // if (type == 2)
    // {
    //     new_env = val;
    //     printf("new env =  %s\n", new_env);
    //     add_new_export(new_env);
    //     // jean = export env xx
    // }
    if (type == 3)
    {
        new_env = ft_strjoin(var, val);
        printf("new env =  %s\n", new_env);
        add_new_env(new_env);
        // jean="oli" export jean=oli env
    }
}

