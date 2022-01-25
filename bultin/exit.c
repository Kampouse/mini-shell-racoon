/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:01:24 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/25 15:07:08 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int	do_exit(t_jobs *job)
{
		(void)job;
		freelist(g_state.env);
		freelist(g_state.exprt);
		//free_list(lst);x
		exit(g_state.output);
}

//Note Exit
// -> si premier argument est valid et deuxiemen non on exit pas
// affiche message derreur 
//si exit sans arg exit(g_state_output)
//si on envoi un nombre < 256 g_State.output aka $? = ce nombre

//  int do_exit(t_jobs *job)
//  {
// 	 (void)job;
// 	freelist(g_state.env);
// 	freelist(g_state.exprt);
// 	// freelist(g_state.output);
// 	printf("exit\n");
// 	return (0);
//  }