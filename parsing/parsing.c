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
	t_jobs *temp;
	t_redir *temp_redir;

	temp_redir = NULL;
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
				//this fix some bugs
				temp = job;
		while(job != NULL)	
		{
			if (job && job->cmd )
			{

				check_jobs(job);
				printf("cmd:%s\n",job->cmd[0]);
				printf("type:%d\n",job->cmd_type);
			}
			if(job && job->redir)
			{
				  temp_redir = job->redir;
				while(temp_redir)
				{
					printf("redir:%s\n",temp_redir->cmd);
					temp_redir = temp_redir->next;
				}
			}
			job = job->next;
		}
			ft_lstdclear(&lst,free);
			free_jobs(temp);
		}
		else if(trimed)
			free(trimed);
	}
}
