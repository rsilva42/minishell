/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:23:59 by rsilva            #+#    #+#             */
/*   Updated: 2018/03/07 21:24:22 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	wnum;
	size_t	inword;

	i = 0;
	wnum = 0;
	inword = 0;
	while (s[i])
	{
		if (s[i] != c && inword == 0)
		{
			inword = 1;
			wnum++;
		}
		else if (s[i] == c && inword == 1)
			inword = 0;
		i++;
	}
	return (wnum);
}
