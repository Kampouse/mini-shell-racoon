#include "minishell.h"

t_exec g_state = {0};


int main(int argc, char **argv, char **envp)
{
	(void)argv;

	if (argc > 1)
	{
		ft_putstr("Invalid number of arguments\n");
		exit (-1);
	}
	init_exec(envp);
	parsing();
}
