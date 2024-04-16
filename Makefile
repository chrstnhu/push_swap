INSTRUCTION_DIRS = instructions/push.c \
			instructions/reverse_rotate.c \
			instructions/rotate.c instructions/swap.c

PUSH_SWAP_DIRS = srcs/init_a.c srcs/init_b.c srcs/init_utils.c \
				srcs/sort_stacks_utils.c srcs/sort_stacks.c \
				srcs/sort_three.c srcs/verif_valid.c \
				srcs/stack_init.c srcs/stack_utils.c \
				srcs/free_stack.c

LIBFT_DIRS = libft/ft_atol.c \
			libft/ft_lstnew.c \
			libft/ft_lstadd_back.c \
			libft/ft_lstadd_front.c \
			libft/ft_lstclear.c \
			libft/ft_lstlast.c \
			libft/ft_split.c

SRCS = $(LIBFT_DIRS) $(INSTRUCTION_DIRS) $(PUSH_SWAP_DIRS) push_swap.c
OBJS = $(SRCS:.c=.o)

PUSHSWAP = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(PUSHSWAP)
	$(CC) $(CFLAGS) -o $(NAME) $^

$(PUSHSWAP): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(PUSHSWAP)

re: fclean all

.PHONY: all clean fclean re
