#include "stdlib.h"
#include "../libft/libft.h"
#include "../parsing/parsing.h"
#ifndef JOB_H
# define JOB_H

int jobs(t_dlist *lst);
int redir_counter(t_dlist *redir);
char **redir_creator(t_dlist *redir,int len);
int  any_heredoc(char **lst);
int redirector(char **redirs);
#endif 
