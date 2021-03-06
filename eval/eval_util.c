/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:48:57 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/10 21:43:37 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "eval.h"
#include "../minishell.h"

/* return variable from env else NULL */
char	*find_env(char **envp, char *str, int type, int inc)
{
	char	*temp;

	if (!str)
		return (NULL);
	if (same_len(str, "$?") == 0 && ft_strncmp(str, "$?", ft_strlen(str)) == 0)
	{
		free(str);
		return (ft_itoa(g_state.output));
	}
	if (ft_strlen(str) == 1 && str[0] == '$')
		return (str);
	while (envp[++inc] != 0)
	{
		if (ft_strncmp(envp[inc], str + 1, ft_strlen(str + 1)) == 0 && *(envp
				[inc] + ft_strlen(str + 1)) == '=')
		{
			temp = ft_strdup(envp[inc] + ft_strlen(str + 1) + 1);
			free(str);
			return (temp);
		}
	}
	if (type == 1)
		return (str);
	free(str);
	return (NULL);
}

/* reinforce join so it can handle  NULL */
char	*lazy_join(char *first, char *second)
{
	char		*output;
	size_t		len;
	size_t		len2;

	if (!first && second)
	{
		output = ft_strdup(second);
		free(second);
		return (output);
	}
	if (!second)
		return (first);
	len = ft_strlen(first);
	len2 = ft_strlen(second);
	output = malloc(sizeof(char) * len + len2 + 1);
	if (output)
	{
		ft_memcpy(output, first, len);
		ft_memcpy(output + len, second, len2 + 1);
		free(first);
		free(second);
	}
	return (output);
}

/*  count how many  char it can read until a delimiter else return -1 */
int	until_this(char *str, char *this)
{
	int	inc;

	inc = -1;
	if (!str)
		return (-1);
	while (str[++inc])
	{
		if (ft_strchr(this, str[inc]))
			return (inc);
	}
	return (-1);
}

/*   extenion of  find_var*/
char	*find_varutil(char *str, int **len, int until)
{
	if (until < 0)
	{
		**len += until_this(str, "\"") + 1;
		return (ft_substr(str, 0, until_this(str, "\"")));
	}
	if (until > 0)
	{
		**len += until_this(str + 1, " $") + 1;
		return (ft_substr(str, 0, until_this(str + 1, " $") + 1));
	}
	return (NULL);
}

/* core of double quote  expension*/
char	*find_var(char *str, int *len)
{
	int		until;
	int		**temp;

	temp = &len;
	until = until_this(str, "$");
	if (until > 0 || until < 0)
		return (find_varutil(str, temp, until));
	if (until == 0 && until_this(str + 1, "$") != -1)
	{
		*len += until_this(str + 1, "$ ") + 1;
		return (ft_substr(str, 0, until_this(str + 1, "$ ") + 1));
	}
	if (until == 0 && until_this(str + 1, " $") != -1)
	{
		*len += until_this(str + 1, " \"$") + 1;
		return (ft_substr(str, 0, until_this(str + 1, " \"$") + 1));
	}
	else
	{
		*len += until_this(str + 1, " \'\"") + 1;
		return (ft_substr(str, 0, until_this(str + 1, " \'\"") + 1));
	}
	return (0);
}
