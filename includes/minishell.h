/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:19:13 by rsilva            #+#    #+#             */
/*   Updated: 2019/04/18 20:35:21 by rsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include "libft.h"

# define BUFF_SIZE 4096
# define BLTIN_COUNT 6

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_builtin
{
	char			*name;
	void			(*func)(t_env **, char **);
}					t_builtin;

void				print_env(t_env *eptr);
void				print_prompt(void);
void				print_not_found(char *command);
void				print_file_not_found(char *file);
void				print_invalid_token(char *token);

int					check_input(char *in);
void				parse_env_token(char *t, char **key, char **val);
void				ft_env(t_env **env, char **tkns);
void				ft_setenv(t_env **env, char **tkns);
void				ft_unsetenv(t_env **env, char **tkns);

size_t				env_lstlen(t_env *e);
char				**env_ltoa(t_env *env);

void				update_env(t_env *eptr, char *key, char *value);
char				*search_env(t_env *eptr, char *key);
void				push_env(t_env **head, char *raw_str);
void				pop_env(t_env **head, char *key);
t_env				*init_env_node(char *key, char *value);

void				ft_echo(t_env **env, char **args);
void				ft_cd(t_env **env, char **args);
void				ft_exit(t_env **env, char **t);

size_t				count_tokens(char *s);
char				**break_input(char *line);
void				clean_empty(char ***tkns, int len, int e);
void				expand(t_env *env, char ***tokens);
char				**lexer(t_env *env, char *line);

void				free_env(t_env **env);
void				free_tokens(char **tokens);

t_env				*ft_setup(char **ev);
void				ft_userloop(t_env *env_head);

t_builtin			*set_builtin(char *n, void (*f)(t_env **, char **));
t_builtin			**init_builtins(void);
int					search_builtin(t_env **env,
					char **tokens, t_builtin **bltins);

char				*ft_pathcat(char *s1, const char *s2);
char				*ft_pathjoin(char const *s1, char const *s2);
void				try_paths(char **tkns, t_env *env_lst);
void				search_path(char **tkns, t_env *env_lst);

#endif
