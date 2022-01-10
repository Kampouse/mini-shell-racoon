#include "../minishell.h"


int pipe_handler(int pipe[],int state)
{
    if(state < -1)
        return(0);

    if(state == 0)
        dup2(1,pipe[1]);
    if(state == 1) 
        dup2(pipe[0],0);
return(0);
}
