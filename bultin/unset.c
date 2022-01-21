/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:45:33 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/18 11:02:26 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Cette fonction parse la commande unset et retourne une liste des variable a "unset"
char **parse_unset(char **to_unset)
{
    int i;
    int j; 
    char **to_delete;// liste de variable a unset
    
    i = 1;
    j = 0;
    to_delete = malloc(sizeof(char *) * ft_tab_len(to_unset) + 1);
    if (!to_delete)
        return(NULL);
    while (to_unset[i])
    {
        //si la unset variable fini par '='
        if (to_unset[i][ft_strlen(to_unset[i]) - 1] == '=')
            printf("bash: unset: `%s': not a valid identifier\n", to_unset[i]);
        else
            to_delete[j++] = to_unset[i];
        i++;
    }
    to_delete[j] = NULL;
    return (to_delete);
}

int do_unset(t_jobs *job)
{
    char    **to_delete;
    int i;
    
    to_delete = parse_unset(job->cmd);
    if (!to_delete)
        return (error_message("Error malloc"));
    i = 0;
    if (!to_delete)
    {
        // free(to_delete); free inutile car todelete == NULL si malloc a chier
        return (1);
    }
    while (to_delete[i])
    {
		g_state.exprt = remove_of_list(to_delete[i], g_state.exprt);
        g_state.env = remove_of_list(to_delete[i], g_state.env);
        i++;
    }
	free(to_delete);
    return (0);
}
