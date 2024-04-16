# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrhu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 10:44:06 by chrhu             #+#    #+#              #
#    Updated: 2023/11/22 16:34:19 by chrhu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	checker.c \
		srcs/ft_strncmp.c  srcs/get_next_line.c \
       srcs/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = checker

PUSH_SWAP_DIR = ../
PUSH_SWAP_ARCHIVE = $(PUSH_SWAP_DIR)/push_swap.a

all: $(NAME)

$(NAME): $(OBJS) $(PUSH_SWAP_ARCHIVE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PUSH_SWAP_ARCHIVE)

$(PUSH_SWAP_ARCHIVE):
	make -C $(PUSH_SWAP_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(PUSH_SWAP_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PUSH_SWAP_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

