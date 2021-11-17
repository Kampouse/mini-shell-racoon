/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:06:06 by olabrecq          #+#    #+#             */
/*   Updated: 2021/05/17 18:42:15 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*cstr;

	if (!s || !f)
		return (NULL);
	cstr = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!cstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cstr[i] = (*f)(i, s[i]);
		i++;
	}
	cstr[i] = '\0';
	return (cstr);
}
