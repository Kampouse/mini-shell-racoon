/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 22:49:52 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/25 09:52:04 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "../minishell.h"

int	minus_n(char *echo_arg)
{
	if (!ft_strncmp(echo_arg, "-n", (size_t)(sizeof(char) * 2)) && \
		ft_strlen(echo_arg) == 2)
		return (1);
	return (0);
}

int	do_echo(t_jobs *jobs)
{
	int	n;
	int	i;

	n = 0;
	i = 1;
	if (ft_tab_len(jobs->eval) > 1)
	{
		if (minus_n(jobs->eval[1]))
		{
			n++;
			i++;
		}
		while (jobs->eval[i])
		{
			if (jobs->eval[i + 1])
				printf("%s ", jobs->eval[i++]);
			else
				printf("%s", jobs->eval[i++]);
		}
	}
	else
		return (1);
	if (!n)
		printf("\n");
	return (0);
}
