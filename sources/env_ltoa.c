/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:50:18 by rsilva            #+#    #+#             */
/*   Updated: 2019/04/17 16:57:54 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	env_lstlen(t_env *e)
{
	size_t	l;

	l = 0;
	while (e)
	{
		l++;
		e = e->next;
	}
	return (l);
}

char	**env_ltoa(t_env *env)
{
	int		i;
	int		l;
	char	**a;
	t_env	*eptr;

	i = 0;
	l = 0;
	eptr = env;
	a = malloc(sizeof(char *) * (env_lstlen(env) + 1));
	while (env)
	{
		l = ft_strlen(env->key) + ft_strlen(env->value) + 2;
		a[i] = ft_memalloc(l);
		ft_strcat(a[i], env->key);
		ft_strcat(a[i], "=");
		ft_strcat(a[i], env->value);
		env = env->next;
		i++;
	}
	a[i] = NULL;
	return (a);
}
