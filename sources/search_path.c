/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:39:19 by rsilva            #+#    #+#             */
/*   Updated: 2019/04/19 00:00:31 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_pathcat(char *s1, const char *s2)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (ft_strcmp(s1, "/"))
	{
		while (s1[a])
			a++;
		s1[a] = '/';
	}
	a++;
	while (s2[b])
	{
		s1[a] = s2[b];
		a++;
		b++;
	}
	s1[a] = '\0';
	return (s1);
}

char		*ft_pathjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!(s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(s3, s1);
	ft_pathcat(s3, s2);
	return (s3);
}

void		try_paths(char **tkns, t_env *env_lst)
{
	int		i;
	char	**dirs;
	char	**env_arr;
	char	*cur_path;

	i = 0;
	env_arr = env_ltoa(env_lst);
	if (!(dirs = ft_strsplit(search_env(env_lst, "PATH"), ':')))
	{
		execve(tkns[0], tkns, env_arr);
		return ;
	}
	while (dirs[i])
	{
		cur_path = ft_pathjoin(dirs[i], tkns[0]);
		execve(cur_path, tkns, env_arr);
		free(dirs[i]);
		free(cur_path);
		i++;
	}
	execve(tkns[0], tkns, env_arr);
}

void		search_path(char **tkns, t_env *env_lst)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
		pid = wait(NULL);
	else if (!pid)
	{
		try_paths(tkns, env_lst);
		print_not_found(tkns[0]);
		exit(EXIT_FAILURE);
	}
	else
		write(2, "Dogsh: fork error\n", 18);
}
