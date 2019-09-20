/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 23:46:13 by rsilva            #+#    #+#             */
/*   Updated: 2019/04/16 00:20:39 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		update_env(t_env *eptr, char *key, char *value)
{
	while (eptr)
	{
		if (!ft_strcmp(eptr->key, key))
		{
			free(eptr->value);
			eptr->value = ft_strdup(value);
			return ;
		}
		eptr = eptr->next;
	}
}

char		*search_env(t_env *eptr, char *key)
{
	while (eptr)
	{
		if (!ft_strcmp(eptr->key, key))
			return (eptr->value);
		eptr = eptr->next;
	}
	return (NULL);
}

void		push_env(t_env **head, char *raw_str)
{
	char	*key;
	char	*value;
	char	*offset;
	t_env	*eptr;

	offset = ft_strchr(raw_str, '=');
	key = ft_strndup(raw_str, offset - raw_str);
	value = ft_strdup(offset + 1);
	if (!*head)
		*head = init_env_node(key, value);
	else
	{
		eptr = *head;
		while (eptr->next)
			eptr = eptr->next;
		eptr->next = init_env_node(key, value);
	}
}

void		pop_env(t_env **head, char *key)
{
	t_env	*eptr;
	t_env	*tptr;

	eptr = *head;
	if (!ft_strcmp((*head)->key, key))
		*head = (*head)->next;
	else
		while (eptr->next)
		{
			if (!(ft_strcmp(eptr->next->key, key)))
			{
				tptr = eptr;
				eptr = eptr->next;
				tptr->next = eptr->next;
				free(eptr->key);
				free(eptr->value);
				free(eptr);
				break ;
			}
			eptr = eptr->next;
		}
}

t_env		*init_env_node(char *key, char *value)
{
	t_env		*node;

	node = malloc(sizeof(t_env));
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}
