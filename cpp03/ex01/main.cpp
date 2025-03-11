#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// int	main() {
// 	ClapTrap	Robin("Robin");
// 	ClapTrap	*Romeo = new ClapTrap("Roméo");
// 	ScavTrap	Cyril("Cyril");

// 	Robin.attack("Cyril");
// 	Cyril.takeDamage(Robin.getAttackDamage());
// 	Cyril.beRepaired(18);
// 	Cyril.guardGate();
// 	Cyril.attack("Romeo");
// 	Romeo->takeDamage(Cyril.getAttackDamage());
// 	delete Romeo;
// 	return 0;
// }

int	main(void)
{
	string name = "Scavy";
	string copy = "ScavyCopy";
	
	ScavTrap scavy(name);

	scavy.takeDamage(10);
	scavy.beRepaired(10);
	
	scavy.attack("some other enemy");
	scavy.guardGate();

	ScavTrap scavy2 = scavy;
	scavy2.attack("another enemy");
	
	ScavTrap scavy3(scavy2);
	scavy3.attack("one more enemy");

	ClapTrap *scavy4 = new ScavTrap(copy);
	ClapTrap *Romeo = new ScavTrap("Roméo");
	scavy4->attack("yet another enemy");
	
	delete scavy4;
	delete Romeo;
	return (0);	
}

