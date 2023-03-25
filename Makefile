# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmunkhja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 11:22:27 by zmunkhja          #+#    #+#              #
#    Updated: 2023/03/25 11:22:39 by zmunkhja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE = source/*.c
OBJECT = obj/


$(NAME):
	$(CC) $(FLAGS) $(SOURCE) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf sources/*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all


test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "TEST 2 Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "TEST 1000 Instructions: "
					@./push_swap $(ARG) | wc -l


.PHONY: all clean fclean re test2 test1000
