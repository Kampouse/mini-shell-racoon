// #include "../minishell.h"

// int until_this(char *str,char *this)
// {
// 	int inc;

// 	inc = 0;
// 	while(str[inc])
// 	{
// 		if(ft_strchr(this,str[inc]))
// 			return(inc);
// 		inc++;
// 	}
// return(-1);
// }

// char *eval_string(char *str)
// {
// int inc;
// const   int quote = until_this(str,"\'\"");
// inc = 0;
// 		printf("%d",quote);
// 			if(  *( str +  quote) == '\"')
// 				printf("tst");
// return(str);
// }
// void eval_cmds(t_jobs *job)
// {
// 	int inc;
	
// 	inc = -1;
// 	if(job->cmd)	
// 	{
// 		while(job->cmd[++inc])
// 			eval_string(job->cmd[inc]);
// 	}
// }
// void eval_redir(t_jobs *job)
// {
// 	int inc;
// 	t_redir *temp;	

// 	temp = NULL;
// 	inc = -1;
// 	if(job->redir)	
// 	{
// 		temp = job->redir;
// 		while(temp)
// 		{
// 				eval_string(job->cmd[inc]);
// 				temp = temp->next;
// 		}
// 	}
// }

// int eval(t_jobs *jobs)
// {
// 	t_jobs *temp;

// 	if(jobs)
// 	{
// 		temp = jobs;
// 		while(temp)
// 		{
// 			eval_cmds(temp);
// 			eval_redir(temp);
// 			temp = temp->next;
// 		}
	
// 	}
// 	return(0);
// }








