/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 14:17:14 by olabrecq          #+#    #+#             */
/*   Updated: 2021/08/03 11:01:57 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str != ch)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *) str);
}

/* char				*ft_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (ch == *str)
			return ((char *)str);
		str++;
	}
	if (ch == '\0' && *str == '\0')
		return ((char *)str);
	return (NULL);
} */