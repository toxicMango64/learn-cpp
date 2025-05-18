NAME = identify
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRC =	./Base.cpp \
		./main.cpp

OBJ_DIR = obj
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

PHONY := all
all: $(NAME)

$(NAME): $(OBJ)
	c++ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	c++ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

PHONY += clean
clean:
	rm -rf $(OBJ_DIR)

PHONY += fclean
fclean: clean
	rm -rf $(NAME)

PHONY += re
re: fclean all

.PHONY: ${PHONY}
