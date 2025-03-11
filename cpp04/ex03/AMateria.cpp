#include "AMateria.hpp"

AMateria::AMateria(void) {
	_type = "default";
	std::cout << "Default AMateria constructed!" << std::endl;
	return ;
}
AMateria::AMateria(std::string const &type) {
	_type = type;
	std::cout << "AMateria of type " << _type << " constructed!" << std::endl;
	return ;
}
AMateria::AMateria(const AMateria &source) {
	*this = source;
	std::cout << "AMateria of type " << _type << " copy constructed!" << std::endl;
	return ;
}
AMateria::~AMateria(void) {
	std::cout << "AMateria destructed!" << std::endl;
	return ;
}

AMateria	&AMateria::operator=(const AMateria &other) {
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

std::string const	&AMateria::getType(void) const {
	return (this->_type);
}
void AMateria::use(ICharacter& target) {
	std::cout << GREEN << "* " << _type << " uses its powers at " << target.getName() << " *" << RESET << std::endl;
	return ;
}
