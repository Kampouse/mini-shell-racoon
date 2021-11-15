/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-phil <jemartel@student.42quebec>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:45:18 by jean-phil         #+#    #+#             */
/*   Updated: 2021/11/15 11:07:07 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin( char *first, char *second)
{
	char		*output;
	size_t		len;
	size_t		len2;

	if(!first)
		return(ft_strdup(second));
	if(!second)
		return(NULL);
	len = ft_strlen(first);
	len2 = ft_strlen(second);
	output = malloc(sizeof(char) * len + len2 + 1);
	if (output)
	{
		ft_memcpy(output, first, len);
		ft_memcpy(output + len, second, len2 + 1);
	}
	return (output);
}	
