/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:44 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/04 19:31:17 by jemartel         ###   ########.fr       */
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

//Cette fonction trie les bonne variable et valeur a ajouter a la liste export
void update_export_list(char *var, char *val, int type)
{
    char *new_exprt;
    char **temp;
    if (type == 1)
    {
        new_exprt = ft_strjoin(var, val);
        g_state.exprt = add_to_list(new_exprt,g_state.exprt, 1);
    }
    if (type == 2)
    {
        new_exprt = val;
        g_state.exprt = add_to_list(new_exprt,g_state.exprt, 1);
    }
    if (type == 3)
    {
        val = ft_str3join("\"", val, "\"");
        new_exprt = ft_strjoin(var, val);
    
        temp = add_to_list(new_exprt,g_state.exprt, 1);
        //free(g_state.exprt);
        g_state.exprt = temp;
    }
}

void parse_export(char **to_export)
{
    char **variable = NULL;
    char **valeur = NULL;
    int i;
    int j;
    
    i = 1;
    j = 0;
    variable = malloc(sizeof(char *) * (ft_tab_len(to_export) + 1));
    valeur = malloc(sizeof(char *) * (ft_tab_len(to_export) + 1));
    while (to_export[i])
    {
        if (last_is_equal(to_export[i]))
        {
            variable[j] = ft_strdup(to_export[i]);
            valeur[j] = "\"\"";
            update_export_list(variable[j], valeur[j], 1);
            update_env_list(variable[j], valeur[j], 1);
        }
        else if (!no_equal(to_export[i]))
        {
            variable[j] = "' '";
            valeur[j] = ft_strdup(to_export[i]);
            update_export_list(variable[j], valeur[j], 2);
        }
        else
        {
            variable[j] = before_equal(to_export[i]);
            valeur[j] = afther_equal(to_export[i]);
            update_export_list(variable[j], valeur[j], 3);
            update_env_list(variable[j], valeur[j], 3);
        }
        j++;
        i++;
    }
    // valeur[j] = NULL;
    //free(valeur);
    //free list fait bugger 
}

void do_export(t_jobs *job)
{
    if (ft_tab_len(job->cmd) == 1)
        print_exprt(ft_tab_len(g_state.exprt));
    if (ft_tab_len(job->cmd) > 1)
    {
        if (got_good_args(job->cmd))
            printf("Not a valid export\n");
        else 
            parse_export(job->cmd);
    }
}
