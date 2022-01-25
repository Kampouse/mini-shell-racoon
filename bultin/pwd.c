/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:55:44 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/25 11:06:22 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	do_pwd(char **args)
{
	char	cwd[4096];

	if (ft_tab_len(args) > 1)
		return (error_message("pwd: too many arguments\n"));
	else
	{
		if (!getcwd(cwd, sizeof(cwd)))
			return (1);
		printf("%s\n", cwd);
	}
	return (0);
}
