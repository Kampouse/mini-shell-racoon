/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:18:35 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/25 11:00:58 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Cette fonction prend une commande et retourne char* de la variable ex: jean=
char	*before_equal(char *var_cmd)
{
	int		i;
	char	*var_str;

	var_str = NULL;
	i = 0;
	while (var_cmd[i] != '=')
		i++;
	var_str = ft_substr(var_cmd, 0, i + 1);
	return (var_str);
}

// doit checek si ny a pas de '='
char	*afther_equal(char *val_cmd)
{
	int		i;
	char	*val_str;

	val_str = NULL;
	i = 0;
	while (val_cmd[i] != '=')
		i++;
	val_str = ft_substr(val_cmd, (i + 1), (ft_strlen(val_cmd) - i));
	if (val_str == (void *) '\0')
		return ("\"\"");
	return (val_str);
}

int	no_equal(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	print_exprt(int tab_len)
{
	int	i;

	i = 0;
	while (i < tab_len)
		printf("%s\n", g_state.exprt[i++]);
}

int	last_is_equal(char *cmd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '=' && cmd[i + 1] != '\0')
			count++;
		if (cmd[i] == '=' && cmd[i + 1] == '\0' && !count)
			return (1);
		i++;
	}
	return (0);
}
