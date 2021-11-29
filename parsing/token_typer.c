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



 
 
int redir_any(t_dlist *redir)
{
		if(redir->type != -2 &&  redir->type <= 3)
	{
			if(redir->next)	
			{
				if(redir->type == -2)
			{
					printf(":(\n");
				 return(1);
			}
			}
			else
				printf("expected something");
			}
	return (0);
}

int  command_input(t_dlist *lst)
{

	





	return(0);
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
	{
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
			printf("echo chamber\n");
		if(temp->type == 5)
			print_env(ft_tab_len(g_state.env));
				redir_any(temp);
			printf("%s %d %d\n",temp->content,temp->type,count);
			temp = temp->next;	
		}
	}
}
