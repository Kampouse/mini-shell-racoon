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


}		s_jobs;


int redir_counter(t_dlist *redir);
char **redir_creator(t_dlist *redir,int len);
int  any_heredoc(char **lst);
int redirector(char **redirs);

int jobs(t_dlist *lst,s_jobs **output); 
int job_lsting(t_dlist *lst);

s_jobs	*last_jobs(s_jobs *currlist);
s_jobs	*ft_joblst(void *content);
s_jobs	*job_new_lst(char **cmd,char **redir);
void	jobs_addfront(s_jobs **currlist, s_jobs *newnode);
void	jobs_addback(s_jobs **currlist, s_jobs *node);
s_jobs	*node_job(char **cmd,char **redir);
#endif 
