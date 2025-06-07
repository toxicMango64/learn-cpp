#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <sstream>
# include <iomanip>
# include <cmath>
# include <stack>

class evaluator
{
private:
    std::stack<double> _operands;
    bool _isOperator(std::string token);
    bool _isOperand(std::string token);
    void _doOperation(char op);
public:
    evaluator();
    evaluator(evaluator const &src);
    ~evaluator();
    evaluator &operator=(evaluator const &src);
    double evaluate(std::string expression);

    class EvaluateErrorException : public std::exception {
        public:
            EvaluateErrorException(const std::string& message);
            virtual ~EvaluateErrorException() throw() {};
            virtual const char *what() const throw();
        private:
            std::string _message;
    };
};

#endif