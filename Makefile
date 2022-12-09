# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 02:09:58 by matcardo          #+#    #+#              #
#    Updated: 2022/11/15 06:37:28 by matcardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

SRCS			= $(wildcard src/*.c)
OBJS			= ${SRCS:src/%.c=objs/%.o}
HEADER			= src/minishell.h
OBJS_DIR		= objs/

RM				= rm -fr
CC				= gcc
FLAGS			= -Wall -Wextra -Werror

LIBFT			= ./libraries/libft/libft.a

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT)
			@printf "\n$(CY)Generating minishell executable...$(RC)\n"
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)
			@printf "$(GR)Done!$(RC)\n\n"

$(OBJS_DIR):
			mkdir $(OBJS_DIR)

objs/%.o: src/%.c
			@printf "\n$(CY)Generating object...$(RC)\n"
			${CC} ${FLAGS} -c $< -o ${<:src/%.c=objs/%.o}
			@printf "$(GR)Object ready!$(RC)"

$(LIBFT):
			@printf "\n$(CY)Generating libft...$(RC)\n"
			make -C ./libraries/libft
			@printf "$(GR)libft ready!$(RC)"

norm:
			norminette ${SRCS} ${HEADER}

clean:
			make -C ./libraries/libft clean
			$(RM) $(OBJS_DIR)
			@printf "$(RE)minishell objects removed!$(RC)\n\n"

fclean:		clean
			make -C ./libraries/libft fclean
			$(RM) $(NAME)
			@printf "$(RE)minishell executables removed!$(RC)\n\n"

re:			fclean all

.PHONY:		all clean fclean re