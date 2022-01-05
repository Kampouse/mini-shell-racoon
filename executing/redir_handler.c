#include "executing.h"

int redir_bool(char *str)
{
    if(str)
    return (1);
    else
        return (0);
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
                printf("am over");
            else if(temp->type == 1 && redir_bool(temp->eval))
                printf("cq");
            else if(temp->type == 2 && redir_bool(temp->eval))
                printf("svp");
            else if(temp->type == 3 && redir_bool(temp->eval))
                printf("rageur");
            temp = temp->next;
        }
    }
    return(0);
}
