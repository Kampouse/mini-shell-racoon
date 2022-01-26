/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:01:24 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/26 14:18:50 by olabrecq         ###   ########.fr       */
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

int chek_arg(char **arg)
{
	int i;

	i = 0;
	if (ft_isalpha_word(arg[1]))
	{
		printf("minishell-racoon: exit: %s: numeric argument required", arg[1]);
		g_state.output = 255;
		return (g_state.output);
	}
	while (arg[i])
	{
		
		i++;

	}
	return (0);
}

int	do_exit(char **exit_arg)
{
	// int i;

	// i = 0;
	if (ft_tab_len(exit_arg) > 2 && ft_isalpha_word(exit_arg[1]))
		return (1);
	if (ft_tab_len(exit_arg) <= 1)
	{
		
		if (chek_arg(exit_arg))
			return (g_state.output = 1);
		
	}
	// else 
		// quit_shell();
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


//exit 5 b b = 1
//exit 5 b  = 1
//exit 5 5 = 1

// exit b b 5 = 255