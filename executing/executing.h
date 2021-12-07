#ifndef EXECUTING_H
# define EXECUTING_H

typedef struct s_exec
{
    char            **exprt;
    char            **env;
    int             stdin;
    int             stdout;
    unsigned int    output;
} t_exec;

extern t_exec g_state;


void init_exec(char **envp);

// ENV
void create_env(char **envp);
void print_env(int tab_len);
//EXPORT
void create_export(char **envp);
void print_exprt(int tab_len);
// VARIABLE

// UTILS FUNCTION
char **alloc_tab(char **envp);
int ft_tab_len(char **tab);
char **ft_sort_tab(char **tab);


char *print_var(char *var);


void do_export(t_jobs *jobb);
void check_bultin(t_jobs *jobb);
int export_valider(t_jobs *jobb);



#endif