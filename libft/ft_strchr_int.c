/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:06:46 by olabrecq          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/25 10:03:23 by olabrecq         ###   ########.fr       */
=======
/*   Updated: 2022/01/25 10:06:30 by jemartel         ###   ########.fr       */
>>>>>>> 841ed453a723448ca54186e8b7e0ca29157e513a
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD

//Faut s'assurer que ch n'est pas position [0]
int     ft_strchr_int(const char *str, int ch)
=======
/*  verif  si le premier est pas un le chr */
int	ft_strchr_int(const char *str, int ch)
>>>>>>> 841ed453a723448ca54186e8b7e0ca29157e513a
{
	int	i;

	i = 0;
	while (str[i] != ch)
		i++;
	return (i);
}
