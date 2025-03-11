NAME  = violence
CC  =  c++
CFLAGS  =  -Wall -Wextra -Werror -std=c++98 -I./

SRC =  main.cpp \
	   HumanA.cpp \
	   HumanB.cpp \
	   Weapon.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
