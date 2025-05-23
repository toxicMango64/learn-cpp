# Copyright [2025] <myousaf>
NAME = iter
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
MKDIR := mkdir -p

SRC = main.cpp

OBJ_DIR = obj
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

PHONY := all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

PHONY += clean
clean:
	$(RM) -r $(OBJ_DIR)

PHONY += fclean
fclean: clean
	$(RM) $(NAME)

PHONY += re
re: fclean all

.PHONY: ${PHONY}
