NAME  =  megaphone
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS  =  megaphone.cpp
OBJS  =  $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

.PHONY: all clean fclean re
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: $(OBJS)
	$(CC) $(CXXFLAGS) -g $^ -o $(NAME)

test: $(NAME)
	./$(NAME)

valgrind: $(NAME)
	valgrind ./$(NAME)