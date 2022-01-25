/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:06:46 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/25 14:23:06 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*  verif  si le premier est pas un le chr */
int	ft_strchr_int(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i] != ch)
		i++;
	return (i);
}
