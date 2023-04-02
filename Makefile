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

OBJECT = $(SOURCE/%.c=object/%.o)

$(NAME):
	$(CC) $(FLAGS) $(SOURCE) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf source/*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all


test2:				$(NAME)
					$(eval ARG = $(shell jot -r 2 0 200))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo "Instruction count: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)
					$(eval ARG = $(shell jot -r 3 0 500))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo "Instruction count: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)
					$(eval ARG = $(shell jot -r 5 0 5000))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo "Instruction count: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)
					$(eval ARG = $(shell jot -r 100 0 50000))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo "Instruction count: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)
					$(eval ARG = $(shell jot -r 500 0 1000000))
					./push_swap $(ARG) | ./checker_Mac $(ARG)
					@echo "Instruction count: "
					@./push_swap $(ARG) | wc -l


.PHONY: all clean fclean re test2 test3 test5 test100 test500
