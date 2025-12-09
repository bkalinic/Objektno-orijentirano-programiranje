#include "Player.h"
#include "GameCharacter.h"

using namespace std;

Player::Player(int h, string n, int s) : GameCharacter(h, n), score(s) {}

Player::~Player() {}

void Player::addScore(int amount) {
	score = score + amount;
}
