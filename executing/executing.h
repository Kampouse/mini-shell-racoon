#ifndef EXECUTING_H
# define EXECUTING_H

#include "../jobs/jobs.h"
#include <stdbool.h>

typedef struct s_exec
{
    char            ** exprt;
    char            **env;
    int             stdin;
    int             stdout;
    unsigned int    output;
} t_exec;

extern t_exec g_state;

// ENV
int     do_env(t_jobs *job);
void    create_env(char **envp);
// void    print_env(int tab_len);

//EXPORT
void    create_export(char **envp);
void    print_exprt(int tab_len);
void    do_export(t_jobs *jobb);


//PWD
int	do_pwd(char **args);
int do_cd(char **args);

// UTILS FUNCTION
char    **alloc_tab(char **old_tab);
int     ft_tab_len(char **tab);
char **add_to_list(char *new_exprt, char **old_list, int type);
char    **ft_sort_tab(char **tab);
char    *print_var(char *var);
int    check_bultin(t_jobs *jobb);
//EXPORT UTILS
char    *before_equal(char *var_cmd);
char    *afther_equal(char *val_cmd);
int     got_good_args(char *cmd);
int no_equal(char *cmd);
int last_is_equal(char *cmd);
//ENV UTILS
void update_env_list(char *var, char *val, int type);
void print_env(int tab_len);

//UNSET
int do_unset(t_jobs *job);
char **remove_of_list(char *to_remove, char **old_list);
//ECHO
int do_echo(t_jobs *jobs);
//start jobs
void start_jobs(t_jobs *job);

// redir handle
int redir_handler(t_jobs *job);


#endif
