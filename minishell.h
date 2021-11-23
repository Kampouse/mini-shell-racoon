#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include "stdlib.h"
# include "stdio.h"
# include "readline/readline.h"
# include "libft/libft.h"
# include "readline/history.h"
# include <sys/types.h>
# include <dirent.h>
# include "./executing/executing.h"
# include "./parsing/parsing.h"
# define GREEN "\002\e[0;32m\002"
# define RESET   "\001\e[0m\002"

typedef struct t_dlist
{
	void			*content;
	struct t_dlist	*next;
	struct t_dlist	*prev;
}		t_dlist;


// Function
int		type_string(char *str,size_t *len);
char	*ft_strend(char *base, char *to_find);
char	*ft_str3join(const char *first, const char *second, const char *third);
char	*findpath(char **environ);
char	freelist(char **list);
int		path_resolver(char *path_bin, char **program_args, char **envp);
int		find_token(char *line, char *token);
int		exit_please(char **tokens,char *trimed);
int		until_space(char *str);
int token_scanner(char *str,size_t *token_size);
int		line_parser(char *trimed,char **environ);
int		ft_isspace(char elm);
char	*find_dquoted(char *str,size_t *len);

void	ft_add_frontd(t_dlist **currlist, t_dlist *newnode);
void	ft_lst_add_backd(t_dlist **currlist, t_dlist *node);
t_dlist	*ft_lst_lastnode(t_dlist *currlist);
t_dlist	*ft_lstnewl(void *content);
t_dlist	*node_init(void *content);
void	ft_clearnode(t_dlist *currlist, void (*del)(void *));
void	ft_cleart_dlist(t_dlist **currlist, void (*del)(void *));
t_dlist	*ft_lst_lastnode(t_dlist *currlist);
t_dlist	*ft_lst_firstnode(t_dlist *currlist);
t_dlist	*ft_lst_nextnode(t_dlist *currlist);
t_dlist	*ft_lstnewl(void *content);
void	free_list(t_dlist *head);
void	ft_lstdclear(t_dlist **lst, void (*del)(void*));
t_dlist	*node_init(void *content);


#endif 
