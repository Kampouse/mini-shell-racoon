#include "../minishell.h"

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
void parsing()
{
	char *line;
	char *trimed;
	t_dlist *lst;
	
    lst = NULL;
	while(1)
	{
		line = readline(GREEN"minishell:>"RESET);
		trimed = ft_strtrim(line," ");
	    free(line);	
		if(trimed && ft_strlen(trimed) > 0)
		{
			lst = line_parser(trimed); 	
			if(lst)
				job_lsting(lst);
			//free_list(lst);
			//jobs_lst(lst);
		}
		else if(trimed)
			free(trimed);
	}
}
