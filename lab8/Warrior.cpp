#include "Warrior.h"
#include "Player.h"

Warrior::Warrior(int h, string n, int s) : Player(h, n, s) {}
Warrior::~Warrior(){}

void Warrior::attackEnemy(Enemy* target) {
	if (target->isAlive) {
		target->takeDamage(20);
	}
	else {
		addScore(10);
	}
}
