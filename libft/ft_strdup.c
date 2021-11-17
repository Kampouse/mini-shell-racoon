/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:19:26 by olabrecq          #+#    #+#             */
/*   Updated: 2021/08/03 11:03:26 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static char 	*my_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*cdest;
	char			*csrc;

	cdest = (char *) dest;
	csrc = (char *) src;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(src) + 1;
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (0);
	dest = my_memcpy(dest, src, len);
	return (dest);
} */

char				*ft_strdup(const char *s1)
{
	char			*s2;
	size_t			l;
	unsigned int	i;

	l = ft_strlen(s1);
	s2 = (char *)malloc(l + 1);
	i = 0;
	if (s2)
	{
		while (s1[i] != '\0' && i < l)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	else
		return (0);
	return (s2);
}