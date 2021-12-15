#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include "libft/libft.h"
# include "readline/readline.h"
# include "readline/history.h"
# include "jobs/jobs.h"
# include "executing/executing.h"
// # include "eval/eval.h"
# include "parsing/parsing.h"

# define GREEN "\002\e[0;32m\002"
# define RESET   "\001\e[0m\002"


// Function
int		type_string(char *str,size_t *len);
char	*ft_strend(char *base, char *to_find);
char		*ft_str3join(const char *first, const char *second, const char *third);
char		*findpath(char **environ);
char		freelist(char **list);
int			path_resolver(char *path_bin, char **program_args, char **envp);
int			find_token(char *line, char *token);
int			exit_please(char **tokens,char *trimed);
int			until_space(char *str);
int 		token_scanner(char *str,size_t *token_size);
t_dlist		*line_parser(char *trimed);
int			ft_isspace(char elm);
char		*find_dquoted(char *str,size_t *len);

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

#endif 
