NAME  = search_and_replace
CC  =  c++
CFLAGS  =  -Wall -Wextra -Werror -std=c++98 -I./

SRC =  main.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME) *.replace

fclean: clean

re: fclean all
