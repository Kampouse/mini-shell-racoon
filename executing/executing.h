#ifndef EXECUTING_H
# define EXECUTING_H

typedef struct s_export
{
    char            *export_node;
    struct s_export *next;
} t_export;

typedef struct s_exec
{
    t_export        *exprt;
    char            **env;
    int             stdin;
    int             stdout;
    unsigned int    output;
} t_exec;

extern t_exec g_state;

void create_env(char **envp);
void print_env(char **envp);
char **alloc_tab(char **envp);


// UTILS FUNCTION
int ft_tab_len(char **tab);
char **ft_sort_tab(char **tab);

#endif