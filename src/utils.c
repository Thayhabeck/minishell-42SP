/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:28:02 by matcardo          #+#    #+#             */
/*   Updated: 2023/02/20 12:23:38 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	error_msg(char *cmd, char *msg, int status)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	g_data.exit_code = status;
}

void	eof_msg(char *redir)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("warning: here-document delimited", 2);
	ft_putstr_fd(" by end-of-file (wanted `", 2);
	ft_putstr_fd(redir, 2);
	ft_putstr_fd("')\n", 2);
}

char	*clear_quotes(char *var)
{
	char	*cmd;
	int		i;

	cmd = NULL;
	i = 0;
	while (var[i])
	{
		if ((var[i] != '\'') && (var[i] != '\"'))
		{
			cmd = ft_straddchar(cmd, var[i]);
		}
		i++;
	}
	return (cmd);
}
