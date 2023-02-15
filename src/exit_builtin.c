/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:23:59 by thabeck-          #+#    #+#             */
/*   Updated: 2023/02/14 18:32:22 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exit_builtin(char **cmds)
{
	int exit_status;

	exit_status = 0;
	if (cmds[1])
		exit_status = ft_atoi(cmds[1]);
	else
		exit_status = 0;
	free_command_table(g_data.command_table_expanded);
	free_pipes_and_pids();
	finish_minishell();
	exit(exit_status);
}