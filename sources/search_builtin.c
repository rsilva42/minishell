/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:00:23 by rsilva            #+#    #+#             */
/*   Updated: 2019/04/17 15:15:08 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	*set_builtin(char *n, void (*f)(t_env **, char **))
{
	t_builtin	*b;

	b = malloc(sizeof(t_builtin));
	b->name = ft_strdup(n);
	b->func = f;
	return (b);
}

t_builtin	**init_builtins(void)
{
	t_builtin	**bltins;

	bltins = malloc(sizeof(t_builtin) * BLTIN_COUNT + 1);
	bltins[0] = set_builtin("echo", (*ft_echo));
	bltins[1] = set_builtin("cd", (*ft_cd));
	bltins[2] = set_builtin("env", (*ft_env));
	bltins[3] = set_builtin("setenv", (*ft_setenv));
	bltins[4] = set_builtin("unsetenv", (*ft_unsetenv));
	bltins[5] = set_builtin("exit", (*ft_exit));
	bltins[BLTIN_COUNT] = NULL;
	return (bltins);
}

int			search_builtin(t_env **env, char **tokens, t_builtin **bltins)
{
	int		i;

	i = 0;
	while (bltins[i])
	{
		if (!ft_strcmp(bltins[i]->name, tokens[0]))
		{
			bltins[i]->func(env, tokens);
			return (1);
		}
		i++;
	}
	return (0);
}
