// Copyright [2025] <myousaf>
#include "easyfind.hpp"

int main(void)
{
    std::cout << "------ Test with a container list of ints ------" << "\n";
    std::list<int> lst;
    for (int i = 0; i < 5; i++)
        lst.push_back(i);
    std::cout << "List: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    try {
        std::cout << "Looking for 3: ";
        std::cout << *easyfind(lst, 3) << "\n";
    }
    catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
    try {
        std::cout << "Looking for 5: ";
        std::cout << *easyfind(lst, 5) << "\n";
    }
    catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "------ Test with a container vector of ints ------" << "\n";
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
        vec.push_back(i);
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    try {
        std::cout << "Looking for 3: ";
        std::cout << *easyfind(vec, 3) << "\n";
    }
    catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
    try {
        std::cout << "Looking for 5: ";
        std::cout << *easyfind(vec, 5) << "\n";
    }
    catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "------ Test with a container deque of ints ------" << "\n";
    std::deque<int> deq;
    for (int i = 0; i < 5; i++)
        deq.push_back(i);
    std::cout << "Deque: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
        std::cout << *it << " ";
    std::cout << "\n";
    try {
        std::cout << "Looking for 3: ";
        std::cout << *easyfind(deq, 3) << "\n";
    }
    catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
    try {
        std::cout << "Looking for 5: ";
        std::cout << *easyfind(deq, 5) << "\n";
    }
    catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
  
    return (0);
}
