#include "jobs.h"

int jobs_lst(t_dlist *lst) 
{
	int count;
	int until;
	char **redir;
	until = 0;
	count =  redir_counter(lst);
	
	redir = redir_creator(lst,count);
	count = 0;
	if (redir)
	{
		//printf("%d",any_heredoc(redir));
		redirector(redir);
		while(redir[count])	
		{
			printf(  " and %s \n",redir[count + 1]);
			count+=2;
		}
	}
return (0);
}



