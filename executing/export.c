/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:44 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/28 01:59:19 by jemartel         ###   ########.fr       */
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

    if (type == 1)
    {
        new_exprt = ft_strjoin(var, val);
        g_state.exprt = add_to_list(new_exprt,g_state.exprt, 1);
        // jean="" = export et jean= = env
    }
    if (type == 2)
    {
        new_exprt = val;
        g_state.exprt = add_to_list(new_exprt,g_state.exprt, 1);
        // jean = export env xx
    }
    if (type == 3)
    {
        val = ft_str3join("\"", val, "\"");
        new_exprt = ft_strjoin(var, val);
        g_state.exprt = add_to_list(new_exprt,g_state.exprt, 1);
        // jean="oli" export jean=oli env
    }
}

void parse_export(t_jobs *job)
{
    char **variable = NULL;
    char **valeur = NULL;
    int i;
    int j;
    
    //i = 1 car 0 = cmd[0]= export
    i = 1;
    j = 0;
    variable = malloc(sizeof(char *) * ft_tab_len(job->cmd) + 1);
    valeur = malloc(sizeof(char *) * ft_tab_len(job->cmd) + 1);
    while (job->cmd[i])
    {
        if (last_is_equal(job->cmd[i]))
        {
            variable[j] = job->cmd[i];
            valeur[j] = "\"\"";
            update_export_list(variable[j], valeur[j], 1);
            update_env_list(variable[j], valeur[j], 1);
            //jean="" = export et jean= = env
            //type 1
        }
        else if (!no_equal(job->cmd[i]))
        {
            variable[j] = "' '";
            valeur[j] = job->cmd[i];
            update_export_list(variable[j], valeur[j], 2);
            //jean = export env xx
            //type 2
        }
        else
        {
            variable[j] = before_equal(job->cmd[i]);
            valeur[j] = afther_equal(job->cmd[i]);
            update_export_list(variable[j], valeur[j], 3);
            update_env_list(variable[j], valeur[j], 3);
            //jean="oli" export jean=oli env
            //type 3
        }
        j++;
        i++;
    }
    // freelist(variable);
    // freelist(valeur);
}

void do_export(t_jobs *job)
{
    if (ft_tab_len(job->cmd) == 1)
        print_exprt(ft_tab_len(g_state.exprt));
    if (ft_tab_len(job->cmd) > 1)
    {
        if (got_good_args(job))
            printf("Not a valid export\n");
        else 
            parse_export(job);
    }
}
