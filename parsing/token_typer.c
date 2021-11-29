#include "parsing.h"

int token_scanner(char *str,size_t *token_size)
{
	int inc;
	const char *trimed  = ft_substr(str,0,until_space(str));
	char *tokens[10] = { ">>", "<<","<", ">","|","env","export","exit","echo",NULL};
	inc = 0;
	if(!str)
		return(-1);
	while(tokens[inc])
	{
		 if(ft_strncmp(trimed,(char *)tokens[inc],ft_strlen(tokens[inc])) == 0)
		{
				free((char *) trimed);
				*token_size = ft_strlen(tokens[inc]);
			 return(inc);
		}
		inc++;
	}
	*token_size = 0;
	free((char *) trimed);
	return(-2);
}





int valid_redir(t_dlist *redir)
{
		if(redir->type >= 0 &&  redir->type <= 3)
	{
			if(redir->next)	
			{
				if(!(redir->next->type >= 0 &&  redir->next->type <= 3))
					 return(1);
			}
			else
			{
				printf("expected something\n");
				return(-1);
			}
	}
	return (0);
}

int redir_counter(t_dlist *redir)
{

	t_dlist *temp;
	int counter;
	int tmp;
	
	temp = redir;
	counter = 0;
	while(temp && temp->type != 4)
	{
		 tmp  = valid_redir(temp);
		if(tmp == -1)	
			return(-1);
		else 
			counter+= tmp;
		temp = temp->next;
	}
	return(counter);
}



/* cureent implementation could be use to split the string int jobs  aka until it sees the pipe */
void tokens_peek(t_dlist *lst)
{
t_dlist *temp;
int status;
int count;

count = 0;
status = 0;
temp = NULL;
	if(lst)
	
		temp = lst;
	while(temp && temp->type != 4)
	{
		if(temp->type == 7)
			{
				status = 1;
				freelist(g_state.env);
				free_list(lst);
				exit(0);
			}
		if(temp->type == 8)
			printf("echo\n");
		if(temp->type == 5)
			print_env(ft_tab_len(g_state.env));
				//valid_redir(temp);
		printf("%s %d %d\n",temp->content,temp->type,count);
		temp = temp->next;	
		}
	}


