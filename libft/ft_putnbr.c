/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:34:30 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/29 11:13:10 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void       ft_putnbr(int nb)
{
    unsigned int nombre;

    if (nb < 0)
    {
        ft_putchar('-');
        nombre = -nb;
    }
    else
        nombre = nb;
    if (nombre > 9)
    {
        ft_putnbr(nombre / 10);
        nombre %= 10;
    }
    ft_putchar(nombre + '0');
}
