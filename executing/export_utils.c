/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:18:35 by olabrecq          #+#    #+#             */
/*   Updated: 2021/12/13 16:15:59 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *before_equal(char *var_cmd)
{
    int i;
    char *var_str = NULL;

    var_str = malloc(sizeof(var_cmd));
    i = 0;
    while (var_cmd[i] != '=')
        i++;
    var_str = ft_substr(var_cmd, 0, i + 1);
    printf("%s\n", var_str);
    return (var_str);
}

char *afther_equal(char *val_cmd)
{
    //Reste a trouver comment prend tout ce qui a apres le equal sign
}