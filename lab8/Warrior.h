#ifndef WARRIOR_H
#define WARRIOR_H

#include "GameCharacter.h"
#include "Player.h"

class Warrior : public Player {
public:
	Warrior(int h = 120, string n, int s);
	~Warrior();

	void attackEnemy(Enemy* target) override;
};

#endif