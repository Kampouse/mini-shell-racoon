/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:47:54 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/15 16:48:16 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/libft.h"

char	*ft_str3join(const char *first, const char *second, const char *third)
{
	char	*output;
	size_t	len;
	size_t	len2;
	size_t	len3;

	len = ft_strlen(first);
	len2 = ft_strlen(second);
	len3 = ft_strlen(third);
	output = malloc(sizeof(char) * (len + len2 + len3 + 1));
	if (output)
	{
		ft_memcpy(output, first, len);
		ft_memcpy(output + len, second, len2);
		ft_memcpy(output + len + len2, third, len3 + 1);
	}
	return (output);
}

/* search the path  and  return the path for the excutables */
char	*findpath(char **envp)
{
	int		inc;
	char	*path;
	int		found;

	path = NULL;
	inc = 0;
	found = 0;
	while (envp[inc])
	{
		if (ft_strncmp(envp[inc], "PATH=/", ft_strlen("PATH=/")) == 0)
		{
			found = 1;
			break ;
		}
		inc++;
	}
	if (found == 1)
	{
		path = envp[inc];
		path += ft_strlen("PATH=");
	}
	return (path);
}
