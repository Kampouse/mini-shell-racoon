#ifndef EVAL_H
# define EVAL_H

#include "../jobs/jobs.h"
#include "../executing/executing.h"

char	*find_env(char **envp,char *str,int type);
char *lazy_join(char *first,char *second);
int until_this(char *str,char *this);
char *find_varutil(char *str,int **len,int until);
char *find_var(char *str,int *len);
void eval_redir(t_jobs *job);
int eval(t_jobs *jobs);
char *eval_line(char *str,char *output,int lon,int type);
void eval_cmds(t_jobs *job);
char *eval_noquote(char *str,int *append,int type);
void pre_val_redir(t_jobs *jobs);
char	*quote_eval(char *str, int left, char *outcome, int type);
int	redir_poll(char *line, char *cmp);
#endif 
