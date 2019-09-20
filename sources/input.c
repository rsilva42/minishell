/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:13:09 by rsilva            #+#    #+#             */
/*   Updated: 2019/04/19 00:04:43 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t		count_tokens(char *s)
{
	size_t	i;
	size_t	wc;
	size_t	inword;

	i = 0;
	wc = 0;
	inword = 0;
	while (s[i])
	{
		if (s[i] != ' ' && !(s[i] >= '\t' && s[i] <= '\r') && inword == 0)
		{
			inword = 1;
			wc++;
		}
		else if ((s[i] == ' ' || s[i] == '\t') && inword == 1)
			inword = 0;
		i++;
	}
	return (wc);
}

char		**break_input(char *line)
{
	size_t		i;
	size_t		k;
	size_t		wc;
	char		**tokens;

	i = 0;
	wc = 0;
	tokens = malloc(sizeof(char *) * (count_tokens(line) + 1));
	while (line[i])
		if (line[i] == ' ' || (line[i] >= '\t' && line[i] <= '\r'))
			i++;
		else
		{
			k = i;
			while (line[k] && line[k] != ' '
			&& !(line[k] >= '\t' && line[k] <= '\r'))
				k++;
			tokens[wc] = ft_strsub(line, i, k - i);
			wc++;
			i = k;
		}
	tokens[wc] = NULL;
	return (tokens);
}

void		clean_empty(char ***tkns, int len, int e)
{
	int		i;
	char	**r;

	r = ft_memalloc(sizeof(char *) * e + 1);
	i = 0;
	e = 0;
	while (i < len)
	{
		if ((*tkns)[i])
		{
			r[e] = (*tkns)[i];
			e++;
		}
		i++;
	}
	r[e] = NULL;
	free(*tkns);
	*tkns = r;
}

void		expand(t_env *env, char ***tokens)
{
	int		i;
	int		exist;
	char	*tptr;

	i = 0;
	exist = 0;
	while ((*tokens)[i])
	{
		if (!ft_strcmp((*tokens)[i], "~"))
		{
			free((*tokens)[i]);
			(*tokens)[i] = ft_strdup(search_env(env, "HOME"));
		}
		else if ((tptr = ft_strchr((*tokens)[i], '$')))
		{
			tptr = ft_strdup(search_env(env, tptr + 1));
			free((*tokens)[i]);
			(*tokens)[i] = tptr;
		}
		if ((*tokens)[i])
			exist++;
		i++;
	}
	clean_empty(tokens, i, exist);
}

char		**lexer(t_env *env, char *line)
{
	char		**tokens;

	tokens = break_input(line);
	expand(env, &tokens);
	return (tokens);
}
