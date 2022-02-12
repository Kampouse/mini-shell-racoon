/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:57:44 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/11 16:43:49 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int is_in_env(char *str);
int is_in_env_assigned(char *str);

int	got_good_args(char *cmd)
{
	int	i;

	i = 0;
	if (!ft_isalpha(cmd[i]) && cmd[i] != '_')
		return (1);
	while (cmd[++i] && cmd[i] != '=')
		if (!ft_isalnum(cmd[i]) && cmd[i] != '_')
			return (1);
	return (0);
}

void	create_export(char **envp)
{
	int	i;

	i = 0;
	g_state.exprt = alloc_tab(envp);
	while (envp[i])
	{
		g_state.exprt[i] = ft_strdup(envp[i]);
		i++;
	}
	ft_sort_tab(g_state.exprt);
}

//Cette fonction trie les bonne variable et valeur a ajouter a la liste export
 
int replace_at(char *var,char *val,int type)
{
	(void)val;
	(void)val;
	(void)type;
	int location;
	location = 0;

	if(is_in_env_assigned(var) >= 0)
		location = is_in_env_assigned(var); 	
	else if(is_in_env(var) >= 0)
	{
		location = is_in_env(var); 
	}
	printf("tst");
		g_state.exprt[location] = ft_strdup(var);

return(0);
}


int	update_export_list(char *var, char *val, int type)
{
	char	*new_exprt;
	const	int prev = is_in_env(var);
	const	int old = is_in_env_assigned(var);
	
	if(prev >= 0 || old >=  0)
		replace_at(var,val,type);
	if (type == 1)
	{
		new_exprt = ft_strjoin(var, val);
		g_state.exprt = add_to_list(new_exprt, g_state.exprt, 1);
	}
	if (type == 3)
	{
		printf("%s\n",var);
		val = ft_str3join("\"", val, "\"");
		new_exprt = ft_strjoin(var, val);
		g_state.exprt = add_to_list(new_exprt, g_state.exprt, 1);
		free(val);
	}
	if (g_state.exprt == NULL)
		return (1);
	free(new_exprt);
	return (0);
}

int	parse_export(char *to_export)
{
	char	*variable;
	char	*valeur;
	int len;
	const	int prev = is_in_env(to_export);
	const	int old = is_in_env_assigned(to_export);

	(void)old;
	variable = NULL;
	valeur = NULL;
	if(prev >= 0 || old >= 0)
	{
		printf("%d",old);
		printf("%d",prev);
		if(old >= 0)
		{
			free(g_state.exprt[old]);
			if(!last_is_equal(to_export))
			{
				//bug is here
				len = until_this(to_export,"=");		
				printf("%s----\n",to_export + len + 2);
			char *temp;
				
				temp = ft_substr(to_export,0,until_this(to_export,"=") + 1);
				g_state.exprt[old] = ft_strjoin(temp,ft_str3join("\"",to_export + until_this(to_export,"=") + 1,"\""));
			}
			else
				g_state.exprt[old] = ft_strjoin(to_export,"\"\"");
			return(0);
			//g_state.exprt = remove_of_list(g_state.exprt[old],g_state.exprt);
		}
		else if(prev >= 0)
		{
			printf("%s\n",g_state.exprt[prev]);
			if(ft_strchr(g_state.exprt[prev],'='))
				return(0);
			free(g_state.exprt[prev]);
			g_state.exprt[prev] = ft_strdup(to_export);
			return(0);
		}

	}
	if (!no_equal(to_export))
	{
		printf("qui est tu\n");
		variable = ft_strdup("' '");
		valeur = ft_strdup(to_export);
		g_state.exprt = add_to_list(valeur, g_state.exprt, 1);
		if (g_state.exprt == NULL)
			return (1);
	}
	else
	{
		
		variable = before_equal(to_export);
		valeur = afther_equal(to_export);
		if (update_export_list(variable, valeur, 3) || \
		update_env_list(variable, valeur, 3))
			return (1);
	}
	free(variable);
	free(valeur);
	return (0);
}

int is_in_env(char *str)
{

	int inc; 
	inc = 0;
	inc = until_this(str,"=");
	 if(inc < 0)
	{
		inc = 0;
		while(g_state.exprt[inc])
			{
				if((ft_strncmp(str,g_state.exprt[inc],ft_strlen(str))) == 0)
					return(inc);
			inc++;
			}
		inc = 0;
	}
	printf("oula\n");
return(-1);
}

int is_in_env_assigned(char *str)
{

	int inc; 
	char *temp;

	inc = 0;
	temp = NULL;
	inc = until_this(str,"=");
	 if(inc < 0)
		 return(-1);
	 else
		temp = ft_substr(str,0,inc);
	inc = 0;
	while(g_state.exprt[inc])
		{
			if(!ft_strncmp(temp,g_state.exprt[inc] ,ft_strlen(temp)))
			{
				printf("found at index %d",inc);
				free(temp);	
				return(inc);
			}
			inc++;
		}
free(temp);
return(-1);
}


int	do_export(t_jobs *job)
{
	int	i;

	if (ft_tab_len(job->cmd) == 1)
		print_exprt(ft_tab_len(g_state.exprt));
	if (ft_tab_len(job->cmd) > 1)
	{
		i = 0;
		while (job->cmd[++i])
		{
			is_in_env_assigned(job->cmd[i]);
			//is_in_env(job->cmd[i]);
			if (got_good_args(job->cmd[i]))
				return (error_message("Not a valid export\n"));
			else if (last_is_equal(job->cmd[i]))
			{
				//temp fix here
					if(is_in_env_assigned(job->cmd[i]) < 0)
				{
					update_export_list(job->cmd[i], "\"\"", 1);
					update_env_list(job->cmd[i], "\"\"", 1);
				}
				else
					parse_export(job->cmd[i]);	

				return (1);
			}
			else
				if (parse_export(job->cmd[i]))
					return (1);
		}
	}
	return (0);
}
