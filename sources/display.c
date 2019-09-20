/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 10:58:26 by rsilva            #+#    #+#             */
/*   Updated: 2019/04/18 22:29:46 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_env(t_env *eptr)
{
	while (eptr)
	{
		write(1, eptr->key, ft_strlen(eptr->key));
		write(1, "=", 1);
		write(1, eptr->value, ft_strlen(eptr->value));
		write(1, "\n", 1);
		eptr = eptr->next;
	}
}

void		print_prompt(void)
{
	write(1, "Dogsh $> ", 9);
}

void		print_not_found(char *command)
{
	write(2, "Dogsh: ", 7);
	write(2, command, ft_strlen(command));
	write(2, ": command not found\n", 20);
}

void		print_file_not_found(char *file)
{
	write(2, "Dogsh: cd: no such directory: ", 30);
	write(2, file, ft_strlen(file));
	write(2, "\n", 1);
}

void		print_invalid_token(char *token)
{
	write(2, "Dogsh: setenv: invalid token: ", 30);
	write(2, token, ft_strlen(token));
	write(2, "\n", 1);
}
