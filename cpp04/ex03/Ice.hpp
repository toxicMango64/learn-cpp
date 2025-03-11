#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice &source);
	virtual ~Ice(void);

	Ice	&operator=(const Ice &other);

	AMateria* clone(void) const;
	void use(ICharacter& target);
};

#endif