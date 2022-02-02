/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:17:06 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/01 20:55:03 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h" 

// This function check is the string is compose of letter  
int	ft_isalpha_word(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
			i++;
		else if ((str[i] >= 'a' && str[i] <= 'z' ))
				i++;
		else
			return (1);
	}
	return (0);
}
