NAME  = zombie
CC  = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC =  Zombie.cpp \
       main.cpp \
       newZombie.cpp \
       randomChump.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
