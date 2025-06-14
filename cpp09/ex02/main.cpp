#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./PmergeMe \"<sequence of unique positive integers>\"\n";
        return (1);
    } else if (!validate_sequence(argv[1])) {
        return (1);
    }

    std::vector<int> control_vector = parse_sequence<std::vector<int> >(argv[1]);
    if (control_vector.size() == 0) {
        std::cout << "Error: empty sequence\n";
        return (1);
    }
    std::cout << "Before: ";
    print_sequence(control_vector);
    std::sort(control_vector.begin(), control_vector.end());
    std::cout << "After: ";
    print_sequence(control_vector);

    std::list<int> control_list = parse_sequence<std::list<int> >(argv[1]);
    control_list.sort();
    
    const clock_t vector_start = clock();
    std::vector<int> vector = parse_sequence<std::vector<int> >(argv[1]);
    PmergeMe::sort(vector);
    const clock_t vector_end = clock();
    const double vector_duration = double(vector_end - vector_start) / CLOCKS_PER_SEC * 1e6;
    if (std::equal(control_vector.begin(), control_vector.end(), vector.begin())) {
        std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << vector_duration << " us\n";
    }
    else { std::cout << "Error: vector not sorted\n"; }

    const clock_t list_start = clock();
    std::list<int> list = parse_sequence<std::list<int> >(argv[1]);
    PmergeMe::sort(list);
    const clock_t list_end = clock();
    const double list_duration = double(list_end - list_start) / CLOCKS_PER_SEC * 1e6;
    if (std::equal(control_list.begin(), control_list.end(), list.begin())) {
        std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << list_duration << " us\n";
    }
    else { std::cout << "Error: list not sorted\n"; }
    return (0);
}
