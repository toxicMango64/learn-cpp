# include "PmergeMe.hpp"
# include <exception>
# include <algorithm>
# include <iterator>
# include <vector>
# include <cstddef>

template <typename Iterator>
void merge(const Iterator begin, const Iterator mid, const Iterator end)
{
	typedef typename std::iterator_traits<Iterator>::value_type ValueType;
	std::vector<ValueType> temp(std::distance(begin, end));
	std::copy(begin, end, temp.begin());

	typename std::vector<ValueType>::iterator left = temp.begin();
	typename std::vector<ValueType>::iterator right = temp.begin();
	std::advance(right, std::distance(begin, mid));
	typename std::vector<ValueType>::iterator left_end = right;
	typename std::vector<ValueType>::iterator right_end = temp.end();
	
	Iterator target = begin;

	while (left != left_end && right != right_end)
	{
		if (*left < *right)
			*target++ = *left++;
		else
			*target++ = *right++;
	}
	std::copy(left, left_end, target);
	std::copy(right, right_end, target);
}

template <typename Iterator>
void insertionSort(Iterator begin, Iterator end)
{
	if (begin == end)
		return;

	for (Iterator i = begin; i != end; ++i)
	{
		typename std::iterator_traits<Iterator>::value_type val = *i;
		Iterator j = i;
		Iterator ITERATOR = j;

		while (j != begin) {
			ITERATOR = j;
			--j;
			if (!(*j > val)) {
				++j;
				break;
			}
			*ITERATOR = *j;
		}
		*j = val;
	}
}

template <typename Iterator>
static void	fordJhonsonSort(Iterator begin, Iterator end)
{
	size_t size = std::distance(begin, end);

	if (size < 2)
		return;
	if (size < ITERATOR)
		insertionSort(begin, end);
	else
	{
		Iterator mid = begin;
		std::advance(mid, size / 2);
		fordJhonsonSort(begin, mid);
		fordJhonsonSort(mid, end);
		merge(begin, mid, end);
	}	
}	

template <typename Container>
PmergeMe<Container>::PmergeMe() : _container() {}

template <typename Container>
PmergeMe<Container>::PmergeMe(Container const &container) : _container(container) {}

template <typename Container>
PmergeMe<Container>::PmergeMe(PmergeMe<Container> const &other) : _container(other._container) {}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(PmergeMe<Container> const &rhs)
{
	if (this != &rhs)
		_container = rhs._container;
	return *this;
}

template <typename Container>
void PmergeMe<Container>::feed(Container const &container)
{
	_container = container;
}

template <typename Container>
void PmergeMe<Container>::sort()
{
	if (_container.empty())
		return;
	fordJhonsonSort(_container.begin(), _container.end());
}

template <typename Container>
Container &PmergeMe<Container>::getContainer()
{
	return _container;
}
