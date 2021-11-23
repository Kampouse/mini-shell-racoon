/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:34:56 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/18 19:38:04 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		needle_len;

	needle_len = ft_strlen(needle);
	i = 0;
	if (!needle[i])
		return ((char *)needle);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (j == needle_len)
			return ((char *)&needle[i]);
		i++;
	}
	return (0);
}

// int main()
// {
// 	char *var = "PATH";
// 	char *env = "PATH=/Users/olabrecq/homebrew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Library/Apple/usr/bin:/Users/olabrecq/homebrew/bin";
	
// 	printf("%s\n", ft_strnstr(env, var, ft_strlen(env)));
// }
