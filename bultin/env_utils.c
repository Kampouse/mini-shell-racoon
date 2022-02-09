/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:24:06 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/09 16:08:40 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int ft_strcmp(char *str1, char *str2)
// {
	
// }

int	check_var(char	*var)
{
	printf("var = %s\n", var);
	int i;

	i = 0;
	while (g_state.env[i])
	{
		if (!ft_strncmp(g_state.env[i], var, ft_strlen(var)))
		{
			printf("Found it \n");	
			return (1);
		}
		i++;
	}
	i = 0;
	while (g_state.exprt[i])
	{
		if (!ft_strncmp(g_state.exprt[i], var, sizeof(var)))
		{
			printf("Found it \n");	
			return (1);
		}
		i++;
	}
	return (0);
}