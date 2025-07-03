# Copyright [2025] <myousaf>

NAME	:=	PmergeMe
CC		:=	c++
CFLAGS	:=	-Wall -Wextra -Werror -std=c++98
MKDIR	:=	mkdir -p

SRC	:=	main.cpp

OBJ_PATH	:=	./obj/
OBJ := $(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))

$(OBJ_PATH)%.o: %.cpp
	$(MKDIR) $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I $(OBJ_PATH) -o $(NAME)

PHONY := all
all: $(NAME)

PHONY += clean
clean:
	$(RM) -r $(OBJ) $(OBJ_PATH)

PHONY += fclean
fclean: clean
	$(RM) $(NAME)

PHONY += re
re: fclean all

.PHONY: ${PHONY}
