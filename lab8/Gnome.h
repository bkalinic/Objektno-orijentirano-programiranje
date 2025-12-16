#ifndef GNOME_H
#define GNOME_H

#include "Enemy.h"
#include <string>

class Gnome : public Enemy {
public:
	Gnome(const std::string n);
	~Gnome();

	void attackPlayer(Player* target) override;
	void specialAbility() override;

	void displayStatus() const override;
};

#endif