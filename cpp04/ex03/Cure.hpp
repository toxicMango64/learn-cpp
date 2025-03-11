#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure &source);
	virtual ~Cure(void);

	Cure	&operator=(const Cure &other);

	AMateria* clone(void) const;
	void use(ICharacter& target);
};

#endif