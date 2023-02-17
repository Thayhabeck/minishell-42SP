/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_in_hashtable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:47:20 by matcardo          #+#    #+#             */
/*   Updated: 2023/02/16 13:47:25 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	insert_in_hashtable(char *envp)
{
	char			*key;
	char			*value;
	unsigned int	hash_index;
	t_env_var		*env_var;

	key = ft_substr(envp, 0, ft_strlen(envp) - ft_strlen(ft_strchr(envp, '=')));
	value = ft_substr(ft_strchr(envp, '='), 1, \
	ft_strlen(envp) - (ft_strlen(key) + 1));
	hash_index = hash_function(key) % TABLE_SIZE;
	env_var = (t_env_var *)malloc(sizeof(t_env_var *));
	env_var->key = key;
	env_var->value = value;
	ft_lstadd_back(&(g_data.hash_table[hash_index]), \
	ft_lstnew((void *)env_var));
}
