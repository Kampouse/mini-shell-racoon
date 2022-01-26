/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:05:32 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/25 10:17:30 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* this function take line and delete all separator,
* it return the width of the line minus all the separator 
* This function was made for the project ---> Fdf <---
*/

#include "libft.h"

int	width_counter(char *line, char separator)
{
	int		i;
	char	**number_in_lines;

	(void)separator;
	number_in_lines = ft_split(line, ' ');
	i = 0;
	while (number_in_lines[i])
		free(number_in_lines[i++]);
	free(number_in_lines);
	return (i);
}
