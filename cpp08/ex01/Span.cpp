// Copyright [2025] <myousaf>
#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {
    return ;
}
Span::Span(const Span &source) {
	this->_n = source.getN();
    const std::vector<int>& sourceVec = source.getVec();
    for (size_t i = 0; i < sourceVec.size(); i++)
        this->_vec.push_back(sourceVec[i]);
    return ;
}
Span::~Span() {
    return ;
}

Span &Span::operator=(const Span &source) {
    this->_n = source.getN();
    const std::vector<int>& sourceVec = source.getVec();
    for (size_t i = 0; i < sourceVec.size(); i++)
        this->_vec.push_back(sourceVec[i]);
    return (*this);
}

void    Span::addNumber(int n) {
    if (this->_vec.size() == this->_n)
        throw FullContainerException();
    this->_vec.push_back(n);
    return ;
}
int     Span::shortestSpan(void) {
    if (this->_vec.size() < 2)
        throw NotEnoughElementsException();
    std::vector<int> tmp = this->_vec;
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
        if (*(it + 1) - *it < shortest)
            shortest = *(it + 1) - *it;
    return (shortest);
}
int     Span::longestSpan(void) {
    if (this->_vec.size() < 2)
        throw NotEnoughElementsException();
    std::vector<int> tmp = this->_vec;
    std::sort(tmp.begin(), tmp.end());
    return (tmp[tmp.size() - 1] - tmp[0]);
}

unsigned int        Span::getN(void) const {
    return (this->_n);
}
std::vector<int>    Span::getVec(void) const {
    return (this->_vec);
}

const char *Span::FullContainerException::what() const throw() {
    return ("Container is full.");
}
const char *Span::NotEnoughElementsException::what() const throw() {
    return ("Not enough elements in container.");
}
