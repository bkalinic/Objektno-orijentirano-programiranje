#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>

using namespace std;

class GameCharacter {
protected:
	int health;
	std::string name;
public:
	GameCharacter(int h, const std::string n);
	virtual ~GameCharacter() = 0;

	virtual void displayStatus() const = 0;
	virtual void specialAbility() = 0;

	virtual void takeDamage(int amount);
	bool isAlive();

	int getHealth() const;
	std::string getName() const;
	void setHealth(int i);
};

#endif