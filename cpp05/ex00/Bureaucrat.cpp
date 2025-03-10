#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Unamed Bureaucrat"), grade_(MIN_GRADE) {
  std::cout << "[Bureaucrat] Default constructor called.\n";
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade)
    : name_(name) {
  std::cout << "[Bureaucrat] Constructor called.\n";
  if (grade < MAX_GRADE)
    throw Bureaucrat::GradeTooHighException();
  if (grade > MIN_GRADE)
    throw Bureaucrat::GradeTooLowException();
  this->grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_), grade_() {
  std::cout << "[Bureaucrat] Copy constructor called.\n";
  *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  std::cout << "[Bureaucrat] Copy assignment called.\n";
  if (this == &other)
    return *this;
  this->grade_ = other.grade_;
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "[Bureaucrat] Destructor called.\n";
}

void Bureaucrat::decrementGrade() {
  if (this->grade_ + 1 > MIN_GRADE)
    throw GradeTooLowException();
  this->grade_++;
}

void Bureaucrat::incrementGrade() {
  if (this->grade_ - 1 < MAX_GRADE)
    throw GradeTooHighException();
  this->grade_--;
}

unsigned int Bureaucrat::getGrade() const { return this->grade_; }

std::string Bureaucrat::getName() const { return this->name_; }

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too Low!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n";
  return os;
}