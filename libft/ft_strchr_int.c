/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:06:46 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/25 10:03:23 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Faut s'assurer que ch n'est pas position [0]
int     ft_strchr_int(const char *str, int ch)
{
    int i;

    i = 0;
	while (str[i] != ch)
		i++;
	return (i);
}