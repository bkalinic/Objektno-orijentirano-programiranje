#include "Player.h"
#include "GameCharacter.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(int h, const std::string n) : GameCharacter(h, n), score(0) {}

Player::~Player() {
	cout << "Player destruktor pozvan!" << endl;
}

void Player::addScore(int amount) {
	score = score + amount;
}

int Player::getScore() const {
	return score;
}

void Player::displayStatus() const {
	cout << "Igrac: " << name << ", zdravlje: " << health << ", bodovi: " << score << endl;
}