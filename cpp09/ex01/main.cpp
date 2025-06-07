#include "RPN.hpp"

int main(int argc, char **argv) {
    evaluator rpn;

    if (argc != 2) {
        std::cout << "Usage: ./rpn \"<expression>\"" << std::endl;
        return (1);
    }
    try {
        std::cout << rpn.evaluate(argv[1]) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
