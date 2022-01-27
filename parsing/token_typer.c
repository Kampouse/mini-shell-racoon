/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_typer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:48:33 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/27 13:50:13 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	token_scanner_ext(const char *trimed, size_t *token_size, int inc)
{
	const char	*tokens[13] = {">>", "<<", "<", ">", "|", "env", "export",
		"exit", "echo", "unset", "pwd", "cd", NULL};

	if (ft_strncmp(trimed, (char *)tokens[inc], ft_strlen(tokens[inc])) == 0)
	{
		if (ft_strlen(trimed) == ft_strlen(tokens[inc]))
		{
			*token_size = ft_strlen(trimed);
			return (inc);
		}
	}
	return (-2);
}

int	token_scanner(char *str, size_t *token_size, int inc)
{
	const char	*trimed = ft_substr(str, 0, until_space(str));
	const char	*tokens[13] = {">>", "<<", "<", ">", "|", "env", "export",
		"exit", "echo", "unset", "pwd", "cd", NULL};

	if (!str)
		return (-1);
	while (tokens[++inc])
	{
		if (inc <= 4 && ft_strncmp(trimed, (char *)tokens[inc],
				ft_strlen(tokens[inc])) == 0)
		{
			free((char *) trimed);
			*token_size = ft_strlen(tokens[inc]);
			return (inc);
		}
		else if (token_scanner_ext(trimed, token_size, inc) != -2)
		{
			*token_size = ft_strlen(trimed);
			free((char *) trimed);
			return (inc);
		}
	}
	*token_size = 0;
	free((char *) trimed);
	return (-2);
}
