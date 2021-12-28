/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:18:35 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/27 12:49:09 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Cette fonction prend une commande et retourne char* de la variable ex: jean=
char *before_equal(char *var_cmd)
{
    int i;
    char *var_str = NULL;

    var_str = malloc(sizeof(char) * ft_strlen(var_cmd) + 1);
    i = 0;
    while (var_cmd[i] != '=')
        i++;
    var_str = ft_substr(var_cmd, 0, i + 1);
    return (var_str);
}

// doit checek si ny a pas de '='
char *afther_equal(char *val_cmd)
{
    int i;
    char *val_str = NULL;
    val_str = malloc(sizeof(char) * ft_strlen(val_cmd) + 1);
    i = 0;
    while (val_cmd[i] != '=')
        i++;
    val_str = ft_substr(val_cmd, (i + 1), (ft_strlen(val_cmd) - i));
    if (val_str == (void*)'\0')
        return("\"\"");
    return (val_str);
}

int no_equal(char *cmd)
{
    int i;

    i = 0;
    while (cmd[i])
    {
        if (cmd[i] == '=')
            return (1);
        i++;
    }
    return(0);
}

int last_is_equal(char *cmd)
{
    int i;
    int count;
    
    count= 0;
    i = 0;
    while (cmd[i])
    {
        if (cmd[i] == '=' && cmd[i + 1] != '\0')
            count++;
        if (cmd[i] == '=' && cmd[i + 1] == '\0' && !count)
            return(1);
        i++;
    }
    return (0);
}

int got_good_args(t_jobs *job)
{
    int i;
    char *temp;

    i = 0;
    temp = NULL;
    while (job->cmd[i])
    {
        temp = job->cmd[i];
        //reguarde si les premiere lettre des cmd est un chiffre ou un =
        if ((ft_isdigit(temp[0])) || temp[0] == '=')
            return (1);
        //reguarde si = est seul ex: (a = b)
        if (ft_strlen(temp) == 1 && temp[0] == '=')
            return (1);
        i++;
    }
    return (0);
}