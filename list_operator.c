/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 02:42:10 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/22 21:31:38 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"
//Cette fonction ajoute un nouvelle element a la liste "export"
char	**add_to_list(char *new_exprt, char **old_list, int type)
{
	char		**new_list;
	int			i;

	new_list = NULL;
	new_list = malloc(sizeof(char *) * (ft_tab_len(old_list) + 2));
	i = 0;
	while (old_list[i])
	{
		new_list[i] = ft_strdup(old_list[i]);
		i++;
	}
	new_list[i] = ft_strdup(new_exprt);
	i++;
	new_list[i] = NULL;
	freelist(old_list);
	if (type)
		return (ft_sort_tab(new_list));
	return (new_list);
}

char	**remove_of_list(char *to_remove, char **old_list)
{
	char	**new_list;
	int		i;
	int		j;

	new_list = NULL;
	new_list = malloc(sizeof(char **) * (ft_tab_len(old_list) + 1));
	i = 0;
	j = 0;
	while (old_list[i])
	{
		if (!ft_strncmp(old_list[i], to_remove, ft_strlen(to_remove)))
		{
			i++;
		}
		else
		{
			new_list[j] = ft_strdup(old_list[i]);
			i++;
			j++;
		}
	}
	new_list[j] = NULL;
	freelist(old_list);
	return (new_list);
}
