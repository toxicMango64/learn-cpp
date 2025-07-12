#include "PmergeMe.hpp"
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdint.h>
#include <ctime>
#include <list>
#include <stdexcept>

template <typename Container1, typename Container2>
static void	fill_containers(Container1 &c1, Container2 &c2, const int n_numbers, const char **numbers)
{
	std::istringstream	iss;
	int					number;
	
	for (int i = 0; i < n_numbers; i++)
	{
		iss.clear();
		iss.str(numbers[i]);
		iss >> number;

		if (iss.fail() || !iss.eof()) {

			std::ostringstream err_msg;
			err_msg << "Error: '" << numbers[i] << "'" << " is not a number";

			throw std::invalid_argument(err_msg.str());
		}

		c1.push_back(number);
		c2.push_back(number);
	}
}

template <typename Container>
static void print_container(const Container &container)
{
	for (typename Container::const_iterator it = container.begin(); it != container.end(); it++)
	std::cout << *it << " ";
std::cout << "\n";
}

template <typename Container1, typename Container2>
static void	sort(size_t &vec_time, size_t &list_time, PmergeMe<Container1> &vec_sorter, PmergeMe<Container2> &list_sorter)
{
	size_t	start_time = 0;
	size_t	end_time = 0;
	
	/** get deque time */
	start_time = clock(); 
	vec_sorter.sort();
	end_time = clock();
	vec_time = (end_time - start_time) * 1000000 / CLOCKS_PER_SEC;
	/** get list time
	 * use start_time as end_time of deque
	 */
	start_time = end_time;
	list_sorter.sort();
	end_time = clock();
	list_time = (end_time - start_time) * 1000000 / CLOCKS_PER_SEC;
}

static void print_times(const size_t deque_time, const size_t list_time, const int n_numbers)
{
	std::ostringstream	base_msg;
	std::string			base_str;
	
	base_msg << "Time to process a range of " << n_numbers << " elements with std::";
	base_str = base_msg.str();
	std::cout << base_str + "deque: " << deque_time << " us\n";
	std::cout << base_str + "list: "  << list_time << " us\n";
}

int main(const int argc, const char **argv)
{	
	std::deque<int>				deque;
	std::list<int>				list;
	PmergeMe<std::deque<int> >	deque_sorter;
	PmergeMe<std::list<int> >	list_sorter;
	size_t						deque_time = 0;
	size_t						list_time = 0;

    std::string line;

	if (argc < 2)
	{
		std::cerr << "Error: invalid arguments\n"
			"\ttry \"./PmergeMe 3 1 2 ...\"\n";
		return (1);
	}

	try
	{
		fill_containers(deque, list, argc - 1, argv + 1);
		std::cout << std::setw(10) << std::left << "Before: ";
		print_container(deque);
		deque_sorter.feed(deque);
		list_sorter.feed(list);
		sort(deque_time, list_time, deque_sorter, list_sorter);
		deque = deque_sorter.getContainer();
		list = list_sorter.getContainer();
		std::cout << std::setw(10) << std::left << "After: ";
		print_container(deque);
		print_times(deque_time, list_time, argc - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
