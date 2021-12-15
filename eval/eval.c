#include "eval.h"
int until_this(char *str,char *this)
{
	int inc;

	inc = 0;
	while(str[inc])
	{
		if(ft_strchr(this,str[inc]))
			return(inc);
		inc++;
	}
return(-1);
}

char *eval_string(char *str)
{
int inc;
const   int quote = until_this(str,"\'\"");
inc = 0;
		printf("%d",quote);
			if(  *( str +  quote) == '\"')
				printf("tst");
return(str);
}
void eval_cmds(t_jobs *job)
{
	
	eval_string(job->cmd[0]);

}





int eval(t_jobs *jobs)
{
	t_jobs *temp;

	if(jobs)
	{
		temp = jobs;
		while(temp)
		{
			printf("%s\n",temp->cmd[0]);
		eval_cmds(jobs);
			temp = temp->next;

			


		}
	
	}
return(0);
}








