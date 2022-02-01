/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:35:10 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/01 17:36:12 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../libft/libft.h"

void	sig_chi(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr("\n");
	}
}
