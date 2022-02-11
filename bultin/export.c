/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:44 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/10 21:18:32 by olabrecq         ###   ########.fr       */
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

//Cette fonction trie les bonne variable et valeur a ajouter a la liste export
int	update_export_list(char *var, char *val, int type)
{
	char	*new_exprt;

	if (type == 1)
	{
		new_exprt = ft_strjoin(var, val);
		if (check_var(var, new_exprt, 1))
		{
			// free(new_exprt);
			return (0);
		}
		g_state.exprt = add_to_list(new_exprt, g_state.exprt, 1);
	}
	if (type == 3)
	{
		val = ft_str3join("\"", val, "\"");
		new_exprt = ft_strjoin(var, val);
		if (check_var(var, new_exprt, 1))
		{
			free(val);
			free(new_exprt);
			return (0);
		}
		g_state.exprt = add_to_list(new_exprt, g_state.exprt, 1);
		free(val);
	}
	if (g_state.exprt == NULL)
		return (1);
	free(new_exprt);
	return (0);
}

int	parse_export(char *to_export)
{
	char	*variable;
	char	*valeur;

	variable = NULL;
	valeur = NULL;
	if (!no_equal(to_export))
	{
		variable = ft_strdup("' '");
		valeur = ft_strdup(to_export);
		if (check_var(valeur, to_export, 1))
		{
			free(variable);
			free(valeur);
			return (0);
		}
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

int	do_export(t_jobs *job)
{
	int	i;

	if (ft_tab_len(job->cmd) == 1)
		print_exprt(ft_tab_len(g_state.exprt));
	if (ft_tab_len(job->cmd) > 1)
	{
		i = 0;
		while (job->cmd[++i])
		{
			if (got_good_args(job->cmd[i]))
				return (error_message("Not a valid export\n"));
			else if (last_is_equal(job->cmd[i]))
			{
				if (update_export_list(job->cmd[i], "\"\"", 1) || \
				update_env_list(job->cmd[i], "\"\"", 1))
					return (1);
			}
			else
				if (parse_export(job->cmd[i]))
					return (1);
		}
	}
	return (0);
}
