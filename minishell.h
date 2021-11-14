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
    char            **env;
    t_export        *exported;
    int             stdin;
    int             stdout;
    unsigned int    output;
} t_exec;

extern t_exec g_state;







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
#endif 
