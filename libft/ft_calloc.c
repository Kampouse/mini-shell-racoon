/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:20:59 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/20 12:58:04 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	size *= count;
	b = (void *)malloc(size);
	if (b)
		ft_bzero(b, size);
	return (b);
}
