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


}		t_jobs;


int redir_counter(t_dlist *redir);
char **redir_creator(t_dlist *redir,int len);
int  any_heredoc(char **lst);
int redirector(char **redirs);

int jobs(t_dlist *lst,t_jobs **output); 
t_jobs *job_lsting(t_dlist *lst);
t_jobs	*last_jobs(t_jobs *currlist);
t_jobs	*ft_joblst(void *content);
t_jobs	*job_new_lst(char **cmd,char **redir);
void	jobs_addfront(t_jobs **currlist, t_jobs *newnode);
void	jobs_addback(t_jobs **currlist, t_jobs *node);
t_jobs	*node_job(char **cmd,char **redir);
t_dlist	*job_find_pipe(t_dlist *lst);
#endif 
