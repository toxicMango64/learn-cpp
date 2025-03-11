NAME = animals

CC = c++
CFLAGS = -Wall -Wextra -Werror
STD = -std=c++98

OBJ_DIR = obj

SRC =  Animal.cpp \
	   Brain.cpp \
	   Cat.cpp \
	   Dog.cpp \
	   WrongAnimal.cpp \
	   WrongCat.cpp \
	   main.cpp

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(STD) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(STD) -c $< -o $@

clean:
	@rm -rf $(OBJ) $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re


# NAME = animals
# LIBNAME = lib$(NAME).so

# CC = c++
# CFLAGS = -Wall -Wextra -Werror -fPIC
# STD = -std=c++98
# LDFLAGS = -shared

# OBJ_DIR = obj

# SRC =  main.cpp


# OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# all: $(LIBNAME) $(NAME)

# $(LIBNAME): $(OBJ)
# 	$(CC) $(LDFLAGS) $(OBJ) -o $(LIBNAME)

# $(NAME): $(OBJ_DIR)/main.o
# 	$(CC) $(CFLAGS) $(STD) $(OBJ_DIR)/main.o -o $(NAME) -L. -l$(NAME)

# $(OBJ_DIR)/%.o: %.cpp
# 	mkdir -p $(OBJ_DIR)
# 	$(CC) $(CFLAGS) $(STD) -c $< -o $@

# clean:
# 	rm -rf $(OBJ) $(OBJ_DIR)/main.o

# fclean: clean
# 	rm -rf $(NAME) $(LIBNAME) $(OBJ_DIR)

# re: fclean all

# .PHONY: all clean fclean re
