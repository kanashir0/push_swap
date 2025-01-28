# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyasuhir <gyasuhir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 14:58:26 by gyasuhir          #+#    #+#              #
#    Updated: 2025/01/28 09:26:47 by gyasuhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN = main.c
SRCS = stack.c \
		ft_split.c \
		ft_strlen.c \
		ft_strlcpy.c

VALGRIND_LOG = valgrind.log

INCLUDES = stack.h

OBJECTS = $(SRCS:%.c=%.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJECTS)
	cc -Wall -Wextra -Werror main.c $(NAME).a -o $(NAME)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@
	ar rcs $(NAME).a $@

clean:
	rm -f $(OBJECTS) $(NAME).a

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind:
	@valgrind --leak-check=full \
	--show-reachable=yes \
	--show-leak-kinds=all -s \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) \
	./$(NAME)
	@cat $(VALGRIND_LOG)

.PHONY: all bonus clean fclean re