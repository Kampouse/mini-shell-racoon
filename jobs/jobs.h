#include "stdlib.h"
#include "../libft/libft.h"
#include "../parsing/parsing.h"
#ifndef JOB_H
# define JOB_H

//chaque node est quand il y a pipe | 
// export type = 6
// env type  = 5 
// unset type  = 9
typedef struct s_redir
{
    char    *cmd;
    char    *eval;
    int     type;
    int     here_status;
	struct s_redir  *next;
	struct s_redir  *prev;

}		t_redir;

typedef struct s_jobs
{
    t_dlist    *lst;
    char    **cmd;
    char    **eval;
    char    *hereduc;
	struct  s_redir    *redir;
    int     pipe[2];
    int     cmd_type;
    int     status;
    int     stdin;
    int     stdout;
	struct s_jobs  *next;
	struct s_jobs  *prev;

}	t_jobs;

int redir_counter(t_dlist *redir);
t_redir *redir_creator(t_dlist *redir, int *status);
int  any_heredoc(char **lst);
int redirector(char **redirs);

int jobs(t_dlist *lst,t_jobs **output); 
t_jobs *job_lsting(t_dlist *lst);
t_jobs	*last_jobs(t_jobs *currlist);
t_jobs	*ft_joblst(void *content);
void	jobs_addfront(t_jobs **currlist, t_jobs *newnode);
void	jobs_addback(t_jobs **currlist, t_jobs *node);
int jobs_lst_counter(t_dlist *lst);
char **jobs_lst_creator(t_dlist *lst,t_dlist **lst_head);
t_jobs	*node_job(char **cmd);
t_dlist	*job_find_pipe(t_dlist *lst);
t_jobs	*job_new_lst(char **cmd,t_redir *redir,t_dlist *cmd_head);
t_redir	*node_redir(char *cmd,int type);
void	redir_addback(t_redir **currlist, t_redir *node);
void	free_jobs(t_jobs *head,int type);
void	free_redir(t_redir *head);

#endif 
