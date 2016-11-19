# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjacobi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 11:02:51 by jjacobi           #+#    #+#              #
#    Updated: 2016/11/19 15:19:14 by jjacobi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
SRC_FILES	= ft_putchar.c ft_putstr.c ft_strlen.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_strnew.c ft_strdel.c ft_memdel.c ft_memalloc.c \
	ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	ft_strsplit.c ft_itoa.c ft_putendl.c ft_putnbr.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c \
	ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_atoi.c ft_strncmp.c \
	ft_strcmp.c ft_strstr.c ft_strnstr.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_memcpy.c \
	ft_strchr.c ft_strrchr.c ft_memset.c ft_bzero.c ft_memccpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_lstnew.c ft_lstdelone.c \
	ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_sqrt.c \
	ft_split_whitespaces.c ft_sort_wordtab.c ft_lstsort.c ft_power.c
OBJ			= $(SRC_FILES:.c=.o)

GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(DEFAULT)"
	@ar rc $@ $^
	@ar -s $@
	@echo "$(GREEN)$(NAME)$(DEFAULT) created."

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(GREEN). \c"

clean:
	@rm -rf $(OBJ)
	@echo "All $(RED).o$(DEFAULT) are now deleted."

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME)$(DEFAULT) is now deleted."

re: fclean all

.PHONY: clean fclean re all
