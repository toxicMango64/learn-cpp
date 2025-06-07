#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <iostream>
# include <ctime>
# include <string>
# include <sstream>
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>

class PmergeMe {
    private:
        PmergeMe(void);
        PmergeMe(PmergeMe const &src);
        ~PmergeMe(void);
        PmergeMe &operator=(PmergeMe const &rhs);
        static void _sort_pairs(std::vector<std::pair<int, int> > &vector, size_t size);
        static void _sort_pairs(std::list<std::pair<int, int> > &list, size_t size);
            
    public:
        static void sort(std::vector<int> &vector);
        static void sort(std::list<int> &list);
};

bool validate_sequence(std::string sequence);

template <typename T>
T parse_sequence(std::string sequence) {
    T container;
    std::stringstream iss(sequence);
    int num;

    while (iss >> num)
        container.push_back(num);
    return (container);
}

template <typename T>
void print_sequence(T container) {
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    while (it != ite) {
        std::cout << *it;
        if (++it != ite)
            std::cout << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void print_pairs(T container) {
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    while (it != ite) {
        std::cout << "(" << it->first << ", " << it->second << ")";
        if (++it != ite)
            std::cout << " ";
    }
    std::cout << std::endl;
}

int jacobsthal(int n);

template <typename T>
T generate_insertion_sequence(size_t size) {
    T sequence;
    if (size < 1)
        return (sequence);
    int jacobsthal_iterator = 2;

    int next = jacobsthal(jacobsthal_iterator++);
    sequence.push_back(next);

    while (sequence.size() < size) {
        next = jacobsthal(jacobsthal_iterator++);
        if (next >= static_cast<int>(size))
            next = size;
        while (sequence.size() < size && next > 0) {
            sequence.push_back(next);
            if (std::find(sequence.begin(), sequence.end(), next - 1) != sequence.end())
                break ;
            next--;
        }
    }
    return (sequence);
}

#endif
