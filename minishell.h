#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include "stdlib.h"
# include "stdio.h"
# include "readline/readline.h"
# include "libft/libft.h"
# include "readline/history.h"
# include <sys/types.h>
# include <dirent.h>

# define GREEN "\002\e[0;32m\002"
# define RESET   "\001\e[0m\002"

// typedef struct s_env
// {
//     char            *env_node;
//     struct s_env    *next;
// } t_env;

typedef struct s_export
{
    char            *export_node;
    struct s_export *next;
} t_export;

typedef struct s_exec
{
    t_export        *exprt;
    // t_env           *env;
    char            **env;
    int             stdin;
    int             stdout;
    unsigned int    output;
} t_exec;



typedef struct t_dlist
{
	void			*content;
	struct t_dlist	*next;
	struct t_dlist	*prev;
}		t_dlist;



extern t_exec g_state;

void create_env(char **envp);
void print_env(char **envp);
int type_string(char *str,size_t *len);
t_dlist	*ft_lst_lastnode(t_dlist *currlist);
t_dlist	*ft_lstnewl(void *content);
void	free_list(t_dlist *head);
void	ft_lst_add_backd(t_dlist **currlist, t_dlist *node);
// void create_env(char **envp);
// void print_env(t_exec g_state);

char	*ft_strend(char *base, char *to_find);
char	*ft_str3join(const char *first, const char *second, const char *third);
char	*findpath(char **environ);
char	freelist(char **list);
int path_resolver(char *path_bin, char **program_args, char **envp);
int		find_token(char *line, char *token);
int		exit_please(char **tokens,char *trimed);
int until_space(char *str);
int token_scanner(char *str);
int line_parser(char *trimed,char **environ);
int ft_isspace(char elm);
char *find_dquoted(char *str,size_t *len);
#endif 
