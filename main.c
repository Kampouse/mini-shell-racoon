/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:48:26 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/01 04:09:11 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signal.h"
#include "fcntl.h"

t_exec	g_state = {0};

int	main(int argc, char **argv, char **envp)
{

	int fd;

	create_env(envp);
	create_export(envp);
	g_state.stdin = dup(0);
	g_state.stdout = dup(1);
	//start_signal(0);
	if (argc > 3)
	{
		ft_putstr("Invalid number of arguments\n");
		exit (-1);
	}
	if (argc == 3 && ft_strncmp("-c", argv[1], ft_strlen("-c")) == 0)
	{
		fd = open("/tmp/here_docced", O_TRUNC | O_CREAT | O_RDWR, 0644);
		close(fd);
		quick_parser(argv[2]);
		freelist(g_state.env);
		freelist(g_state.exprt);
		unlink("/tmp/here_docced");
	}
	else
	{
		fd = open("/tmp/here_docced", O_TRUNC | O_CREAT | O_RDWR, 0644);
		close(fd);
		parsing();
	}
}
