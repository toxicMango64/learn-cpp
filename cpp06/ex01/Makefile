NAME = serialize
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98

SRC =	./Data.cpp \
		./main.cpp \
		./Serializer.cpp

OBJ_DIR = obj
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

PHONY := all
all: $(NAME)

$(NAME): $(OBJ)
<<<<<<< HEAD
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
=======
	c++ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	c++ $(CC) $(CFLAGS) -c $< -o $@
>>>>>>> 71d067d01b6401f17885ad9cb6b96ebae5df7352

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

<<<<<<< HEAD
.PHONY: ${PHONY}
=======
.PHONY: ${PHONY}
>>>>>>> 71d067d01b6401f17885ad9cb6b96ebae5df7352
