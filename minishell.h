#ifndef MINI_SHELL_H
# define  LIBFT_H
# include "stdlib.h"
# include "stdio.h"
# include "readline/readline.h"
# include "libft/libft.h"
# include "readline/history.h"
# include <sys/types.h>
# include <dirent.h>


char	*ft_strend(char *base, char *to_find);
char	*ft_str3join(const char *first, const char *second, const char *third);
char	*findpath(char **environ);
char	freelist(char **list);
int path_resolver(char *path_bin,char *program , char **env);
#endif 
