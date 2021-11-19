/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:55:42 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/18 19:27:50 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void create_var(char **envp)
// {
//     int i;
//     int j;

//     i = 0;
//     while (envp[i])
//     {
        
//         i++;
//     }
// }

// char	*find_var(char *var)
// {
// 	int		i;
// 	char	*path;
// 	char 	**tab_search  = g_state.env;

// 	path = var;
// 	i = 0;
// 	while (g_state.env[i])
// 	{
// 		if (path)
// 			break ;
// 		path = ft_strend(g_state.env[i], var);
// 		i++;
// 	}
// 	path += ft_strlen(var);
// 	return (path);
// }


void print_var(char *var)
{
	int i = 0;
	char *temp;
	char *ret;
	
	temp = ft_strchr(var, '$');
	ret = temp;
	while (g_state.env[i])
	{
		if (ret == ft_strnstr(g_state.env[i], temp, ft_strlen(g_state.env[i])))
		{
			ret = ft_strchr(g_state.env[i], '=');
			printf("%s\n", ret);
		}
		i++;
	}
}
