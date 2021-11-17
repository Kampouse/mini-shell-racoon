/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:05:32 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/15 09:16:58 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* this function take line and delete all separator,
* it return the width of the line minus all the separator 
* This function was made for the project ---> Fdf <---
*/

#include "libft.h"

// void check_hexa(char *line)
// {
//     int i = 0;
//     int j = 0;

//     if (line[i] == ',')
//         {    
//             j = i;
//             while (line[j] != ' ')
//                 j++;
//             i = j;
//             //width++;
//         }
// }

// int width_counter(char *line, char separator)
// {
//     int i;
//     //int j;
//     int width;

//     width = 0;
//     i = 0;
//     while (line[i])
//     {
//         check_hexa(line);

//         if (line[i] == '-')
//             i++;
//         if (line[i] != separator && line[i - 1] == separator)
//         {
//             width++;
//             i++;
//         }
//         else
//             i++;
//     }
//     return (width);
// }

int width_counter(char *line, char separator)
{
    int i;
    char **number_in_lines;
    
    (void)separator;
    number_in_lines = ft_split(line, ' ');
    i = 0;
    while (number_in_lines[i])
        free(number_in_lines[i++]);
    free(number_in_lines);
    return (i);    
}