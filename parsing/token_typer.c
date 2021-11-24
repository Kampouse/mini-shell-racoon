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




void tokens_end(t_dlist *lst)
{
t_dlist *temp;
int status;
status = 0;
temp = NULL;
	if(lst)
	{
		temp = lst;
	while(temp)
		{
		if(temp->type == 7)
			{
				status = 1;
				free_list(lst);
				exit(0);
			}
		if(temp->type == 8)
		{
			printf("echo chamber\n");
		}
		printf("%s\n",temp->content);
		temp = temp->next;	
		}

	}
}
