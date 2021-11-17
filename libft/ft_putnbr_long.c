/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:53:21 by olabrecq          #+#    #+#             */
/*   Updated: 2021/08/03 14:14:16 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_long(long nb)
{
	static int	nb_bytes;
	int			nb_bytes_minus;

	nb_bytes_minus = 0;
	nb_bytes = 0;
	if (nb < 0)
	{
		nb_bytes_minus = ft_putchar_int('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_long(nb /10);
		nb %= 10;
	}
	nb_bytes += ft_putchar_int(nb + '0');
	return (nb_bytes + nb_bytes_minus);
}