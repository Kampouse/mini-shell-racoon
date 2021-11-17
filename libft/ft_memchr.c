/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:15:37 by olabrecq          #+#    #+#             */
/*   Updated: 2021/05/17 14:31:26 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		*pstr;

	pstr = (unsigned char *) str;
	i = 0;
	while (i < n)
	{
		if (pstr[i] == (unsigned char)c)
			return (pstr + i);
		i++;
	}
	return (NULL);
}
