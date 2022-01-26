/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:17:06 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/26 12:25:56 by olabrecq         ###   ########.fr       */
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
		if (!ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}
