/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:01:24 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/09 15:02:00 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	quit_shell(t_jobs *jobs, int type)
{
	if (!type)
		printf("exit\n");
	close(g_state.stdin);
	close(g_state.stdout);
	while (jobs->prev)
		jobs = jobs->prev;
	if (jobs->piped != NULL)
		delete_pipe(jobs->piped, 1);
	free_jobs(jobs, 0);
	freelist(g_state.env);
	freelist(g_state.exprt);
	rl_clear_history();
	unlink("/tmp/here_docced");
	exit(g_state.output);
}

int	check_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (2);
		i++;
	}
	g_state.output = ft_atoi(arg);
	if (g_state.output > 255)
		g_state.output = ((ft_atoi(arg) % 256));
	return (g_state.output);
}

int	do_exit(t_jobs *job)
{
	int	type;

	type = 0;
	if (ft_tab_len(job->eval) > 2)
	{
		printf("exit\nmini-shell-recoon: exit: too many arguments\n");
		return (1);
	}
	else if (ft_tab_len(job->eval) == 2)
	{
		if (check_arg(job->eval[1]) == 2 && ft_atoi(job->eval[1]) != 2)
		{
			type = 1;
			g_state.output = 2;
			printf("exit\nmini-shell-recoon: %s: numeric argument required\n", \
			job->eval[1]);
		}
	}
	quit_shell(job, type);
	return (0);
}
