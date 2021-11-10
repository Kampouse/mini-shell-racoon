/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:50:06 by jemartel          #+#    #+#             */
/*   Updated: 2021/11/10 10:09:22 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*ft_strend(char *base, char *to_find)
{
	char	*basecp;
	char	*looking;
	char	*ptr;

	basecp = base;
	looking = to_find;
	if (*to_find == 0)
		return (base);
	while (*basecp != '\0')
	{
		if (*to_find == '\0')
			return (basecp);
		ptr = basecp;
		while (*looking == *basecp && *looking != '\0')
		{
			looking++;
			basecp++;
		}
		if (*looking == '\0')
			return (ptr);
		basecp++;
	}
	return (0);
}

char	*ft_str3join(const char *first, const char *second, const char *third)
{
	char	*output;
	size_t	len;
	size_t	len2;
	size_t	len3;

	len = ft_strlen(first);
	len2 = ft_strlen(second);
	len2 = ft_strlen(second);
	len3 = ft_strlen(third);
	output = malloc(sizeof(char) * len + len2 + len3 + 1);
	if (output)
	{
		ft_memcpy(output, first, len);
		ft_memcpy(output + len, second, len2);
		ft_memcpy(output + len + len2, third, len3 + 1);
	}
	return (output);
}

/* search the path  and  return the path for the excutables */
char	*findpath(char **environ)
{
	int		i;
	char	*path;

	path = NULL;
	i = 0;
	while (environ[i])
	{
		if (path)
			break ;
		path = ft_strend(environ[i], "PATH=/");
		i++;
	}
	path += ft_strlen("PATH=");
	return (path);
}
