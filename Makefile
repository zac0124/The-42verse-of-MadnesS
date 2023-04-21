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

SOURCE = game_logic/*.c

GETNEXTLINE = get_next_line/*.c

LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit

MINILIBX = minilibx/

all: 
		make -C $(MINILIBX)
		$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) $(MINILIBX) -o $(NAME)
clean: 
