/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:18:35 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/14 11:28:22 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Cette fonction prend une commande et retourne char* de la variable ex: jean=
char *before_equal(char *var_cmd)
{
    int i;
    char *var_str = NULL;

    var_str = malloc(sizeof(char) * ft_strlen(var_cmd));
    i = 0;
    while (var_cmd[i] != '=')
        i++;
    var_str = ft_substr(var_cmd, 0, i + 1);
    printf("variable = %s\n", var_str);
    return (var_str);
}

// doit checek si ny a pas de '='
char *afther_equal(char *val_cmd)
{
    int i;
    char *val_str = NULL;
    val_str = malloc(sizeof(char) * ft_strlen(val_cmd));
    i = 0;
    while (val_cmd[i] != '=')
        i++;
    val_str = ft_substr(val_cmd, (i + 1), (ft_strlen(val_cmd) - i));
    printf("valeur = %s\n", val_str);
    return (val_str);
}

// char *no_equal(char *cmd)
// {
    
// }