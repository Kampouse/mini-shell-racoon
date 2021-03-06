/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:39:22 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/15 18:29:58 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "eval.h"
#include "fcntl.h"
#include "../minishell.h"
#include "../readline/readline.h"

int	skip_over(char *str)
{
	int	skiped;

	skiped = 0;
	while (until_this(&str[skiped], "\'\"") == 0)
		skiped++;
	return (skiped);
}

char	*quote_eval(char *str, int left, char *outcome, int type)
{
	const char	*duped = str;
	const int	skipped = skip_over((char*)duped + left);

	if (skipped > 0)
		outcome = lazy_join(outcome, ft_substr(duped, left, skipped));
	left += skipped;
	outcome = lazy_join(outcome, eval_noquote((char *)duped, &left, 0));
	if ((unsigned int)left < ft_strlen(duped))
		return (quote_eval((char *)duped, left, outcome, type));
	return (outcome);
}

void	free_this(char *line, char *outcome, char *no_nl, char *trimed)
{
	free(line);
	free(outcome);
	free(no_nl);
	free(trimed);
}

int	redir_poll(char *line, char *cmp)
{
	char	*outcome;
	char	*no_nl;
	char	*trimed;
	int		len;

	outcome = NULL;
	if (!line)
		return (1);
	outcome = eval_line(line, outcome, 0, 1);
	no_nl = ft_strtrim(outcome, "\n");
	trimed = ft_strtrim(cmp, " ");
	len = (int)ft_strlen(no_nl) - ft_strlen(trimed);
	if (ft_strncmp(no_nl, trimed, ft_strlen(no_nl)) == 0 && len == 0)
	{
		free_this(line, outcome, no_nl, trimed);
		return (0);
	}
	else
	{
		free(outcome);
		free(no_nl);
		free(trimed);
		return (1);
	}
}

void	eval_redir(t_jobs *job)
{
	t_redir	*temp;	
	char	*outcome;

	outcome = NULL;
	if (job->redir)
	{
		temp = job->redir;
		while (temp)
		{
			if (temp->type != 1 && job->status == 0)
				temp->eval = eval_line(temp->cmd, outcome, 0, 0);
			temp = temp->next;
		}
	}
}
