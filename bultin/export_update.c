/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:54:49 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/12 15:07:48 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	got_good_args(char *cmd)
{
	int	i;

	i = 0;
	if (!ft_isalpha(cmd[i]) && cmd[i] != '_')
		return (1);
	while (cmd[++i] && cmd[i] != '=')
		if (!ft_isalnum(cmd[i]) && cmd[i] != '_')
			return (1);
	return (0);
}

void	create_export(char **envp)
{
	int	i;

	i = 0;
	g_state.exprt = alloc_tab(envp);
	while (envp[i])
	{
		g_state.exprt[i] = ft_strdup(envp[i]);
		i++;
	}
	ft_sort_tab(g_state.exprt);
}

char	*wrap_input(char *str)
{
	const char	*temp = ft_substr(str, 0, until_this(str, "=") + 1);
	const char	*tempb = ft_str3join("\"", str + until_this(str, "=") + 1, "\"");
	const char	*res = ft_strjoin((char *)temp, (char *)tempb);

	free((void *)temp);
	free((void *)tempb);
	return ((char *) res);
}

int	parse_export(char *to_export)
{
	char	*variable;
	char	*valeur;

	if (update_this(to_export, g_state.exprt) != 1 || update_this(to_export,
			g_state.env) != 1)
		return (0);
	if (!no_equal(to_export))
	{
		variable = ft_strdup("' '");
		valeur = ft_strdup(to_export);
		g_state.exprt = add_to_list(valeur, g_state.exprt, 1);
		if (g_state.exprt == NULL)
			return (1);
	}
	else
	{
		variable = before_equal(to_export);
		valeur = afther_equal(to_export);
		if (update_export_list(variable, valeur, 3) || \
		update_env_list(variable, valeur, 3))
			return (1);
	}
	free(variable);
	free(valeur);
	return (0);
}

int	is_in_env_assigned(char *str)
{
	int		inc;
	char	*temp;

	inc = 0;
	temp = NULL;
	inc = until_this(str, "=");
	if (inc < 0)
		return (-1);
	else
		temp = ft_substr(str, 0, inc);
	inc = 0;
	while (g_state.exprt[inc])
	{
		if (!ft_strncmp(temp, g_state.exprt[inc], ft_strlen(temp)))
		{
			free(temp);
			return (inc);
		}
		inc++;
	}
	free(temp);
	return (-1);
}
