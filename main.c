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


/* main  entry point of minishell where jobs  
will be created(yet to be implemented) and  (executed WORKING)  */

int read_wrapper(char **envp)
{
	char *line;
	char *trimed;
	int type;
	
	//jtype = -2;
	while(1)
	{
		line = readline(GREEN"minishell:>"RESET);
		trimed = ft_strtrim(line," ");
	    free(line);	
		if(trimed && ft_strlen(trimed) > 0)
			type = line_parser(trimed,envp); 	
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
	print_env(envp);
	if(read_wrapper(envp) == 1)
		printf("delete squense");
}
