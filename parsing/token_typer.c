#include "parsing.h"
#include "../minishell.h"

int token_scanner(char *str,size_t *token_size)
{
	int inc;
	const char *trimed  = ft_substr(str,0,until_space(str));
	const char *tokens[10] = { ">>", "<<","<", ">","|","env","export","exit","echo",NULL};

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

/* cureent implementation could be use to split the string int jobs  aka until it sees the pipe */
void tokens_peek(t_dlist *lst)
{
t_dlist *temp;

temp = NULL;
	if(lst)
	
		temp = lst;
	while(temp && temp->type != 4)
	{
		if(temp->type == 7)
			{
				freelist(g_state.env);
				if(lst)
					free_list(lst);
				exit(0);
			}
		if(temp->type == 8)
			printf("echo\n");
		if(temp->type == 5)
			print_env(ft_tab_len(g_state.env));
				//valid_redir(temp);
		//printf("%s %d %d\n",temp->content,temp->type,count);
		temp = temp->next;	
		}
	}


