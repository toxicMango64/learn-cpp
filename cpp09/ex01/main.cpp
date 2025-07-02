#include "RPN.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>

static std::vector<std::string>	tokenize(const std::string &str);

static int	check_args(const int argc, const char * const *argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Invalid Number of Arguments\n";
		return(-1);		
	}
	return (0);
}

static bool is_digit(const char c) {
    return (c >= '0' && c <= '9');
}

static bool	is_operator(const char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}


int main(const int argc, const char * const *argv)
{
	std::vector<std::string>	tokens;
	RPN							rpn;
	size_t						n_tokens = 0;

	try	{
		if (check_args(argc, argv) == -1) {
			return (1);
		}
		tokens = tokenize(std::string(argv[1]));
		n_tokens = tokens.size();
		for (size_t i = 0; i < n_tokens; i++) {
			if (tokens[i].length() != 1) {
				std::cerr << "Invalid Token: " << tokens[i] << "\n";
				return (1);
			}
			if (is_digit(tokens[i][0])) {
				rpn.addNumber(tokens[i][0] - '0');
			}
			else if (is_operator(tokens[i][0])) {
				rpn.addOperand(tokens[i][0]);
			}
			else {
				std::cerr << "Invalid Token: " << tokens[i] << "\n";
				return (1);	
			}
		}
		std::cout << rpn.getResult() << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << "\n";
		return (1);
	}
}

static std::vector<std::string> tokenize(const std::string &str)
{
	std::istringstream			iss(str);
	std::vector<std::string>	tokens;
	std::string					token;

	while (iss >> token) {
		tokens.push_back(token);
	}
	return (tokens);
}
