/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_jobs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:51:53 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/04 17:48:54 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "../minishell.h"

/* there should be function  that deal with seperator separatly */
char	*until_separator(char *str)
{
	int		inc;
	char	*created;
	size_t	len;
	char	*result;

	result = NULL;
	len = 0;
	inc = 0;
	if (str)
		inc = is_quoted(str);
	else
		return (NULL);
	created = ft_substr(str, 0, inc);
	result = token_loop(result, created, len, 0);
	free(created);
	return (result);
}

char	*separtor_token(char *str, int *type)
{
	size_t	len;

	len = 0;
	*type = token_scanner(str, &len, -1);
	if (len > 0)
		return (ft_substr(str, 0, len));
	return (0);
}

/* determine when it should stop going forward when is see a  space*/
int	handle_space(char *trimed)
{
	int	inc;

	inc = 0;
	if (!trimed)
		return (-1);
	while (trimed[inc])
	{
		if (!ft_isspace(trimed[inc]))
			break ;
		inc++;
	}
	return (inc);
}

/* create the list of token and wrap in into a linked list */
void	tokens_lst(char *trimed, size_t total_len, t_dlist **token_lst)
{
	char		*output;
	int			type;
	size_t		len;
	const int	offset = handle_space(trimed);

	type = -2;
	output = separtor_token(trimed + offset, &type);
	if (!output && type == -2)
		output = until_separator(trimed + offset);
	if (!output)
	{
		free_list(ft_lst_firstnode(*token_lst));
		*token_lst = NULL;
		return ;
	}
	ft_lst_add_backd(token_lst, node_init(output, type));
	len = ft_strlen(output);
	if (len == 0 && type > 0)
		len++;
	total_len -= (len + offset);
	if (total_len == 0)
		return ;
	else
		tokens_lst(trimed + len + offset, total_len, token_lst);
	return ;
}

/* created  a list of token from a   string  (wrapped function)*/
t_dlist	*parser(char *trimed)
{
	t_dlist	*lst;

	lst = NULL;
	if (!trimed)
		return (NULL);
	tokens_lst(trimed, ft_strlen(trimed), &lst);
	free(trimed);
	return (lst);
}
