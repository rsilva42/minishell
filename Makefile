# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsilva <rsilva@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/10 23:44:31 by rsilva            #+#    #+#              #
#    Updated: 2019/04/19 00:04:54 by rsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIB = libft
LIB_LINK = -L $(LIB) -l ft
LIB_INC = -I $(LIB)
CCFLAGS = -c -Wall -Wextra -Werror
SRCS =	sources/display.c\
		sources/env_builtins.c\
		sources/env_ltoa.c\
		sources/environment.c\
		sources/general_builtins.c\
		sources/input.c\
		sources/memory_management.c\
		sources/minishell.c\
		sources/search_builtin.c\
		sources/search_path.c
OBJS =	objects/display.o\
		objects/env_builtins.o\
		objects/env_ltoa.o\
		objects/environment.o\
		objects/general_builtins.o\
		objects/input.o\
		objects/memory_management.o\
		objects/minishell.o\
		objects/search_builtin.o\
		objects/search_path.o
INCLS = -I includes $(LIB_INC)

all: $(NAME)

objects/%.o: sources/%.c
	@/bin/mkdir -p objects
	@gcc $(CCFLAGS) $(INCLS) $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIB)
	@gcc $(OBJS) $(LIB_LINK) -o $(NAME)

clean:
	@make -C $(LIB) clean
	@/bin/rm -f $(OBJS)

fclean: clean
	@make -C $(LIB) fclean
	@/bin/rm -f $(NAME)

re: fclean all
