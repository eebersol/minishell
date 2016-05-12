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

#Define the program

NAME			= minishell

LIB				=	./libft/libft.a

_SRC			= 	minishell.c \
						ft_cd.c \
						ft_exit.c \
						ft_signal.c \
						builtin_env/ft_env_set.c \
						builtin_env/ft_env_unset.c \
						builtin_env/ft_env_to_list.c \
						builtin_env/ft_env_get.c \
						builtin_env/ft_env_show.c \
						builtin_env/ft_env_opt.c \
						utils/ft_cut_title.c \
						utils/ft_free_node.c \
						utils/ft_get_path.c \
						utils/ft_join_path.c \
						utils/ft_lstlen.c \
						utils/ft_seek_wrong_opt.c \
						utils/ft_display_prompt.c\
						error/ft_error_cd.c \
						error/ft_error_env.c \
						error/ft_error_exit.c \
						error/ft_error_not_found.c \
						error/ft_error_set_unset_env.c

INCLUDES		= -I./libft/includes/ -I./includes/

SRC				= $(addprefix srcs/,$(_SRC))

OBJ				= $(SRC:.c=.o)

CFLAGS			= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	@gcc $(CFLAGS) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@echo $(NAME)" compiled"


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@echo "Clean all .o files"

fclean:	clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)
	@echo "Clean all .o and .a"

re: fclean all