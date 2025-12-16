#include "GameCharacter.h"
#include <iostream>
#include <string>

GameCharacter::GameCharacter(int h, const std::string n) : health(h), name(n) {}

GameCharacter::~GameCharacter() {
	cout << "Bazni destruktor pozvan!" << endl;
}

void GameCharacter::takeDamage(int amount) {
	health = health - amount;
	if (health < 0) health = 0;
}

bool GameCharacter::isAlive() {
	if (health > 0) {
		return true;
	}
	else {
		return false;
	}
}

int GameCharacter::getHealth() const {
	return health;
}

std::string GameCharacter::getName() const {
	return name;
}

void GameCharacter::setHealth(int i) {
	health = i;
	if (health < 0) health = 0;
}