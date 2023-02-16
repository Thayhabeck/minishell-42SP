/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 06:34:38 by matcardo          #+#    #+#             */
/*   Updated: 2023/02/16 13:34:14 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data g_data;

void	print_color_char(int index, char c)
{
	if (index < 12)
		printf("\e[38;5;%dm%c\e[0m", 82, c);
	else if (index < 24)
		printf("\e[38;5;%dm%c\e[0m", 83, c);
	else if (index < 36)
		printf("\e[38;5;%dm%c\e[0m", 84, c);
	else if (index < 48)
		printf("\e[38;5;%dm%c\e[0m", 85, c);
	else if (index < 60)
		printf("\e[38;5;%dm%c\e[0m", 86, c);
	else
		printf("\e[38;5;%dm%c\e[0m", 87, c);
}

void	print_startup(void)
{
	int		fd;
	char	buff[1];
	int		index;

	fd = open("./src/assets/startup.txt", O_RDONLY);
	if (fd == -1)
		return ;
	printf("\n");
	index = 0;
	while (read(fd, buff, 1))
	{
		if (index < 74)
			print_color_char(index, buff[0]);
		else
		{
			index = 0;
			print_color_char(index, buff[0]);
		}
		index++;
	}
	printf("\n");
	close(fd);
	return ;
}

void	init_minishell(char **envp)
{
	print_startup();
	g_data.envp = envp;
	store_env_variables(envp);
	g_data.exit_code = 0;
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1 && argv)
		return (1);
	init_minishell(envp);
	start_minishell();
	finish_minishell();
	return (0);
}
