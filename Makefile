# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eebersol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/08 19:11:03 by eebersol          #+#    #+#              #
#    Updated: 2016/04/08 19:11:04 by eebersol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= minishell

_SRCS 	= 

SRCS  	= $(addprefix srcs/,$(_SRCS))
LIBFT 	= -Llibft -lft -Ilibft
CFLAGS	= -Wall -Wextra -Werror
CC 		= gcc $(CFLAGS)

all		:$(NAME)

$(NAME)	:
	@make -C libft
	@$(CC) $(SRCS) -Iincludes -o $(NAME) $(LIBFT)
	@echo $(NAME) "Compiled"

clean	:
	@make fclean -C libft
	@/bin/rm -rf bin
	@echo "Clean all .o"

fclean	:
	@make fclean -C libft
	@/bin/rm -rf bin
	@/bin/rm -rf $(NAME)
	@echo "clean all .o .a"

re		: fclean all

.PHONY: all, clean, fclean, re