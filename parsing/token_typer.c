/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_typer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:48:33 by jemartel          #+#    #+#             */
/*   Updated: 2022/01/26 10:26:58 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	token_scanner_ext(const char *trimed, size_t *token_size, int inc)
{
	const char	*tokens[13] = {">>", "<<", "<", ">", "|", "env", "export",
		"exit", "echo", "unset", "pwd", "cd", NULL};

	if (ft_strncmp(trimed, (char *)tokens[inc], ft_strlen(tokens[inc])) == 0)
	{
		if (ft_strlen(trimed) == ft_strlen(tokens[inc]))
		{
			*token_size = ft_strlen(trimed);
			return (inc);
		}
	}
	return (-2);
}

int	token_scanner(char *str, size_t *token_size, int inc)
{
	const char	*trimed = ft_substr(str, 0, until_space(str));
	const char	*tokens[13] = {">>", "<<", "<", ">", "|", "env", "export",
		"exit", "echo", "unset", "pwd", "cd", NULL};

	if (!str)
		return (-1);
	while (tokens[++inc])
	{
		if (inc <= 4 && ft_strncmp(trimed, (char *)tokens[inc],
				ft_strlen(tokens[inc])) == 0)
		{
			free((char *) trimed);
			*token_size = ft_strlen(tokens[inc]);
			return (inc);
		}
		else if (token_scanner_ext(trimed, token_size, inc) != -2)
		{
			*token_size = ft_strlen(trimed);
			free((char *) trimed);
			return (inc);
		}
	}
	*token_size = 0;
	free((char *) trimed);
	return (-2);
}

/*  exit  */
// void	tokens_peek(t_dlist *lst)
// {
// 	t_dlist	*temp;

// 	temp = NULL;
// 	if (lst)
// 		temp = lst;
// 	while (temp && temp->type != 4)
// 	{
// 		if (temp->type == 7)
// 		{
// 			freelist(g_state.env);
// 			freelist(g_state.exprt);
// 			if (lst)
// 				free_list(lst);
// 			write(1, "exit\n", ft_strlen("exit\n"));
// 			unlink("/tmp/here_docced");
// 			exit(g_state.output);
// 		}
// 		temp = (t_dlist *)temp->next;
// 	}
// }

//Note Exit
// -> si premier argument est valid et deuxiemen non on exit pas
// affiche message derreur 
//si exit sans arg exit(g_state_output)
//si on envoi un nombre < 256 g_State.output aka $? = ce nombre

// comme premier arg 0 a 255 on affiche 
//256 = 0
//257 = 1
//


// 1. When exit is given more than two args. The return value is 1 
// 2. When exit is given exactly two args. This has two sub cases 
//        When in those two args, any one is not a number or if it is number but the number is bigger than a l. 
//        long -- in that case you return 2 
// otherwise if it is two args and it is a number within long you return ( num & 255 ) { Lil trick from the internet}
// 3. When exit is given less than 2 args then just return the shell status
// For example 
// 1. Exit 400 400 ( this is more than 2 args)
// 2. Exit 100 ( this is exactly 2 args)
// 3. Exit (this is less than 2 args) 