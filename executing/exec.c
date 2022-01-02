/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:49:42 by olabrecq          #+#    #+#             */
/*   Updated: 2022/01/02 20:03:11 by jemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Cette fonction cree et init la struct s_exec: ENV & EXPORT
void init_exec(char **envp)
{
    create_env(envp);
    create_export(envp);
}

