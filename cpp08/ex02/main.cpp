// Copyright [2025] <myousaf>
#include "MutantStack.hpp"

int main(void) {
    std::cout << "Trying to iterate through a stack:" << "\n";
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);   
    std::cout << "\tStack: ";
    for (std::stack<int> dump = s; !dump.empty(); dump.pop())
        std::cout << dump.top() << " ";
    std::cout << "\n";
    std::cout << "\t\tThe numbers are backwards 'cause that's the way a stack works." << "\n";
    std::cout << "\t\tYou can only ´push´ and ´pop´ elements from the top of the stack." << "\n";

    std::cout << "Trying to iterate through a MutantStack:" << "\n";
    MutantStack<int> ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    std::cout << "\tMutantStack: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    std::cout << "\t\tThe numbers are in the right order 'cause that's the way a MutantStack works." << "\n";
    std::cout << "\t\tYou can iterate through it using the underlying container iterator." << "\n";
    
    std::cout << "Subject tests #1 - Using MutantStack" << "\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << "\n";
    mstack.pop();
    std::cout << mstack.size() << "\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << "\n";
        ++it;
    }
    std::stack<int> stack(mstack);
    
    std::cout << "Subject tests #2 - Using std::list" << "\n";
    std::list<int> lstack;
    lstack.push_back(5);
    lstack.push_back(17);
    std::cout << lstack.back() << "\n";
    lstack.pop_back();
    std::cout << lstack.size() << "\n";
    lstack.push_back(3);
    lstack.push_back(5);
    lstack.push_back(737);
    lstack.push_back(0);
    std::list<int>::iterator itl = lstack.begin();
    std::list<int>::iterator itle = lstack.end();
    ++itl;
    --itl;
    while (itl != itle) {
        std::cout << *itl << "\n";
        ++itl;
    }
    std::list<int> list(lstack);

    std::cout << "\t\tThe results from the two previous tests must be the same." << "\n";
    std::cout << "\t\tIt means that we can use the underlying iterator for the MutantStack class." << "\n";
    
    return (0);
}
