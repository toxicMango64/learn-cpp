#include "Brain.hpp"

Brain::Brain() {
	cout << "[C] Neuronal creation of brain. Loading..." << endl;
	int	i = -1;
	while (++i < 100) {
		this->_ideas[i] = this->ideaGenerator();
		cout << "Idea " << i + 1 << "/100 implemented." << "\r" << std::flush;
		usleep(35000);
	}
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

string Brain::ideaGenerator() const {
	srand((unsigned)time(NULL) * getpid());
	
	string tmp;
	int min = 4;
	int max = 12;
	int random = min + rand() % (max - min + 1);
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	tmp.reserve(random);
	for (int i = 0; i < random; ++i) {
        tmp += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
	return tmp;
}

string	Brain::getRandomIdea() const {
	int	min = 0;
	int	max = 99;
	int random = min + rand() % (max - min + 1);

	return this->_ideas[random];
}