/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:05:16 by matcardo          #+#    #+#             */
/*   Updated: 2023/02/18 11:01:43 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_prompt(void)
{
	char	*prompt;
	char	*path;
	char	*tmp;
	char	*tmp2;

	prompt = get_str_prompt();
	path = get_str_path();
	tmp = ft_strjoin(prompt, path);
	tmp2 = ft_strjoin(tmp, RESET_PROMPT);
	free(path);
	free(prompt);
	free(tmp);
	return (tmp2);
}

char	*get_str_prompt(void)
{
	char	*prompt;
	char	*tmp;

	tmp = ft_strjoin(getenv("USER"), "@minishell:");
	prompt = ft_strjoin(PROMPT_COLOR, tmp);
	free(tmp);
	return (prompt);
}

char	*get_str_path(void)
{
	char	*path;
	char	*home;
	char	*tmp;
	char	*tmp2;

	path = getcwd(NULL, 0);
	home = ft_strdup(getenv("HOME"));
	if (ft_strncmp(path, home, ft_strlen(home)) == 0)
	{
		tmp = ft_strjoin("~", &path[ft_strlen(home)]);
		tmp2 = ft_strjoin(PATH_COLOR, tmp);
		free(path);
		free(home);
		free(tmp);
		return (tmp2);
	}
	else
	{
		tmp = ft_strjoin(PATH_COLOR, path);
		free(path);
		free(home);
		return (tmp);
	}
}
