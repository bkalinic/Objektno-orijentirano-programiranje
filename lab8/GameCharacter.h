#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>

using namespace std;

class GameCharacter {
protected:
	int health;
	string name;
public:
	GameCharacter(int h, string n);
	virtual ~GameCharacter();

	virtual void displayStatus() = 0;
	virtual void specialAbility() = 0;

	void takeDamage(int amount);
	bool isAlive();
};

#endif