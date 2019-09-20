/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:47:26 by rsilva            #+#    #+#             */
/*   Updated: 2018/03/06 11:47:31 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long val;

	val = n;
	if (val < 0)
	{
		ft_putchar_fd('-', fd);
		val = -val;
	}
	if (val / 10 > 0)
		ft_putnbr_fd(val / 10, fd);
	ft_putchar_fd(val % 10 + 48, fd);
}
