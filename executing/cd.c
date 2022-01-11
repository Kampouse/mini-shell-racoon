/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 08:47:19 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/10 21:00:15 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//  This function update the OLDPWD and PWD variable in the env & export list
int    update_path(char *old, char *new)
{
    char *to_remove;
    
    to_remove = ft_strjoin("OLDPWD=", new);
    g_state.env = remove_of_list(to_remove, g_state.env);
    g_state.exprt = remove_of_list(to_remove, g_state.exprt);
    free(to_remove);
    to_remove = ft_strjoin("OLDPWD=", old);
    g_state.env = remove_of_list(to_remove, g_state.env);
    g_state.exprt = remove_of_list(to_remove, g_state.exprt);
    g_state.env = add_to_list(to_remove, g_state.env, 0);
    g_state.exprt = add_to_list(to_remove, g_state.exprt, 1);
    free(to_remove);
    to_remove =  ft_strjoin("PWD=", old);
    g_state.env = remove_of_list(to_remove, g_state.env);
    g_state.exprt = remove_of_list(to_remove, g_state.exprt);
    free(to_remove);
    to_remove =  ft_strjoin("PWD=", new);
    g_state.env = add_to_list(to_remove, g_state.env, 0);
    g_state.exprt = add_to_list(to_remove, g_state.exprt, 1);
    free(to_remove);
    
    return (0);
}

int do_cd(char **args)  
{
    char cwd[4096];
    char cwd2[4096];

    if (ft_tab_len(args) > 2)
    {
        printf("cd: too many arguments\n");
		return  (1);
    }
    else
    {
        getcwd(cwd, sizeof(cwd));
        if (chdir(args[1]))
        {
            printf("cd: no such file or directory: %s\n", args[1]);
            return (1);
        }
        getcwd(cwd2, sizeof(cwd2));
        if (update_path(cwd, cwd2))
            return(1);
    }
    return (0);
}