#include "eval.h"

char **eval_cmds(t_jobs *job)
{
	int inc;
	int len;
	char **output;	

	output = NULL;
	inc = 0;
	len = 0;
	if(job->cmd && job->cmd[inc])	
	{
		while(job->cmd[len])
			len++;
		output = ft_calloc(len + 1,sizeof(job->cmd));
	}
	while(job->cmd[inc])	
	{
		output[inc] = eval_line(job->cmd[inc],output[inc],0,0);
		inc++;
	}
	return(output);
}
