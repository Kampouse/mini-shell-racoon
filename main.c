#include "minishell.h"

t_exec g_state = {0};

/* this will chop string in substring until it find a a pipe or other  a redirection... */

/* this  will  function yet to be functionnal will
determine a index that  will excute a set function such as exit_please */
int find_token(char *line, char *token) 
{
	const int len = ft_strlen(line);

	if(ft_strnstr(line,token,len))
		return(1);

	return(0);
}


/* main entry point where every thing happen from creating token to jobs to excution */
int read_wrapper()
{
	char *line;
	char *trimed;
	t_dlist *token_lst;

	token_lst = NULL;
	while(1)
	{
		line = readline(GREEN"minishell:>"RESET);
		trimed = ft_strtrim(line," ");
	    free(line);	
		if(trimed && ft_strlen(trimed) > 0)
		{
			 token_lst = line_parser(trimed); 	
		}
		else if(trimed)
			free(trimed);
	}
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	create_env(envp);
	read_wrapper();
}
