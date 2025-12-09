#ifndef ENEMY_H
#define ENEMY_H

#include "GameCharacter.h"
#include "Player.h"

class Enemy : public GameCharacter {
protected:
	int difficulty;
public:
	Enemy(int h, string n, int d);
	virtual ~Enemy();

	virtual void attackPlayer(Player* target) = 0;
};

#endif