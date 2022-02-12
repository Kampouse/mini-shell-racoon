/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:55:52 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/12 15:29:10 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include "parsing/parsing.h"
# include "readline/readline.h"
# include "readline/history.h"
# include "jobs/jobs.h"
# include "executing/executing.h"
# include "eval/eval.h"
# include "libft/libft.h"
# define GREEN "\001\e[0;32m\002"
# define RESET   "\001\e[0m\002"
// Function
int			type_string(char *str, size_t *len);
char		*ft_strend(char *base, char *to_find);
char		*ft_str3join(const char *first, const char *second,
				const char *third);
char		*findpath(char **environ);
void		freelist(char **list);
int			path_resolver(t_jobs *job, t_dlist *lst, t_pipe *pipes);
int			find_token(char *line, char *token);
int			exit_please(char **tokens, char *trimed);
int			until_space(char *str);
t_dlist		*line_parser(char *trimed);
int			ft_isspace(char elm);
char		*find_dquoted(char *str, size_t *len);
void		ft_add_frontd(t_dlist **currlist, t_dlist *newnode);
void		ft_lst_add_backd(t_dlist **currlist, t_dlist *node);
t_dlist		*ft_lst_lastnode(t_dlist *currlist);
t_dlist		*ft_lstnewl(void *content);
t_dlist		*node_init(void *content, int type);
void		ft_clearnode(t_dlist *currlist, void (*del)(void *));
void		ft_cleart_dlist(t_dlist **currlist, void (*del)(void *));
t_dlist		*ft_lst_lastnode(t_dlist *currlist);
t_dlist		*ft_lst_firstnode(t_dlist *currlist);
t_dlist		*ft_lst_nextnode(t_dlist *currlist);
t_dlist		*ft_lstnewl(void *content);
void		free_list(t_dlist *head);
void		ft_lstdclear(t_dlist **lst, void (*del)(void*));
void		ft_lstonlyhead(t_dlist **lst);
void		free_nodes(t_dlist *head);
void		quick_parser(char *str);
int			same_len(char *str, char *str2);
void		start_job(t_jobs *job, t_dlist *lst, t_pipe *pipes);
void		delete_pipe(t_pipe *pipes, int should_delete);
int			pipe_handler(t_pipe *pipes);
void		start_signal(int type);
char		*find_part(char *first, char *str, int inc, size_t **len);
int			exec_the_bin(char *paths, t_jobs *job, t_dlist *lst, t_pipe *pipes);
char		*make_executable(t_jobs *job);
void		command_not_found(t_jobs *job);
int			is_file_exec(t_jobs *job);
void		command_not_found(t_jobs *job);
int			restore_signal(const int signum);
void		sig_cc(int signum);
void		sig_chi(int signum);
int			here_redir(void);
int			got_good_args(char *cmd);
void		create_export(char **envp);
int			parse_export(char *to_export);
char		*wrap_input(char *str);
int			do_export(t_jobs *job);
int			update_this(char *to_export, char **location);
int			update_export_list(char *var, char *val, int type);
int			is_in_env_assigned(char *str);
int			little_export(char *str);
#endif 
