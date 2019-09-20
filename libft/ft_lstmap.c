/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 01:39:44 by rsilva            #+#    #+#             */
/*   Updated: 2018/03/07 01:39:46 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *tmp;

	if (lst)
	{
		tmp = NULL;
		ret = (*f)(lst);
		tmp = ret;
		lst = lst->next;
		while (lst)
		{
			tmp->next = (*f)(lst);
			tmp = tmp->next;
			lst = lst->next;
		}
		return (ret);
	}
	return (NULL);
}
