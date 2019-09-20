/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:51:07 by rsilva            #+#    #+#             */
/*   Updated: 2018/03/06 11:51:09 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	int		isneg;
	char	*ret;

	isneg = 1;
	if (!(ret = malloc((sizeof(char) * (ft_intlen(n) + 1)))))
		return (NULL);
	ret[ft_intlen(n)] = '\0';
	if (n == 0)
		ret[0] = '0';
	else if (n > 0)
	{
		n = -n;
		isneg = 0;
	}
	else
		ret[0] = '-';
	i = ft_intlen(n) + isneg - 2;
	while (i >= isneg)
	{
		ret[i] = (-(n % 10)) + 48;
		n = n / 10;
		i--;
	}
	return (ret);
}
