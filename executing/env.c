#include "../minishell.h"

char **alloc_tab(char **envp)
{
    char **tab;
    int i;

    i = 0;
    while (envp[i])
        i++;
    tab = malloc(sizeof(char*) * i);
    return (tab);
}

void create_env(char **envp)
{
    g_state.env = alloc_tab(envp);
    int i;

    i = 0;
    while (envp[i])
    {
        g_state.env[i] = ft_strdup(envp[i]);
        i++;
    }
}

void print_env(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {
        printf("%s\n", g_state.env[i]);
        i++;
    }
}