NAME = megaphone
SOURCE = megaphone.cpp
OBJECT = $(SOURCE:.cpp=.o)
CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

all: $(NAME)

$(NAME) : $(OBJECT)
	$(CC) $(FLAGS) $(OBJECT) -o $(NAME)
	@echo "$(COLOUR_GREEN)Created a megaphone program!"
	@echo "Please run it as expected.$(COLOUR_END)"
clean:
	rm -f $(OBJECT)
	@echo "$(COLOUR_BLUE)Removed object file!$(COLOUR_END)"
fclean:
	rm -f $(NAME)
	@echo "$(COLOUR_RED)Cleaned everything!$(COLOUR_END)"

re: fclean $(NAME)

.PHONY: all clean fclean re
