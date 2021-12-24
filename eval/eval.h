#include "../jobs/jobs.h"
#include "../executing/executing.h"
# ifndef EVAL_H
# define EVAL_H


char	*find_env(char **envp,char *str);
char *lazy_join(char *first,char *second);
int until_this(char *str,char *this);
char *find_varutil(char *str,int **len,int until);
char *find_var(char *str,int *len);
void eval_redir(t_jobs *job);
int eval(t_jobs *jobs,t_exec *g_state);
char *eval_line(char *str,char *output,int lon,int type);
void eval_cmds(t_jobs *job);
#endif 
