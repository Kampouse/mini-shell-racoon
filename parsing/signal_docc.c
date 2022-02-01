/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_docc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemartel <jemartel@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 03:01:33 by jemartel          #+#    #+#             */
/*   Updated: 2022/02/01 12:34:03 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"
#include "parsing.h"

void	sig_chi(int signum)
{
	if (signum == SIGINT)
	{
			ft_putstr("\n");
	}
}
void	sig_cc(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(1, "  \n", 3);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
		ft_putstr("\b\b \b\b");
}
void	sig_c(int signum, siginfo_t *info, void *unsed)
{
	(void)info;
	(void)unsed;
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(1, "  \n", 3);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();

	}
	else if (signum == SIGQUIT)
	{

		ft_putstr("\b\b \b\b");
		rl_redisplay();
		
	}
}

void	sig_child(int signum, siginfo_t *info, void *unsed)
{
	(void)info;
	(void)unsed;
	if (signum == SIGINT)
	{
		ft_putstr("\b\b\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
	else if (signum == SIGQUIT)
		ft_putstr("\b\b \b\b");
}

void	sig_docc(int signum, siginfo_t *info, void *unsed)
{
	(void)info;
	(void)unsed;
	if (signum == SIGINT)
	{
		ft_putstr("\b\b\n");
		rl_replace_line("", 0);
	}
}

void	start_signal(int type)
{
	struct sigaction	sa_sig;

	sa_sig.sa_flags = SA_SIGINFO;
	if (type == 0)
	{
		dup2(g_state.stdin, 1);
		dup2(g_state.stdout, 0);
		sa_sig.sa_sigaction = sig_c;
	}
	if (type == 1)
		sa_sig.sa_sigaction = sig_child;
	if (type == 2)
		sa_sig.sa_sigaction = sig_docc;
	sigemptyset(&sa_sig.sa_mask);
	if (sigaction(SIGINT, &sa_sig, NULL) == -1)
		perror("SIGACTION ERROR\n");
	if (sigaction(SIGINT, &sa_sig, NULL) == -1)
		perror("SIGACTION ERROR\n");
}
 int restore_signal(const int signum)
{
    struct sigaction  act;

    memset(&act, 0, sizeof act);
    sigemptyset(&act.sa_mask);

    act.sa_handler = SIG_DFL;
    act.sa_flags = 0;

    if (sigaction(signum, &act, NULL) == -1)
        return 0;

    return 0;
}

