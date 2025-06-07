NAME		= PmergeMe
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98# -Wshadow
RM	= rm -fr

SRC :=	main.cpp \
		PmergeMe.cpp

OBJ_PATH	=./obj/
OBJ			= $(addprefix $(OBJ_PATH), $(notdir $(SRC:.cpp=.o)))
$(OBJ_PATH)%.o: %.cpp
	@mkdir -p $(OBJ_PATH)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -I $(OBJ_PATH) -o $(NAME)

PHONY := all
all:		$(NAME)

PHONY += clean
clean:
	$(RM) $(OBJ) $(OBJ_PATH)

PHONY += fclean
fclean: clean
	$(RM) $(NAME)

PHONY += re
re: fclean all

.PHONY = ${PHONY}
