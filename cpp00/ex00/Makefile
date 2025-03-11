NAME  =  megaphone

CC  =  c++
CFLAGS  =  -Wall -Wextra -Werror
STD  =  -std=c++98

SRC  =  megaphone.cpp

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(STD) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -fr $(NAME)

fclean: clean

re: fclean all
