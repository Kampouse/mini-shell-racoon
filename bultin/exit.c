/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:01:24 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/25 18:43:06 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void quit_shell()
{
	freelist(g_state.env);
	freelist(g_state.exprt);
	rl_clear_history();
	printf("exit\n");
	exit(g_state.output);
}

int chek_arg(char *arg)
{
	
}

int	do_exit(char **exit_arg)
{
	int i;

	i = 0;
	while (exit_arg[i])
	{
		if (chek_arg(exit_arg[i++]))
			return (1);
	}
	quit_shell();
	return (0);
}

//Note Exit
// -> si premier argument est valid et deuxiemen non on exit pas
// affiche message derreur 
//si exit sans arg exit(g_state_output)
//si on envoi un nombre < 256 g_State.output aka $? = ce nombre

// comme premier arg 0 a 255 on affiche 
//256 = 0
//257 = 1
//