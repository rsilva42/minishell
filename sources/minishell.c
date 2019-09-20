/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:25:17 by rsilva            #+#    #+#             */
/*   Updated: 2019/04/19 00:03:34 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_setup(char **ev)
{
	size_t		i;
	size_t		shlvl;
	t_env		*new_env;

	i = 0;
	new_env = NULL;
	while (ev[i])
	{
		push_env(&new_env, ev[i]);
		i++;
	}
	shlvl = ft_atoi(search_env(new_env, "SHLVL"));
	update_env(new_env, "SHLVL", ft_itoa(shlvl + 1));
	return (new_env);
}

void	ft_userloop(t_env *env)
{
	size_t		read_len;
	char		buff[BUFF_SIZE];
	char		**tokens;
	t_builtin	**builtins;

	builtins = init_builtins();
	while ((read_len = read(0, buff, BUFF_SIZE - 1)) > 0)
	{
		buff[read_len - 1] = '\0';
		tokens = lexer(env, buff);
		if (tokens[0] && !search_builtin(&env, tokens, builtins))
			search_path(tokens, env);
		free_tokens(tokens);
		print_prompt();
	}
}

int		main(int ac, char **av, char **ev)
{
	t_env		*env_head;

	(void)ac;
	(void)av;
	env_head = ft_setup(ev);
	print_prompt();
	ft_userloop(env_head);
	return (EXIT_SUCCESS);
}
