/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:03:04 by rsilva            #+#    #+#             */
/*   Updated: 2019/04/18 16:49:29 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		c;
	char	*ret;

	i = 0;
	c = 0;
	if (!src)
		return (NULL);
	while (src[i])
		i++;
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (c < i)
	{
		ret[c] = src[c];
		c++;
	}
	ret[c] = '\0';
	return (ret);
}
