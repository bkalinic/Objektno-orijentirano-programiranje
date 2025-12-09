#include "Enemy.h"
#include "GameCharacter.h"

using namespace std;

Enemy::Enemy(int h, string n, int d) : GameCharacter(h, n), difficulty(d) {}

Enemy::~Enemy() {}
