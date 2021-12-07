#include "jobs.h"
t_dlist *ft_lst_nextnth(t_dlist *node,int nth)
{
	t_dlist *temp;
    temp = NULL;
	if(node)
	{
		temp = node;
		while(temp && nth > 0)
		{
			nth--;
			temp = temp->next;
		}
	}
	return (temp);
}
/* this current version can be wrong in some case */
int jobs_lst_counter(t_dlist *lst)
{
	t_dlist *temp;
	int count;

	count = 0;
	temp = lst;
	while(temp && temp->type == -2)
	{
		count++;
		temp = temp->next;
	}
return(count);
}

/* function that create a lst of  args for exceve */
char **jobs_lst_creator(t_dlist *lst,char **redir)
{
 char	**commands;
t_dlist	 *temp;
int		inc;

	temp  = NULL;
	if (redir &&  lst->type >= 0 &&  lst->type <= 3 && lst->next->next)
		temp = lst->next->next;
	else
		temp = lst;
	inc = 0;
	commands = malloc(sizeof(char *) * jobs_lst_counter(temp) + 1);
	while(temp && (temp->type > 4  || temp->type == -2))
	{
		commands[inc] = temp->content;
		temp = temp->next;
		inc++;
	}
	commands[inc] = 0;

return (commands);
}


/*  function  that make a job (get a job) */
int print_tokens(t_dlist *lst)
{
	t_dlist *temp;
	temp = lst;
		while(temp)
	{
		printf("%s %d\n",temp->content,temp->type);
		temp = temp->next;
	}
	return(0);
}
/* verify  if the | symbol is  between two element of the right type */
int piping_verif(t_dlist *lst)
{
	t_dlist *temp =lst;
	
	while(temp)
	{
		if(ft_strchr(temp->content,'|') && temp->next && !(ft_strchr(temp->
			 next->content,'|')))
		{
			if(temp->prev)
			{
				if(!(temp->prev->type == -2 || temp->prev->type > 4))
					return(-1);
			}
			if(temp->next && !temp->prev)
					return(-1);
		}
		else if(ft_strchr(temp->content,'|'))
			return(-1);
		temp = temp->next;		
	}
	return (0);
}
/* create a jobs with the right element in it */
int jobs(t_dlist *lst,t_jobs **output ) 
{
	char **redir;
	char **commands;
	t_dlist *temp;

	temp = NULL;
	temp = lst;
	if(redir_counter(lst) < 0)
		return(-1);
	redir = redir_creator(lst,redir_counter(lst));
	commands = jobs_lst_creator(lst,redir);	
	*output = job_new_lst(commands,redir);
return (0);
}
/* function that  create a list of (jobs) break on failure */
t_jobs *jobs_tail(t_dlist *lst,t_jobs *currjobs)
{
  t_dlist *temp;
  t_jobs *tempjob;
  
	temp = job_find_pipe(lst);
	if(temp)
	{
		if(jobs(temp,&tempjob) >= 0 )
		{
			jobs_addback(&currjobs,tempjob);
			return(jobs_tail(temp,currjobs));
		}
		else
		//	 should free this when it fail;
			return(NULL);
	}
return(currjobs);
}
t_jobs *job_lsting(t_dlist *lst)
{
	t_jobs *joblst;
	t_dlist *temp;	

	joblst  = NULL;
	temp = lst;

	if(piping_verif(lst) == 0)
	{
			if(jobs(lst,&joblst) == 0)
				printf(" test %s\n",joblst->cmd[0]);
			else
				return(NULL);
				//should return a free list since it failed;
	//		jobs_addback(jobbing,temp);
	}
	else
	{
		printf("syntax error near unexpected token `|'\n");
			return(NULL);
	}
	jobs_tail(lst,joblst);
	return(0);
}
