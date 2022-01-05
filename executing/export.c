/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:44 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/04 22:54:57 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int got_good_args(char **cmd)
{
    int i;
    char *temp;

    i = 0;
    temp = NULL;
    while (cmd[i])
    {
        temp = cmd[i];
        //reguarde si les premiere lettre des cmd est un chiffre ou un =
        if ((ft_isdigit(temp[0])) || temp[0] == '=')
            return (1);
        //reguarde si = est seul ex: (a = b)
        else if (ft_strlen(temp) == 1 && temp[0] == '=')
            return (1);
        i++;
    }
    return (0);
}

//Cette fonction trie les bonne variable et valeur a ajouter a la liste export
void update_export_list(char *var, char *val, int type)
{
    char *new_exprt;

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
        g_state.exprt = add_to_list(new_exprt,g_state.exprt, 1);
    }
    free(val);
}

void parse_export(char **to_export)
{
    char **variable = NULL;
    char **valeur = NULL;
    int i;
    int j;
    
    i = 1;
    j = 0;
    while (to_export[i])
    {
        variable = malloc(sizeof(char *) * (ft_tab_len(to_export) + 1));
        valeur = malloc(sizeof(char *) * (ft_tab_len(to_export) + 1));
        if (last_is_equal(to_export[i]))
        {
            //pourrais mettre fontion update en char** return le list
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
        free(variable[j]);
        free(valeur[j]);
        j++;
        i++;
    }
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
