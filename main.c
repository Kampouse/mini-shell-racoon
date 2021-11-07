/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:36:20 by jemartel          #+#    #+#             */
/*   Updated: 2021/11/07 17:22:55 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

extern char ** environ;

/* this will chop string in substring until it find a a pipe or other  a redirection... */
char **line_parser(char *line)
{
	char	**tokens;

	tokens  = ft_split(line,' ');

return(tokens);
}
/* this  will  function yet to be functionnal will
determine a index that  will excute a set function such as exit_please */
int find_token(char *line, char *token) 
{
const int len = ft_strlen(line);

if(ft_strnstr(line,token,len))
	return(1);

return(0);
}


/* main  entry point of minishell where jobs  
will be created(yet to be implemented) and  (executed WORKING)  */

int read_wrapper(void)
{
char *line;
char *trimed;
char **tokens;

while(1)
	{
		line = readline(GREEN"minishell:>"RESET);
		trimed = ft_strtrim(line," ");
	    free(line);	
		if(trimed && ft_strlen(trimed) > 0)
		{
				tokens = line_parser(trimed);	
				if(exit_please(tokens,trimed) == 1)
					return (1);
			path_resolver(findpath(environ),tokens,environ);
		free(trimed);
		freelist(tokens);
		}
		else if(trimed)
			free(trimed);
}
return (0);
}

int main (void)
{
		if(read_wrapper() == 1)
			printf("delete squense");
}
