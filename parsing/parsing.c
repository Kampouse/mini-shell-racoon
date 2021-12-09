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
	t_jobs *job;
	
	job = NULL;
    lst = NULL;
	while(1)
	{
		line = readline(GREEN"minishell:>"RESET);
		trimed = ft_strtrim(line," ");
	    free(line);
	
		if(trimed && ft_strlen(trimed) > 0)
		{
			lst = line_parser(trimed); 	
			job = job_lsting(lst);
			if (job)
				check_jobs(job);
		}
		else if(trimed)
			free(trimed);
	}
}
//job_lst->cmd[0] == export 