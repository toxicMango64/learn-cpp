NAME = Bureaucrat
CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror
STD = -std=c++98

SRC =	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

$(NAME): $(SRC)
	$(CPP) $(CPP_FLAGS) $(STD) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -fr $(NAME)

fclean: clean
		rm -f *_shrubbery

re: fclean all
