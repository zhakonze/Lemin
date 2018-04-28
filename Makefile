# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 10:52:05 by zhakonze          #+#    #+#              #
#    Updated: 2017/07/13 15:08:08 by zhakonze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lemin

FLAGS = -Werror -Wall -Wextra

SRCS =	checks.c creation.c destroy.c main.c misc.c misc2.c bfs.c bfs2.c paths.c \
		paths2.c antUpdates.c

LIB = -L libft/ -lft

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft
	gcc -o $(NAME) $(SRCS) $(LIB)

clean:
	rm -f $(NAME)

fclean: clean
	@$(MAKE) -C libft fclean
re: fclean all
