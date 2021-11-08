/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:29:29 by jemartel          #+#    #+#             */
/*   Updated: 2021/11/07 17:19:01 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/* should clean all the data structures left
 on the  heap also return a status?*/

int	exit_please(char **tokens, char *trimed)
{
	if (trimed && tokens)
	{
		if (find_token(tokens[0], "exit"))
		{
			printf("exit\n");
			free(trimed);
			freelist(tokens);
			return (1);
		}
	}
	return (0);
}

char	freelist(char **list)
{
	int	index;

	index = 0;
	while (list[index])
	{
		free((void *) list[index]);
		index++;
	}
	free(list);
	return (0);
}
