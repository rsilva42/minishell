/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 23:42:03 by rsilva            #+#    #+#             */
/*   Updated: 2019/04/17 23:44:18 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_input(char *in)
{
	if (!ft_strchr(in, '='))
		return (1);
	return (0);
}

void	parse_env_token(char *t, char **key, char **val)
{
	char	*offset;

	offset = ft_strchr(t, '=');
	*key = ft_strndup(t, offset - t);
	*val = ft_strdup(offset + 1);
}

void	ft_env(t_env **env, char **tkns)
{
	(void)tkns;
	print_env(*env);
}

void	ft_setenv(t_env **env, char **tkns)
{
	int		i;
	char	*key;
	char	*val;

	i = 1;
	while (tkns[i])
	{
		if (check_input(tkns[i]))
		{
			print_invalid_token(tkns[i]);
			i++;
			continue ;
		}
		parse_env_token(tkns[i], &key, &val);
		if (search_env(*env, key))
			update_env(*env, key, val);
		else
			push_env(env, tkns[i]);
		free(key);
		free(val);
		i++;
	}
}

void	ft_unsetenv(t_env **env, char **tkns)
{
	int		i;

	i = 1;
	(void)tkns;
	while (tkns[i])
	{
		pop_env(env, tkns[i]);
		i++;
	}
}
