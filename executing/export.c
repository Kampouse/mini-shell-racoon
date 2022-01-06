/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:44 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/06 11:06:58 by olabrecq         ###   ########.fr       */
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

char *add_dquote(char *old)
{
    char **var_val;
    char *var;
    char *val;
    
    var_val =  ft_split(old, '=');
    var = ft_strjoin(var_val[0], "=\"");
    val =  ft_strjoin(var_val[1], "\"");
    freelist(var_val);
    return(ft_strjoin(var, val));
}

void parse_export(char *to_export)
{
    g_state.env = add_to_list(to_export, g_state.env, 0);
    if(last_is_equal(to_export))
        g_state.exprt = add_to_list(ft_strjoin(to_export, "\"\""), g_state.exprt, 1);
    else
    {
        to_export = add_dquote(to_export);
        g_state.exprt =  add_to_list(to_export, g_state.exprt, 1);
    }
}

void do_export(char **args)
{
    int i ;
    
    if (ft_tab_len(args) == 1)
        print_exprt(ft_tab_len(g_state.exprt));
    if (ft_tab_len(args) > 1)
    {
        i = 0;
        while (args[++i])
        {    
            printf("args = %s\n", args[i]);
            if (got_good_args(args[i]))
                printf("Not a valid export\n");
            else
            {
                if (!got_good_args(args[i]) && no_equal(args[i]))
                    parse_export(args[i]);
                if (!got_good_args(args[i]) && !no_equal(args[i]))
                    g_state.exprt = add_to_list(args[i], g_state.exprt, 1);
            }
        }
    }
}
