NAME = animals

CC = c++
CFLAGS = -Wall -Wextra -Werror
STD = -std=c++98

OBJ_DIR = obj

SRC =  AMateria.cpp \
	   Character.cpp \
	   Cure.cpp \
	   Ice.cpp \
	   MateriaSource.cpp \
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
