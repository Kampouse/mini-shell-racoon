#include "minishell.h"

// void    insert_end(t_env **root, char *str)
// {

//     t_env *new_node = malloc(sizeof(t_env));
    
//     if (new_node == NULL)
//         exit(1);
        
//     new_node->next = NULL;
//     new_node->env_node = ft_strdup(str);
//    if (*root == NULL)
//     {
//         *root = new_node;
//         return;
//     }
    
//     t_env *current = *root;
//     while (current->next != NULL)
//     {
//         current = current->next;
//     }
//     current->next = new_node;
// }


// void create_env(char **envp)
// {
//     int i;

//     i = 0;
//     while (envp[i])
//         insert_end(&g_state.env, envp[i++]);
// }

// void print_env()
// {
//     while (g_state.env->next != NULL)
//     {
//         printf("%s\n", g_state.env->env_node);
//         g_state.env = g_state.env->next;
//     }
// }

// char *ft_strcpy(char *str)
// {
//     char *ret;
//     int i;

//     i = 0;
//     ret = NULL;
//     while (str[i])
//     {
//         ret[i] = str[i];
//         i++;
//     }
//     ret[i] = '\0';
//     return (ret);
// }
 

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