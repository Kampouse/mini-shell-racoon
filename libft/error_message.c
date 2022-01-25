/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 11:37:40 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/25 09:43:54 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//This function print your error message and return 1
int	error_message(char *error_message)
{
	printf("%s\n", error_message);
	return (1);
}
