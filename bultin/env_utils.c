/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:24:06 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/10 21:05:12 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void swap_n_free(char *new, int type, int i)
{
	// char *temp;
	if (!type)
	{
		// temp = g_state.env[i];
		g_state.env = remove_of_list(g_state.env[i], g_state.env);
		g_state.env = add_to_list(new, g_state.env, 0);
		// free(new);
	}
	else
	{
		// temp = g_state.exprt[i];
		g_state.exprt = remove_of_list(g_state.exprt[i], g_state.exprt);
		g_state.exprt = add_to_list(new, g_state.exprt, 0);
		// free(new);
	}
	// free(temp);
}

int just_check(char *var)
{
	int i;

	i = 0;
	if (var[ft_strlen(var) - 1] == '=')
		return (0);
	while (g_state.exprt[i])
	{
		if (!ft_strncmp(var, g_state.exprt[i], ft_strlen(var)))
			return (1);
		i++;
	}
	return (0);
}
// This function check if its got the same variable into the env and export list
// if it is she swap it and retrun 1
int	check_var(char	*var, char *to_export, int type)
{
	int i;
	char *temp; //mettre dedans pour pas avoir de leak
	
	temp = var;
	if (var[ft_strlen(var) - 1] == '=')
		var = ft_strtrim(temp, "=");
	i = 0;
	if (!type)
	{
		while (g_state.env[i])//si il y a la variable a linterieur de la liste on change seulement si ya une = dans le news var
		{
			if (!ft_strncmp(var, g_state.env[i], ft_strlen(var)))
			{
				printf("found it\n");
				swap_n_free(to_export, 0, i);
				// free(temp);
				return (1);
			}
			i++;
		}
		i = 0;
	}
	else
	{
		while (g_state.exprt[i])
		{
			if (!ft_strncmp(var, g_state.exprt[i], ft_strlen(var)))
			{
				if (just_check(temp))
				{
					return (1);
				}
				printf("found it\n");
				printf("add %s at export list\n", to_export);
				swap_n_free(to_export, 1, i);
				free(var);
				return (1);
			}
			i++;
		}
	}
	return (0);
}