#include "executing.h"
#include "fcntl.h"

int redir_bool(char *str)
{
    if(str)
    return (1);
    else
        return (0);
}


int input_redir(char  *temp)
{

int  fd;

fd = open(temp,O_RDONLY);
	if(fd < 0)
		return(-1);
	dup2(fd,0);
	close(fd);
return(0);
}


int redir_handler(t_jobs *job)
{
    t_redir *temp;
    temp = NULL;
    (void)job;
    if(job->redir)
    {
        temp = job->redir; 
        while(temp)
        {
            if(temp->type == 0 && redir_bool(temp->eval))
                printf("am over\n");
            else if(temp->type == 1 && redir_bool(temp->eval))
                printf("cq\n");
            else if(temp->type == 2 && redir_bool(temp->eval))
			{
				if(input_redir(temp->eval) == -1)
				{
					printf(" minishell  ->>> invalid file %s\n",temp->eval);
					return(-1);
				}
			}
            else if(temp->type == 3 && redir_bool(temp->eval))
                printf("rageur\n");
            temp = temp->next;
        }
    }
    return(0);
}
