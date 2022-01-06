/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:44 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/06 15:51:28 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int got_good_args(char *cmd)
{
    int i;

    i = 0;
    if (!ft_isalpha(cmd[i]) && cmd[i] != '_')
        return (1);
    while (cmd[++i] && cmd[i] != '=')
        if (!ft_isalnum(cmd[i]) && cmd[i] != '_')
            return(1);
    return (0);
}

void create_export(char **envp)
{
    int i; 
    
    i = 0;
    g_state.exprt = alloc_tab(envp);
    while (envp[i])
    {
        g_state.exprt[i] = ft_strdup(envp[i]);
        i++;

    }
    ft_sort_tab(g_state.exprt);
}

void print_exprt(int tab_len)
{
    int i;

    i = 0;
    while (i < tab_len)
        printf("%s\n", g_state.exprt[i++]);
}

//Cette fonction trie les bonne variable et valeur a ajouter a la liste export
void update_export_list(char *var, char *val, int type)
{
    char *new_exprt;
    char **temp;
    
    if (type == 1)
    {
        new_exprt = ft_strjoin(var, val);
        g_state.exprt = add_to_list(new_exprt,g_state.exprt, 1);
        free(new_exprt);
    }
    if (type == 3)
    {
        val = ft_str3join("\"", val, "\"");
        new_exprt = ft_strjoin(var, val);
        free(val); 
        temp = add_to_list(new_exprt,g_state.exprt, 1);
        free(new_exprt);
        g_state.exprt = temp;
    }
}

void parse_export(char *to_export)
{
    char *variable = NULL;
    char *valeur = NULL;
    
    if (last_is_equal(to_export))
    {
        update_export_list(to_export, "\"\"", 1);
        update_env_list(to_export, "\"\"", 1);
    }
    else
    {
        if (!no_equal(to_export))
        {
            variable = ft_strdup("' '");
            valeur = ft_strdup(to_export);
            g_state.exprt = add_to_list(valeur, g_state.exprt, 1);
        }
        else
        {
            variable = before_equal(to_export);
            valeur = afther_equal(to_export);
            update_export_list(variable, valeur, 3);
            update_env_list(variable, valeur, 3);
        }
        free(valeur);
        free(variable);
    }
        
}
    

void do_export(t_jobs *job)
{
    int i;
    
    if (ft_tab_len(job->cmd) == 1)
        print_exprt(ft_tab_len(g_state.exprt));
    if (ft_tab_len(job->cmd) > 1)
    {
        i = 0;
        while (job->cmd[++i])
        {
            if (got_good_args(job->cmd[i]))
                printf("Not a valid export\n");
            else 
                parse_export(job->cmd[i]);
        }
    }
}
