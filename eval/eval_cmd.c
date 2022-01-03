#include "eval.h"

char **eval_cmds(t_jobs *job)
{
	int inc;
	int len;
	char *temp;
	char **output;	

	output = NULL;
	temp = NULL;
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
		temp = eval_line(job->cmd[inc],output[inc],0,0);
		if(!temp)
			temp = ft_strdup("");
		output[inc] = temp;
		inc++;
	}
  	free(job->cmd);
	return(output);
}
