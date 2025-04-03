# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 14:58:26 by gyasuhir          #+#    #+#              #
#    Updated: 2025/04/03 20:08:44 by gyasuhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler vars
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	main.c \
		stack_init.c \
		stack_utils.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		sort_three.c \
		handle_errors.c

OBJECTS = $(SRCS:%.c=%.o)

NAME = push_swap

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME) $(LIBFT) $(PRINTF)

$(NAME): $(OBJECTS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

valgrind:
	valgrind --leak-check=full \
	--show-reachable=yes \
	--show-leak-kinds=all -s \
	--track-origins=yes \
	./$(NAME)

clean:
	rm -f $(OBJECTS)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re valgrind