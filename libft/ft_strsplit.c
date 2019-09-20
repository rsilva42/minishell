/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 00:45:33 by rsilva            #+#    #+#             */
/*   Updated: 2018/03/05 00:45:40 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *s, size_t i, char c)
{
	size_t wlen;

	wlen = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		wlen++;
	}
	return (wlen);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	wlen;
	size_t	wnum;
	char	**ret;

	i = 0;
	wnum = 0;
	if (!s || !(ret = malloc(sizeof(char *) * ((ft_wordcount(s, c)) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			wlen = ft_wordlen(s, i, c);
			ret[wnum] = ft_strsub(s, i, wlen);
			if (!ret[wnum])
				return (ret);
			i = i + wlen;
			wnum++;
		}
	}
	ret[wnum] = NULL;
	return (ret);
}
