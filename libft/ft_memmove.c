/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:45:34 by olabrecq          #+#    #+#             */
/*   Updated: 2021/05/28 12:09:14 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	if (dest == src)
		return (dest);
	if (csrc < cdest)
	{
		while (n--)
			*(cdest + n) = *(csrc + n);
		return (dest);
	}
	while (n--)
		*cdest++ = *csrc++;
	return (dest);
}
