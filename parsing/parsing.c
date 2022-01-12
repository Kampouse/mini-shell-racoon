#include "../minishell.h"

/* evaluate each job one after the  other */
void sig_c(int signum)
{
    (void)signum;
    ft_putstr("\n");
    rl_replace_line("\n",0);
    rl_on_new_line();
    rl_redisplay();
}

void sig_d(int signum)
{
    printf("%d\n",signum);
}


int same_len(char *str ,char *str2)
{
	if(str && str2)
	{
		if(ft_strlen(str) == ft_strlen(str2))
			return(0);
		else
			return(1);
	}
	return(-1);
}

int pipe_counter(t_dlist *lst)
{
	t_dlist *tmp;
	int count;

	count = 0;
	tmp = lst;
	while(tmp)
	{
		if(tmp->type == 4)
		count += 2;
		tmp = tmp->next;
	}
	return(count);
}

void parser_muduled(t_jobs *job,t_dlist *lst,int inc)
{
	t_jobs *temp;
    int pipes[2];
    int state = 0;

    temp = job;
    if(inc > 1)
        pipe(pipes);
    else
        state = -1;
		while(temp)
		{
			start_job(temp, lst,pipes,state);
			temp = temp->next;
		}
		free_jobs((t_jobs *)job,0);
}


void parser_core(t_dlist *lst)
{
	t_jobs *job = job_lsting(lst);
	t_jobs *temp;
    int inc;

	temp = NULL;	
	temp = (t_jobs*)job;
    inc = 0;
    
	if(job)
	{
		pre_val_redir((t_jobs*)job);
		while(temp)
		{
			eval(temp);
			temp = temp->next;
            inc++;
		}
        parser_muduled(job,lst,inc);
	}
}

/* start readline and tokenize the string */
void quick_parser(char *str)
{
	const char *trimed = ft_strtrim(str," ");
	t_dlist *lst;

	if(trimed && ft_strlen(trimed) > 0)
	{
		lst = line_parser((char *)trimed);
		free((char *)trimed);
		if(lst != NULL)
		{
			parser_core(lst);			
			free_nodes(lst);
		}
	}	
}

void parsing(void)
{
	char *line;
	char *trimed;
	t_dlist *lst;

    lst = NULL;
	while(1)
	{
        signal(SIGINT,sig_c);
        signal(SIGQUIT,sig_d);
		line = readline(GREEN"minishell:>"RESET);
		trimed = ft_strtrim(line,"\n ");
		add_history(trimed);
		free(line);
		if(trimed && ft_strlen(trimed) > 0)
		{
			lst = line_parser(trimed);
			free(trimed);
			if(lst != NULL)
			{
				parser_core(lst);			
				free_nodes(lst);
			}
		}
		else
			free(trimed);
	}
}
