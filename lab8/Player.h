#ifndef PLAYER_H
#define PLAYER_H

#include "GameCharacter.h"
#include "Enemy.h"

class Player : public GameCharacter {
protected:
	int score;
public:
	Player(int h, string n, int s);
	virtual ~Player();

	virtual void attackEnemy(Enemy* target) = 0;
	void addScore(int amount);
};

#endif