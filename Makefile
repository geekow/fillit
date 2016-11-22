# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 11:02:51 by jjacobi           #+#    #+#              #
#    Updated: 2016/11/22 18:27:03 by jjacobi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

CC			= gcc
FLAGS		= -g -Wall -Wextra -Werror

SRC_FILES	= main.c stock_tetri.c fillit.c try_to_place.c
OBJ			= $(SRC_FILES:.c=.o)

H_DIR		= ./includes
LIBFT_PATH	= ./libft
SRC_FOLDER	= ./srcs

GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m

all: $(NAME)

$(NAME): $(OBJ) libft.a
	@$(CC) $(FLAGS) -o $@ $(OBJ) $(LIBFT_PATH)/libft.a -I $(H_DIR)
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."

libft.a:
	@echo "$(DEFAULT)"
	@(cd $(LIBFT_PATH) && $(MAKE))

%.o: $(SRC_FOLDER)/%.c
	@$(CC) $(FLAGS) -c -o $@ $< -I $(H_DIR)
	@echo "$(GREEN). \c"

clean:
	@rm -rf $(OBJ)
	@(cd $(LIBFT_PATH) && $(MAKE) $@)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."

fclean:
	@rm -rf $(NAME) $(OBJ)
	@(cd $(LIBFT_PATH) && $(MAKE) $@)
	@echo "$(RED).o $(DEFAULT) are now deleted for $(NAME)."
	@echo "$(RED)$(NAME)$(DEFAULT) deleted."

re: fclean all

.PHONY: clean fclean re all
