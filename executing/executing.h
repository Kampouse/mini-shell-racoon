#ifndef EXECUTING_H
# define EXECUTING_H

typedef struct s_export
{
    char            *export_node;
    struct s_export *next;
} t_export;

typedef struct s_exec
{
    char            **exprt;
    char            **env;
    int             stdin;
    int             stdout;
    unsigned int    output;
} t_exec;

extern t_exec g_state;
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


void print_var(char *var);

#endif