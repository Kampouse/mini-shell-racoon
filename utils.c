/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:54:17 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/21 08:53:04 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* should clean all the data structures left
 on the  heap also return a status?*/
/*
int	exit_please(char **tokens, char *trimed)
{
	if (trimed && tokens)
	{
		if (find_token(tokens[0], "exit"))
		{
			printf("exit\n");
			free(trimed);
			freelist(tokens);
			return (1);
		}
	}
	return (0);
}
*/
int	ft_isspace(char elm)
{
	if (!elm)
		return (0);
	if (elm == ' ' || elm == '\t')
		return (1);
	else if (elm == '\n' || elm == '\v' || elm == '\v' || elm == '\f' || elm == '\r')
		return (1);
	return (0);
}

int	until_space(char *str)
{
	int	inc;

	inc = 0;
	if (!str)
		return (-1);
	while (!ft_isspace(str[inc]) && str[inc])
	{
		inc++;
	}
	return (inc);
}

void	freelist(char **list)
{
	int	index;

	index = 0;
	if (list)
	{
		while (list[index])
		{
			if (list[index])
			{
				free((void *)list[index]);
			}
			index++;
		}
		free(list);
	}
}

// return la longueur d'un char** devrais s'appler list_len
int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

//Cette fonction trie un tableau de char en ordre ascii
char	**ft_sort_tab(char **tab)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strncmp(tab[i], tab[j], ft_strlen(tab[i])) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
