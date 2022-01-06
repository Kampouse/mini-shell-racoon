#include "eval.h"

void eval_cmds(t_jobs *job)
{
	int len;
	char *temp;
	char **output;	

    temp = NULL;
	len = 0;
	if(job->cmd && job->cmd[0])	
	{
		while(job->cmd[len])
			len++;
		output = ft_calloc(len + 1,sizeof(job->cmd));
	}
	len = -1;
	while(job->cmd[++len])	
	{
		temp = eval_line(job->cmd[len],output[len],0,0);
		if(!temp)
			temp = ft_strdup("");
		output[len] = temp;
	}
	free(job->cmd);
	job->eval= output;
}
