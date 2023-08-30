NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror/

SOURCE = source/*.c

OBJECT	= $(:%.o=%.c)

R = "\033[31m"
G = "\033[32m"

$(NAME): $(OBJECT)
	@echo $G "Compiling!"
	$(CC) $(CFLAGS) $(SOURCE) -o $(NAME)
	@echo $G "Done!"

all: $(NAME)

clean:
	rm -rf $(OBJECT)
	@echo $R "Removed object files!"

fclean: clean
	rm -rf $(NAME)
	@echo $R "Removed philo!"

	
re: fclean all

.PHONY: all, clean, fclean, re