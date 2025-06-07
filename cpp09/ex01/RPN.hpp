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
    void _doOperation(char op);
public:
    evaluator();
    evaluator(evaluator const &src);
    ~evaluator();
    evaluator &operator=(evaluator const &src);
    double evaluate(const std::string &expression);

    class EvaluateErrorException : public std::exception {
    private:
        std::string _message;
    public:
        EvaluateErrorException(const std::string& message);
        virtual ~EvaluateErrorException() throw() {};
        virtual const char *what() const throw();
    };
};

#endif