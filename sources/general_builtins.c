/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:34:02 by rsilva            #+#    #+#             */
/*   Updated: 2019/04/18 22:42:23 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_env **env, char **tkns)
{
	int		i;
	char	n;

	i = 1;
	n = 1;
	(void)env;
	if (!tkns[1])
		return ;
	if (tkns[i] && !(n = ft_strcmp(tkns[i], "-n")))
		i++;
	if (tkns[i])
	{
		write(1, tkns[i], ft_strlen(tkns[i]));
		i++;
	}
	while (tkns[i])
	{
		write(1, " ", 1);
		write(1, tkns[i], ft_strlen(tkns[i]));
		i++;
	}
	if (n)
		write(1, "\n", 1);
}

void	ft_cd(t_env **env, char **tkns)
{
	int		ac;
	char	prev[256];

	ac = 0;
	getcwd(prev, 256);
	while (tkns[ac])
		ac++;
	if (ac == 1)
		if (chdir(search_env(*env, "HOME")))
			print_file_not_found(search_env(*env, "HOME"));
	if (ac == 2)
	{
		if (!ft_strcmp(tkns[1], "-"))
		{
			if (chdir(search_env(*env, "OLDPWD")))
				print_file_not_found(search_env(*env, "OLDPWD"));
		}
		else if (chdir(tkns[1]))
			print_file_not_found(tkns[1]);
	}
	update_env(*env, "OLDPWD", prev);
}

void	ft_exit(t_env **env, char **t)
{
	free_env(env);
	if (t[1])
		exit(ft_atoi(t[1]));
	exit(0);
}
