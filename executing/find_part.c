
#include <sys/stat.h>
#include "../minishell.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>

char	*find_part(char *first, char *str, int inc, size_t **len)
{
	(void)len;
	(void)inc;
	(void)str;
	if (!first)
	{
		ft_putstr_fd("you should learn how to type! :rage: \n", 2);
		len = NULL;
		first = NULL;
		g_state.output = 130;
		return (NULL);
	}
	len = NULL;
	return (first);
}

int	same_len(char *str, char *str2)
{
	if (str && str2)
	{
		if (ft_strlen(str) == ft_strlen(str2))
			return (0);
		else
			return (1);
	}
	return (-1);
}

int	is_folder(t_jobs *jobs, char *local)
{
	struct stat	stats;

	if (local)
	{
		stat(local, &stats);
		if (S_ISREG(stats.st_mode) == 0 && ft_strlen(jobs->eval[0]) != 0)
		{
			ft_putstr_fd("IS a directory: ", 2);
			ft_putstr_fd(jobs->eval[0], 2);
			ft_putstr_fd("\n", 2);
			free(local);
			g_state.output = 126;
			return (1);
		}
	}
	return (0);
}
 void handle_fd(t_pipe *pipes)
{
	if (pipes && pipes->state < pipes->pipe_nbr)
		{
			dup2(pipes->pipes[pipes->state][1],1);
			close( pipes->pipes[pipes->state][1]);
			close( pipes->pipes[pipes->state][0]);
		}
	if (pipes && pipes->state != 0)
	{
		dup2(pipes->pipes[pipes->state - 1][0],STDIN_FILENO);
		close(pipes->pipes[pipes->state - 1][1]);
		close(pipes->pipes[pipes->state - 1][0]);
	}
}
 void handle_fd_main(t_pipe *pipes)
{
	if (pipes && pipes->state > 0)
	{
		close(pipes->pipes[pipes->state - 1][0]);
		close(pipes->pipes[pipes->state - 1][1]);
	}
}

int	path_resolver(t_jobs *job, t_dlist *lst,t_pipe *pipes)
{
	int			pid;
	int			status;
	const char	*local = make_executable(job);

	if (!local || is_folder(job, (char *)local))
		return (g_state.output);
	pid = -1;
//restore_signal(SIGINT);
//restore_signal(SIGQUIT);

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
			handle_fd(pipes);
			redir_handler(job);
			rl_clear_history();
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			if(job->cmd_type >= 0)
		{
			check_bultin(job);	
			job->status = g_state.output;
			while(job->prev)
				job = job->prev;
			free_jobs(job, 0);
			freelist(g_state.exprt);
			free_list(lst);
			freelist(g_state.env);
			rl_clear_history();
			delete_pipe(pipes,1);
			free((void*) local);
			exit(g_state.output);
		}
			job->status = g_state.output;
			exec_the_bin((char *)local, job, lst,pipes);
	}
	handle_fd_main(pipes);
	free((char *)local);
	return (WEXITSTATUS(status));
}
