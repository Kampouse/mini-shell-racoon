/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:57:06 by olabrecq          #+#    #+#             */
/*   Updated: 2021/05/18 10:11:04 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chek_char_in_set(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*trimer;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && chek_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && chek_char_in_set(s1[end - 1], set))
		end--;
	trimer = malloc(sizeof(char) * (end - start + 1));
	if (!trimer)
		return (NULL);
	i = 0;
	while (start < end)
		trimer[i++] = s1[start++];
	trimer[i] = '\0';
	return (trimer);
}
