#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
using std::cout;
using std::endl;

class Fixed {
	private:
		int					value;
		static const int	bits = 8;

	public:
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed	&operator=(const Fixed &rSym);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif