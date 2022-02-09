/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:24:06 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/09 16:31:26 by olabrecq         ###   ########.fr       */
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
	while (g_state.env[i])//si il y a la variable a linterieur de la liste on change seulement si ya une = dans le news var
	{
		if (!ft_strncmp(var, g_state.env[i], ft_strlen(var)))
		{
			printf("Found it \n");	
			return (1);
		}
		i++;
	}
	// i = 0;
	// while (g_state.exprt[i])
	// {
	// 	if (!ft_strncmp(var, g_state.exprt[i], sizeof(var)))
	// 	{
	// 		printf("Found it \n");	
	// 		return (1);
	// 	}
	// 	i++;
	// }
	return (0);
}