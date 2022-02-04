/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:38:44 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/04 17:47:53 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <signal.h>

typedef struct s_dlist
{
	char			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
	int				type;
	size_t			len;
}		t_dlist;

void		 igntion_seq(void);
void		tokens_peek(t_dlist *lst);
char		*token_builder(char *str);
char		*find_single(char *str, size_t *len);
char		*find_dquoted(char *str, size_t *len);
char		*find_partner(char *str, size_t *len);
char		*line_no_string(char *str, size_t *len);
t_dlist		*parser(char *str);
char		*token_loop(char *result, char *str, size_t len, size_t offset);
int			token_bool(char *str, size_t *len);
int			is_quoted(char *str);
int			token_valid(char **tokens, char *trimed, int type);
int			token_scanner(char *str, size_t *token_size, int inc);
int			redir_counter(t_dlist *redir);
void		sig_c(int signum, siginfo_t *info, void *unsed);
void		sig_child(int signum, siginfo_t *info, void *unsed);
void		sig_docc(int signum, siginfo_t *info, void *unsed);
void		start_signal(int type);
char		*prompt_eval(void);
char		*prompt(char **trimed);
void		sig_chi(int signum);
#endif
