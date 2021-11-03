/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:28:42 by jean-phil         #+#    #+#             */
/*   Updated: 2021/10/18 11:03:00 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*heler_src;
	unsigned char	*heler_dest;

	i = 0;
	if (!dest && !src)
		return (NULL);
	heler_src = (unsigned char *)src;
	heler_dest = (unsigned char *)dest;
	while (i < n)
	{
		heler_dest[i] = heler_src[i];
		i++;
	}
	return (dest);
}
