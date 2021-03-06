/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 08:47:19 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/14 12:07:51 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//  This function update the OLDPWD and PWD variable in the env & export list
int	update_path(char *old, char *new)
{
	char	*to_remove;

	to_remove = ft_strjoin("OLDPWD=", new);
	g_state.env = remove_of_list(to_remove, g_state.env);
	g_state.exprt = remove_of_list(to_remove, g_state.exprt);
	free(to_remove);
	to_remove = ft_strjoin("OLDPWD=", old);
	g_state.env = remove_of_list(to_remove, g_state.env);
	g_state.exprt = remove_of_list(to_remove, g_state.exprt);
	g_state.env = add_to_list(to_remove, g_state.env, 0);
	g_state.exprt = add_to_list(to_remove, g_state.exprt, 1);
	free(to_remove);
	to_remove = ft_strjoin("PWD=", old);
	g_state.env = remove_of_list(to_remove, g_state.env);
	g_state.exprt = remove_of_list(to_remove, g_state.exprt);
	free(to_remove);
	to_remove = ft_strjoin("PWD=", new);
	g_state.env = add_to_list(to_remove, g_state.env, 0);
	g_state.exprt = add_to_list(to_remove, g_state.exprt, 1);
	free(to_remove);
	if (g_state.env == NULL || g_state.exprt == NULL)
		return (1);
	return (0);
}

int	go_home(int i, bool found, char **line)
{
	char	pwd[4096];

	getcwd(pwd, sizeof(pwd));
	while (g_state.env[++i])
	{
		if (!ft_strncmp("HOME=", g_state.env[i], ft_strlen("HOME=")))
		{
			found = true;
			line = ft_split(g_state.env[i], '=');
			update_path(pwd, line[1]);
			if (line[1] && chdir(line[1]))
			{
				printf("minishell: cd to HOME FAILED\n");
				freelist(line);
				return (1);
			}
		}
	}
	if (!found)
	{
		error_message("minishell: cd: HOME not set\n");
		return (1);
	}
	freelist(line);
	return (0);
}

int	do_cd(char **args)
{
	char	cwd[4096];
	char	cwd2[4096];

	if (ft_tab_len(args) == 1)
	{
		if (go_home(-1, false, NULL))
			return (1);
		return (0);
	}
	if (ft_tab_len(args) > 2)
		error_message("cd: too many arguments\n");
	else
	{
		getcwd(cwd, sizeof(cwd));
		if (chdir(args[1]))
		{
			printf("cd: no such file or directory: %s\n", args[1]);
			return (2);
		}
		getcwd(cwd2, sizeof(cwd2));
		if (update_path(cwd, cwd2))
			return (1);
	}
	return (0);
}
