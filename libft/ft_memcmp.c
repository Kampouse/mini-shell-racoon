/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:22:02 by olabrecq          #+#    #+#             */
/*   Updated: 2021/05/17 18:42:01 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned char		*pstr1;
	unsigned char		*pstr2;

	pstr1 = (unsigned char *) s1;
	pstr2 = (unsigned char *) s2;
	i = 0 ;
	if (n == 0)
		return (0);
	while (pstr1[i] == pstr2[i] && i < n - 1)
		i++;
	return (pstr1[i] - pstr2[i]);
}
