/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:44 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/12 15:31:05 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_in_env(char *str);
int	is_in_env_assigned(char *str);

//Cette fonction trie les bonne variable et valeur a ajouter a la liste export
int	replace_at(char *var, char *val, int type)
{
	int	location;

	location = 0;
	(void)val;
	(void)var;
	(void)type;
	if (is_in_env_assigned(var) >= 0)
	{
		location = is_in_env_assigned(var);
	}
	else if (is_in_env(var) >= 0)
	{
		location = is_in_env(var);
	}
	g_state.exprt[location] = ft_strdup(var);
	return (0);
}

int	update_export_list(char *var, char *val, int type)
{
	char		*new_exprt;
	const int	prev = is_in_env(var);
	const int	old = is_in_env_assigned(var);

	if (prev >= 0 || old >= 0)
		replace_at(var, val, type);
	if (type == 1)
	{
		new_exprt = ft_strjoin(var, val);
		g_state.exprt = add_to_list(new_exprt, g_state.exprt, 1);
	}
	if (type == 3)
	{
		val = ft_str3join("\"", val, "\"");
		new_exprt = ft_strjoin(var, val);
		g_state.exprt = add_to_list(new_exprt, g_state.exprt, 1);
		free(val);
	}
	if (g_state.exprt == NULL)
		return (1);
	free(new_exprt);
	return (0);
}

int	update_this(char *to_export, char **location)
{
	const int	prev = is_in_env(to_export);
	const int	old = is_in_env_assigned(to_export);

	if (prev >= 0 || old >= 0)
	{
		if (old >= 0)
		{
			free(location[old]);
			if (!last_is_equal(to_export))
				location[old] = wrap_input(to_export);
			else
				location[old] = ft_strjoin(to_export, "\"\"");
			return (0);
		}
		else if (prev >= 0)
		{
			if (ft_strchr(location[prev], '='))
				return (0);
			free(location[prev]);
			location[prev] = ft_strdup(to_export);
			return (0);
		}
	}
	return (1);
}

int	is_in_env(char *str)
{
	int	inc;

	inc = until_this(str, "=");
	if (inc < 0)
	{
		inc = 0;
		while (g_state.exprt[inc])
		{
			if ((ft_strncmp(str, g_state.exprt[inc], ft_strlen(str))) == 0)
				return (inc);
			inc++;
		}
	}
	return (-1);
}

int	little_export(char *str)
{
	if (is_in_env_assigned(str) < 0)
	{
		update_export_list(str, "\"\"", 1);
		update_env_list(str, "\"\"", 1);
		return (0);
	}
	else
		parse_export(str);
	return (1);
}
