#include "RPN.hpp"

int main(int argc, char **argv) {
    evaluator rpn;

    if (argc != 2) {
        std::cout << "Usage: ./rpn \"<expression>\\n";
        return (1);
    }
    try {
        std::cout << rpn.evaluate(argv[1]) << "\n";
    }
    catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
    return (0);
}
