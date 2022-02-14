/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_eval.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:08:47 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/14 12:16:29 by jemartel         ###   ########.fr       */
/*   Updated: 2022/02/12 15:48:41 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"
#include "parsing.h"

char	*prompt_eval(void)
{
	char	*str;
	char	*out;
	int		inc;

	inc = 0;
	str = NULL;
	str = eval_line("$PWD", str, 0, 0);
	if (!str)
		str = ft_strdup("/minishell");
	inc = ft_strlen(str);
	inc--;
	while (str[inc] != '/')
		inc--;
	inc++;
	out = ft_strdup(&str[inc]);
	free(str);
	str = ft_strjoin(out, ":>");
	free(out);
	out = ft_str3join(GREEN, str, RESET);
	free(str);
	return (out);
}

char	*prompt(char **trimed)
{
	char	*line;
	char	*prompt;

	prompt = prompt_eval();
	line = readline(prompt);
	free(prompt);
	*trimed = ft_strtrim(line, "\n ");
	add_history(*trimed);
	free(line);
	return (*trimed);
}
