NAME		= phonebook

OBJ_PATH	=./obj/
# add a rule that also makes teh asmmbely files of these C++ codes as well

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98# -Ofast

RM			= rm -rf

SRC 		= main.cpp \
			contact.cpp \
			phonebook.cpp 

OBJ 		= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))

$(OBJ_PATH)%.o: %.cpp
			mkdir -p $(OBJ_PATH)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all:		$(NAME)

re:			fclean all

clean:
			$(RM) $(OBJ) $(OBJ_PATH)

fclean:		clean
			$(RM) $(NAME)


# NAME		= phonebook

# OBJ_PATH	= ./obj/
# ASM_PATH	= ./asm/  # Path to store assembly files

# CC			= c++
# CFLAGS		= -Wall -Wextra -Werror -std=c++98 -Ofast

# RM			= rm -rf

# SRC 		= main.cpp \
# 			Contact.cpp \
# 			Phonebook.cpp 

# OBJ 		= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))
# ASM 		= $(addprefix $(ASM_PATH), $(notdir $(SRC:.cpp=.s)))

# # Rule to create object files
# $(OBJ_PATH)%.o: %.cpp
# 			mkdir -p $(OBJ_PATH)
# 			$(CC) $(CFLAGS) -c $< -o $@

# # Rule to create assembly files
# $(ASM_PATH)%.s: %.cpp
# 			mkdir -p $(ASM_PATH)
# 			$(CC) $(CFLAGS) -S $< -o $@

# # Target to build the executable
# $(NAME): $(OBJ)
# 			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# # Target to build all
# all: $(NAME) $(ASM)

# # Ensure assembly files are built
# $(ASM): $(SRC)
# 		@for src in $(SRC); do \
# 			$(CC) $(CFLAGS) -S $$src -o $(ASM_PATH)$$src.s; \
# 		done

# re:			fclean all

# clean:
# 			$(RM) $(OBJ) $(OBJ_PATH) $(ASM) $(ASM_PATH)

# fclean:		clean
# 			$(RM) $(NAME)