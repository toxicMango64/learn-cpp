#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// # include <exception>
// # include <algorithm>
// # include <iterator>
// # include <vector>
// # include <cstddef>

# define K 5

template <typename Container>
class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(Container const &container);
		PmergeMe(PmergeMe const &other);
		~PmergeMe();
		PmergeMe	&operator=(PmergeMe const &rhs);
		void		feed(Container const &container);
		void		sort();
		Container	&getContainer(void);
	private:
		Container	_container;
};

# include "PmergeMe.tpp"

#endif
