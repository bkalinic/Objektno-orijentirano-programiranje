#ifndef PLAYER_H
#define PLAYER_H

#include "GameCharacter.h"
#include <string>

using namespace std;

class Enemy;

class Player : public GameCharacter {
protected:
	int score;
public:
	Player(int h, const std::string n);
	virtual ~Player();

	virtual void attackEnemy(Enemy* target) = 0;
	void addScore(int amount);

	int getScore() const;

	void displayStatus() const override;
};

#endif