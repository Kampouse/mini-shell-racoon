/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:45:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/25 22:36:32 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Cette fonction parse la commande unset et retourne une liste des variable a "unset"
char **parse_unset(t_jobs *job)
{
    int i; 
    char **to_delete;// liste de variable a unset
    
    i = 1;
    to_delete = malloc(sizeof(job->cmd));
    while (job->cmd[i])
    {
        //si la unset variable fini par '='
        if (job->cmd[i][ft_strlen(job->cmd[i]) - 1] == '=')
            printf("bash: unset: `%s': not a valid identifier\n",job->cmd[i]);
        else
            to_delete[i - 1] = ft_strdup(job->cmd[i]);//i -1 car i commence a 1 car unset est cmd[0]
        i++;
    }
    return (to_delete);
}

void remove_from_list(char *to_remove, int type)
{
    char **new_list;
    int i;
    new_list = NULL;
    new_list = malloc(sizeof(char **) * (ft_tab_len(g_state.env) - ft_tab_len(&to_remove)));
    i = 0;
    if (type == 1)
    {
        while (g_state.exprt[i])
        {
            if (!ft_strncmp(g_state.exprt[i], to_remove, ft_strlen(to_remove)))
                i++;
            new_list[i] = ft_strdup(g_state.exprt[i]);
            i++;
        }
        g_state.exprt = new_list;
    }
    i = 0;
    if (type == 2)
    {
        while (g_state.env[i])
        {
            if (!ft_strncmp(g_state.env[i], to_remove, ft_strlen(to_remove)))
                i++;
            new_list[i] = ft_strdup(g_state.env[i]);
            i++;
        }
        g_state.env = new_list;
    }
}

//passer les liste env et epxport a la recherche de variable a delete
//stncmp de la len de la varible
void do_unset(t_jobs *job)
{
    int     i;
    int     j;
    char    **to_delete;
    
    // to_delete dois etre char ** car peu avoir plus qu'un a la fois
    // si to_delete fini par '=' : bash: unset: `jean=': not a valid identifier
    to_delete = parse_unset(job);
    i = 0;
    j = 0;
    while(to_delete[i])
    {   
        printf("to_delete = %s\n", to_delete[i]);
        
        while (g_state.env[j])
        {
            if (!ft_strncmp(g_state.env[j], to_delete[i], ft_strlen(to_delete[i])))
            {   
                printf("On supprime ca tabarnak!!! \n");
                remove_from_list(to_delete[i], 2);
            }
            j++;
        }
        j = 0;
        while (g_state.exprt[j])
        {
            if (!ft_strncmp(g_state.exprt[j], to_delete[i], ft_strlen(to_delete[i])))
            {
                printf("On supprime ca tabarnak!!! \n");
                remove_from_list(to_delete[i], 1);
            }
            j++;
        }
        i++;
    }
}

// void search_n_delete(char *var)
// {
    
// }