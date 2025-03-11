#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_inventory[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &source);
		virtual ~MateriaSource(void);

		MateriaSource	&operator=(const MateriaSource &other);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type);
};

#endif