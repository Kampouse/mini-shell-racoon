/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:01:24 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/22 18:05:58 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

//exit return g_state_status
// exit 
//

void	tokens_peek(t_dlist *lst)
{
	t_dlist	*temp;

	temp = NULL;
	if (lst)
		temp = lst;
	// check seulement la premiere node te add free_jobs
	while (temp && temp->type != 4)
	{
		if (temp->type == 7)//&& temp->prev->type != 8
		{
			freelist(g_state.env);
			freelist(g_state.exprt);
			if (lst)
				free_list(lst);
			write(1, "exit\n", ft_strlen("exit\n"));
			exit(g_state.output);
		}
		temp = (t_dlist *)temp->next;
	}
}
