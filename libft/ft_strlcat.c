/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:28:03 by rsilva            #+#    #+#             */
/*   Updated: 2018/02/27 15:28:16 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	while (dst[a] && a < dstsize)
		a++;
	if (a == dstsize)
	{
		while (src[b])
			b++;
		return (dstsize + b);
	}
	while (a + b < dstsize - 1 && src[b])
	{
		dst[a + b] = src[b];
		b++;
	}
	dst[a + b] = '\0';
	return (a + ft_strlen(src));
}
