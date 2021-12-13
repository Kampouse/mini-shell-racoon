#include "../minishell.h"

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
	
	while(temp)
	{
		if(temp->type > 4 || temp->type == -2)
			count++;

		temp = temp->next;
	}
return(count);
}

/* function that create a lst of  args for exceve */
char **jobs_lst_creator(t_dlist *lst,t_dlist **lst_head)
{
 char	**commands;
t_dlist	 *temp;
int		inc;

	inc = 0;
	temp  = NULL;
	commands = NULL;
	if ((lst->type >= 0 &&  lst->type <= 3 && lst->next && lst->next->next))
		temp = lst->next->next;
	else
		temp = lst;
	if(temp->content &&  !(temp->type >= 0 && temp->type <= 3))
	{
		*lst_head = temp;
		 commands  = ft_calloc( (size_t)jobs_lst_counter(temp) + 1,sizeof(char **));
		while(temp && (temp->type > 4  || temp->type == -2))
		{
			commands[inc++] = temp->content;
			temp = temp->next;
		}
	}
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
int pipe_return(int status)
{
	if(status == -1)
	{
		printf("syntax error near unexpected token `|'\n");
		return(-1);
	}
	return(0);
}

int piping_verif(t_dlist *lst)
{
	t_dlist *temp =lst;
	
	while(temp)
	{
//ft_strncmp(temp->content,"|",ft_strlen("|")) && temp->next && !( ft_strncmp(temp->next->content,"|",ft_strlen("|")))
		if(temp->type  == 4)
		{
			if(temp->prev && (temp->prev->type >= 0  && temp->prev->type <= 4))
					return(pipe_return(-1));
			if(temp->next && (temp->next->type >= 0  && temp->next->type <= 4))

					return(pipe_return(-1));
			if(!temp->prev || !temp->next)
					return(pipe_return(-1));
		}
		temp = temp->next;		
	}
	return (0);
}
/* create a jobs with the right element in it */
int jobs(t_dlist *lst,t_jobs **output ) 
{
	t_redir *redir;
	t_dlist *cmd_head;
	int status;
	char **commands;

	commands = NULL;
	cmd_head = NULL;
	status = 0;
	redir = redir_creator(lst,&status);
	if(status < 0)
		return(-1);
	if( lst && lst->content)
		commands = jobs_lst_creator(lst,&cmd_head);	
		//cmd_head give acces to type of the cmd
	*output = job_new_lst(commands,redir,cmd_head);
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
	joblst  = NULL;

	if(piping_verif(lst) == 0 && jobs(lst,&joblst) == 0)
		  return(jobs_tail(lst,joblst));
	else
		return(NULL);
	return(joblst);
}
