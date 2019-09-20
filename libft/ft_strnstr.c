/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:37:19 by rsilva            #+#    #+#             */
/*   Updated: 2018/02/26 16:46:06 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	while (haystack[i] && i + nlen <= len)
	{
		if (ft_strncmp((haystack + i), needle, nlen) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
