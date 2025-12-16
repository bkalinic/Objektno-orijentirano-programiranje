#include "Enemy.h"
#include "GameCharacter.h"

using namespace std;

Enemy::Enemy(int h, string n, int d) : GameCharacter(h, n), difficulty(d) {}

Enemy::~Enemy() {
	cout << "Enemy destruktor pozvan!" << endl;
}

int Enemy::getDifficulty() const {
	return difficulty;
}

void Enemy::displayStatus() const {
	cout << "Neprijatelj: " << name << ", zdravlje: " << health << ", tezina: " << difficulty << endl;
}
