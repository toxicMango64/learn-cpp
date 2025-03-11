#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria &source);
		virtual ~AMateria(void);

		AMateria			&operator=(const AMateria &other);

		std::string const 	&getType(void) const; //Returns the materia type
		virtual void 		use(ICharacter& target);
		virtual AMateria	*clone(void) const = 0;
};

#endif