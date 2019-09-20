/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:16:57 by rsilva            #+#    #+#             */
/*   Updated: 2018/02/26 16:26:17 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	a;
	size_t	nlen;

	a = 0;
	if (!*needle)
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	while (haystack[a])
	{
		if (ft_strncmp(needle, &(haystack[a]), nlen) == 0)
			return ((char *)haystack + a);
		a++;
	}
	return (0);
}
