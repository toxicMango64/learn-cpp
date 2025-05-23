// Copyright [2025] <myousaf>
#include "Span.hpp"

int main(void) {

    std::cout << "------ Test as in subject ------" << "\n";
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << "\n";
    std::cout << sp.longestSpan() << "\n";

    std::cout << "------ Test with exception ------" << "\n";
    try {
        sp.addNumber(1);
    }
    catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "------ Test with a minimum of 10000 elements ------" << "\n";
    Span sp3 = Span(10000);
    std::srand(time(NULL));
    for (int i = 0; i < 10000; i++)
        sp3.addNumber(std::rand() % 10000);
    std::cout << sp3.shortestSpan() << "\n";
    std::cout << sp3.longestSpan() << "\n";    

    std::cout << "------ Test with a minimum of 100000 elements using addRange() ------" << "\n";
    Span sp4 = Span(100000);
    std::list<int> lst;
    for (int i = 0; i < 100000; i++)
        lst.push_back(std::rand() % 100000);
    sp4.addRange(lst.begin(), lst.end());
    std::cout << sp4.shortestSpan() << "\n";
    std::cout << sp4.longestSpan() << "\n";

    return (0);
}
