# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 13:46:10 by zmunkhja          #+#    #+#              #
#    Updated: 2023/01/31 17:33:06 by zmunkhja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = gcc
FLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers -L$(PRINTF) -lftprintf

PRINTF = printf

all:
	@make -s -C $(PRINTF)
	@gcc $(FLAGS) server.c -o $(SERVER)
	@gcc $(FLAGS) client.c -o $(CLIENT)
	@echo "SERVER CLIENT OBJECTS COMPILED !!!"

clean:
	@make clean -s -C $(PRINTF)

fclean: clean
	@make fclean -s -C $(PRINTF)
	@rm -f $(SERVER) $(CLIENT)
	@echo "CLEANED!!!"

re: fclean all
