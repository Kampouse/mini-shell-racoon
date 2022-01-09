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
    {
        printf("invalid file:%s\n", temp);
		return(-1);
    }
	dup2(fd,0);
	close(fd);
return(0);
}

int here_redir(char *temp)
{
    int fd = open("/tmp/here_docced",O_TRUNC | O_CREAT | O_RDWR , 0777);
    int stdin = dup(0);
    const int len = ft_strlen(temp);

    if(fd < 0)
    {
        printf("herror\n");
        return (-1);
    }
    write(0, temp, len);
    dup2(fd,0);
    write(fd, temp, len);
    close(fd);
    unlink("/tmp/here_docced");
return (0);
}

int redir_handler(t_jobs *job)
{
    t_redir *temp;
    int status;

    temp = NULL;
    status = 0;
    if(job->redir)
    {
        temp = job->redir; 
        while(temp && status == 0)
        {
            if(temp->type == 0 && redir_bool(temp->eval))
                printf("help\n");
            else if(temp->type == 1)
                status = here_redir(job->hereduc);
            else if(temp->type == 2 && redir_bool(temp->eval))
				status = input_redir(temp->eval);
            else if(temp->type == 3 && redir_bool(temp->eval))
                printf("rageur\n");
            temp = temp->next;
        }
    }
    return (status);
}
