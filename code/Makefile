# Compiler and compiler flags

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Executable name
NAME = push_swap

# Source and object files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Main rule to build the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Clean rule
clean:
	rm -f $(OBJ)

# Full clean rule
fclean: clean
	rm -f $(NAME)

# Rebuild rule
re: fclean all

# Default rule
all: $(NAME)

.PHONY: all clean fclean re
