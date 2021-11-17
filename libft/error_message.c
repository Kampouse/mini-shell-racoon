/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:37:40 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/13 14:02:40 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
* CODE ERROR
* 1 = invalid map
* 2 =  nb dargument invalide
* 3 =  general error
*/

void	error_message(int code_error)
{
	if (code_error == 1)
		ft_putstr_fd("Map invalid\n", 2);
	if (code_error == 2)
		ft_putstr("Number of arguments invalid\n");
	if (code_error == 3)
		ft_putstr("Error\n");
	if (code_error == 4)
		ft_putstr("Fd invalid\n");
	if (code_error == 5)
		ft_putstr("Close error\n");
	exit(EXIT_FAILURE);
}
