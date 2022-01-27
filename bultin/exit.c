/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:01:24 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/27 11:48:21 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void quit_shell(int type)
{
	if (!type)
		printf("exit\n");
	freelist(g_state.env);
	freelist(g_state.exprt);
	rl_clear_history();
	exit(g_state.output);
}

int check_arg(char *arg)
{
	int i;

	i = 0;
	while(arg[i])
		if (!ft_isdigit(arg[i++]))
			return (2);
	g_state.output = ft_atoi(arg);
	if (g_state.output > 255)
		g_state.output = ((ft_atoi(arg) % 255) - 1);
	return (g_state.output);
}

int	do_exit(char **exit_arg)
{
	int type;

	type = 0;
	if (ft_tab_len(exit_arg) > 2)
	{
		printf("exit\nmini-shell-recoon: exit: too many arguments\n");
		return (1);
	}
	else if (ft_tab_len(exit_arg) == 2)
	{
		if (check_arg(exit_arg[1]) == 2)
		{
			type = 1;
			g_state.output = 2;
			printf("exit\nmini-shell-recoon: %s: numeric argument required\n", exit_arg[1]);
		}
	}
	quit_shell(type);
	return (0);
}

