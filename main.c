/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:48:26 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/14 21:01:53 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signal.h"

t_exec	g_state = {0};

int	main(int argc, char **argv, char **envp)
{
	create_env(envp);
	create_export(envp);
	g_state.stdin = dup(0);
	g_state.stdout = dup(1);
	if (argc > 3)
	{
		ft_putstr("Invalid number of arguments\n");
		exit (-1);
	}
	if (argc == 3 && ft_strncmp("-c", argv[1], ft_strlen("-c")) == 0)
	{
		quick_parser(argv[2]);
		freelist(g_state.env);
		freelist(g_state.exprt);
	}
	else
		parsing();
}
