#include "minishell.h"

void print_env(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
        ft_putstr_fd(1, envp[i++]);
}

void create_env(t_exec g_state, char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {
      
    }
    
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	print_env(envp);
}