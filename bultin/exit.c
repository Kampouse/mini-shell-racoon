/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:01:24 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/26 11:33:54 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void quit_shell()
{
	freelist(g_state.env);
	freelist(g_state.exprt);
	rl_clear_history();
	printf("exit\n");
	exit(g_state.output);
}

int chek_arg(char **arg)
{
	int i;

	i = 0;
	if (arg[1])
	while (arg[i])
	{
		i++;

	}
	return (0);
}

int	do_exit(char **exit_arg)
{
	// int i;

	// i = 0;
	if (ft_tab_len(exit_arg) > 2)
		return (1);
	if (ft_tab_len(exit_arg) < 1)
	{
		
		if (chek_arg(exit_arg))
			return (1);
		
	}
	quit_shell();
	return (0);
}

