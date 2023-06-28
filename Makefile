# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 16:32:28 by zmunkhja          #+#    #+#              #
#    Updated: 2023/04/21 16:32:42 by zmunkhja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iheaders/

SOURCE = logic/*.c

OBJECT	= $(:%.o=%.c)

GETNEXTLINE = get_next_line/*.c

LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit

MINILIBX = minilibx/

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)
	@echo "Done!"

all: $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re