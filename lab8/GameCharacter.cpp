#include "GameCharacter.h"
#include <iostream>
#include <string>

GameCharacter::GameCharacter(int h, string n) : health(h), name(n) {}
GameCharacter::~GameCharacter() {
	cout << "Bazni destruktor pozvan!" << endl;
}

void GameCharacter::takeDamage(int amount) {
	health = health - amount;
}

bool GameCharacter::isAlive() {
	if (health > 0) {
		return true;
	}
	else {
		return false;
	}
}

