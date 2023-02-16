/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_minishell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 11:24:22 by matcardo          #+#    #+#             */
/*   Updated: 2023/02/16 13:36:18 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_closing(void)
{
	int		fd;
	char	buff[1];
	int		index;

	fd = open("./src/assets/closing.txt", O_RDONLY);
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

void	finish_free(void)
{
	free_hash_table();
}

void	finish_minishell(void)
{
	finish_free();
	rl_clear_history();
	print_closing();
}
