/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 09:29:30 by olabrecq          #+#    #+#             */
/*   Updated: 2021/08/12 09:44:59 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_of_lines(char const *s1, char c)
{
	int	lines;
	int	comp;

	lines = 0;
	comp = 0;
	if (!*s1)
		return (0);
	while (*s1)
	{
		if (*s1 == c)
			comp = 0;
		else if (comp == 0)
		{
			comp = 1;
			lines++;
		}
		s1++;
	}
	return (lines);
}

int	ft_num_of_chars(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i])
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**ft_array(char const *s, char **dst, char c, int l)
{
	int	i;
	int	y;
	int	k;

	i = 0;
	y = 0;
	while (s[i] && y < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[y] = malloc(sizeof(char) * ft_num_of_chars(s, c, i) + 1);
		if (!dst[y])
			return (NULL);
		while (s[i] && s[i] != c)
			dst[y][k++] = s[i++];
		dst[y][k] = '\0';
		y++;
	}
	dst[y] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		n;

	if (s == NULL)
		return (NULL);
	n = ft_num_of_lines(s, c);
	dst = (char **)malloc(sizeof(char *) * (n + 1));
	if (!dst)
		return (NULL);
	return (ft_array(s, dst, c, n));
}
