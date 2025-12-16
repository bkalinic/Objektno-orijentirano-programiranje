#ifndef MAGE_H
#define MAGE_H

#include "Player.h"
#include <string>

class Mage : public Player {
private:
	int mana;
public:
	Mage(const std::string n);
	~Mage();

	void attackEnemy(Enemy* target) override;
	void specialAbility() override;
	void displayStatus() const override;
	int getMana() const;
};

#endif