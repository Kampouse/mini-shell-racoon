/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:04:34 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/25 10:10:13 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *str1, const char *str2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!n)
		return (0);
	while ((unsigned char)str1[i]
		&& (unsigned char)str1[i] == (unsigned char)str2[i] && i < n - 1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
