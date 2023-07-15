# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmunkhjargal <zmunkhjargal@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 16:32:28 by zmunkhja          #+#    #+#              #
#    Updated: 2023/07/10 19:23:25 by zmunkhjarga      ###   ########.fr        #
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
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)
	@echo "Done!"

all: $(NAME)

clean:
	make clean -C $(MINILIBX)
	@echo "minilibx clean done!"

fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all, clean, fclean, re