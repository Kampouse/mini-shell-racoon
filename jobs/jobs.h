#include "stdlib.h"
#include "../libft/libft.h"
#include "../parsing/parsing.h"
#ifndef JOB_H
# define JOB_H

typedef struct s_jobs
{
    char    **cmd;
    char    *hereduc;
    char    **redir;
    int     pipe[2];
    int     stdin;
    int     stdout;
	struct s_jobs  *next;
	struct s_jobs  *prev;
} t_jobs;

int redir_counter(t_dlist *redir);
char **redir_creator(t_dlist *redir,int len);
int  any_heredoc(char **lst);
int redirector(char **redirs);
int jobs(t_dlist *lst);
int job_lsting(t_dlist *lst);
#endif 
