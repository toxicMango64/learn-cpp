#include "Brain.hpp"

Brain::Brain() {
	cout << "[C] Neuronal creation of brain. Loading..." << endl;
	int	i = -1;
	while (++i < 100)
		this->_ideas[i] = this->ideaGenerator();
	cout << endl;
}

Brain::Brain(Brain const &src) {
	*this = src;
}

Brain &	Brain::operator=(Brain const &rSym) {
	if (this != &rSym) {
		int	i = -1;
		while (++i < 100)
			this->_ideas[i] = rSym._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	cout << "[D] Brain destruction, no turning back. Loading..." << endl;
}

#include <array>
string Brain::ideaGenerator() const {
	srand((unsigned)time(NULL) * getpid());
	
	string tmp;
	int min = 4;
	int max = 12;
	int random = min + arc4random() % (max - min + 1);

	static const std::array<char, 62> alphanum = {{
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		'U', 'V', 'W', 'X', 'Y', 'Z',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
		'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x', 'y', 'z'
	}};

	tmp.reserve(random);
	for (int i = 0; i < random; ++i) {
        tmp += alphanum[arc4random() % (sizeof(alphanum) - 1)];
    }
	return tmp;
}

string	Brain::getRandomIdea() const {
	int	min = 0;
	int	max = 99;
	int random = min + arc4random() % (max - min + 1);

	return this->_ideas[random];
}
