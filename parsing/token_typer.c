#include "../minishell.h"


int token_scanner_ext(const char *trimed,size_t *token_size,int inc)
{
	const char *tokens[11] = { ">>", "<<","<", ">","|","env","export","exit","echo","unset",NULL};

	if( ft_strncmp(trimed,(char *)tokens[inc],ft_strlen(tokens[inc])) == 0)
	{
		if(ft_strlen(trimed) == ft_strlen(tokens[inc]))
		{
			*token_size = ft_strlen(trimed);
			return (inc);
		}
	}
	return (-2);
}

int token_scanner(char *str,size_t *token_size)
{
	int inc;
	const char *trimed  = ft_substr(str,0,until_space(str));
	const char *tokens[11] = { ">>", "<<","<", ">","|","env","export","exit","echo","unset",NULL};

	inc = -1;
	if(!str)
		return(-1);
	while(tokens[++inc])
	{
		if(inc <= 4 && ft_strncmp(trimed,(char *)tokens[inc],ft_strlen(tokens[inc])) == 0)
		{
			free((char *) trimed);
			*token_size = ft_strlen(tokens[inc]);
			return(inc);
		}
		else if(token_scanner_ext(trimed,token_size,inc) != -2)
		{
			*token_size = ft_strlen(trimed);
			free((char *) trimed);
			return(inc);
		}
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
			printf("at :token_typer:48 please find a correct place for it \n");
			exit(0);
		}
		if(temp->type == 5)
			print_env(ft_tab_len(g_state.env));
		temp = temp->next;	
	}
}
