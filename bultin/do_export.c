/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:30:55 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/12 15:31:02 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
				return (little_export(job->cmd[i]));
			}
			else
				if (parse_export(job->cmd[i]))
					return (1);
		}
	}
	return (0);
}
