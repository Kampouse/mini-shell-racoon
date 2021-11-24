/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_analyzzzzer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:44:03 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/24 10:09:17 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// int check_cashtoken(t_dlist *link)
// {
//     int i;
//     int dolla_sign;

//     dolla_sign = 0;
//     i = 0;
//     if (!link->content)
//         return (-1);
//     while (link->content[i])
//     {
//         // if (link->content[i] == '$' && (!ft_isspace(link->content[i + 1])))
//         if (link->content[i] == '$' && (link->content[i + 1] >= '\t' && link->content[i + 1] <= '\r'))
//             dolla_sign++;
//         i++;
//     }
//     return (dolla_sign);
// }