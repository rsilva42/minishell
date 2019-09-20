/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 22:46:09 by rsilva            #+#    #+#             */
/*   Updated: 2018/03/06 22:46:15 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ret;

	ret = (t_list *)ft_memalloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	if (content)
	{
		ret->content_size = content_size;
		ret->content = ft_memalloc(content_size);
		ft_memcpy(ret->content, content, content_size);
	}
	return (ret);
}
