#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include <string>

class Boss : public Enemy {
public:
	Boss(const std::string n);
	~Boss();

	void attackPlayer(Player* target) override;
	void specialAbility() override;

	void displayStatus() const override;
};

#endif