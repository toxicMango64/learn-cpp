#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	ClapTrap	Robin("Robin");
	ClapTrap	*Romeo = new ClapTrap("Roméo");
	ScavTrap	Cyril("Cyril");
	FragTrap	Bryan("Bryan");

	Robin.attack("Cyril");
	Cyril.takeDamage(Robin.getAttackDamage());
	Cyril.beRepaired(18);
	Cyril.guardGate();
	Cyril.attack("Romeo");
	Romeo->takeDamage(Cyril.getAttackDamage());
	delete Romeo;
	Bryan.attack("Cyril");
	Cyril.takeDamage(Bryan.getAttackDamage());
	Bryan.highFivesGuys();
	return 0;
}