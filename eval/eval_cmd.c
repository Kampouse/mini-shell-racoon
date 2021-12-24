#include "eval.h"

void eval_cmds(t_jobs *job)
{
	int inc;
	char *output;	

	output = NULL;
	inc = 0;
	if(job->cmd && job->cmd[inc])	
	{
		output = eval_line(job->cmd[inc],output,0,0);
		if(output)
		{
				job->cmd[inc] = output;
				
				//free(job->cmd[inc]);
		}
	}
}
