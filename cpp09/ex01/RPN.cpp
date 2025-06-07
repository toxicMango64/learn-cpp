#include "RPN.hpp"

evaluator::evaluator(void) { }

evaluator::evaluator(evaluator const &src) { *this = src; }

evaluator::~evaluator(void) { }

evaluator &evaluator::operator=(evaluator const &src) {
    if (this != &src)
        *this = src;
    return (*this);
}

double evaluator::evaluate(std::string expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (_isOperand(token))
            _operands.push(std::strtod(token.c_str(), NULL));
        else if (_isOperator(token))
            try {
                _doOperation(token.begin()[0]);
            } catch (std::exception &e) {
                throw EvaluateErrorException(e.what());
            }
        else
            throw EvaluateErrorException("Invalid token: " + token);
    }
    if (_operands.size() != 1)
        throw EvaluateErrorException("Invalid expression: More or less than one operand left on stack.");
    return (_operands.top());
}

bool evaluator::_isOperator(std::string token) {
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return (true);
    return (false);
}

bool evaluator::_isOperand(std::string token) {
    if (token.empty()) {
        return false;
    }
    char* end = NULL;
    double val = std::strtod(token.c_str(), &end);
    if (end == token.c_str() + token.size() && val >= 0 && val <= 9) {
        return true;
    }
    return false;
}

void evaluator::_doOperation(char op) {
    double result = 0;
    double op1 = 0;
    double op2 = 0;

    if (_operands.size() < 2)
        throw EvaluateErrorException("Invalid expression: Not enough operands for operator.");
    op2 = _operands.top();
    _operands.pop();
    op1 = _operands.top();
    _operands.pop();
    switch (op)
    {
    case '+':
        result = op1 + op2;
        break;
    case '-':
        result = op1 - op2;
        break;
    case '*':
        result = op1 * op2;
        break;
    case '/':
        if (op2 == 0){
            throw EvaluateErrorException("Division by zero.");
            return ;
        }
        result = op1 / op2;
        break;
    default:
        throw EvaluateErrorException("Unknown operator: " + std::string(1, op));
        return ;
    }
    _operands.push(result);
    return ;
}

evaluator::EvaluateErrorException::EvaluateErrorException(const std::string& message) : _message(message) {
    return ;
}

const char *evaluator::EvaluateErrorException::what() const throw() {
    return (_message.c_str());
}
