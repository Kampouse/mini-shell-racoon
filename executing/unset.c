/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:45:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/27 17:01:09 by jemartel         ###   ########.fr       */
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

void do_unset(t_jobs *job)
{
    int     i;
    int     j;
    char    **to_delete;
    
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
                remove_env(to_delete[i]);
            }
            j++;
        }
        i++;
    }
    i = 0;
    while(to_delete[i])
    {
        j = 0;
        while (g_state.exprt[j])
        {
            if (!ft_strncmp(g_state.exprt[j], to_delete[i], ft_strlen(to_delete[i])))
            {
                printf("On supprime ca tabarnak!!! \n");
                remove_export(to_delete[i]);
            }
            j++;
        }
        i++;
    }
}
