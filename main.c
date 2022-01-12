#include "minishell.h"
#include "signal.h"

t_exec g_state = {0};

/* this will chop string in substring until it find a a pipe or other  a redirection... */

/* this  will  function yet to be functionnal will
determine a index that  will excute a set function such as exit_please */

/* main entry point where every thing happen from creating token to jobs to excution */


int main(int argc, char **argv, char **envp)
{
	create_env(envp);
    create_export(envp);
	g_state.output = 0;
	if (argc > 3)
	{
		ft_putstr("Invalid number of arguments\n");
		exit (-1);
	}
	if (argc == 3 &&  ft_strncmp("-c",argv[1],ft_strlen("-c")) == 0)
	{
		quick_parser(argv[2]);
		freelist(g_state.env);
		freelist(g_state.exprt);
	}
	else
		parsing();
}

