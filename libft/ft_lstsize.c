/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 20:56:52 by rsilva            #+#    #+#             */
/*   Updated: 2018/03/07 20:56:57 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *begin_list)
{
	int i;

	i = 0;
	if (begin_list == NULL)
		return (0);
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
