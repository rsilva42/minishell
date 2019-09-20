/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:12:03 by rsilva            #+#    #+#             */
/*   Updated: 2019/04/18 20:34:36 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_env **env)
{
	t_env	*eptr;

	eptr = *env;
	while (*env)
	{
		eptr = (*env)->next;
		free((*env)->key);
		free((*env)->value);
		free(*env);
		*env = eptr;
	}
}

void	free_tokens(char **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
