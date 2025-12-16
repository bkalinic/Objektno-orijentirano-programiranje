#include "Warrior.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <string>

Warrior::Warrior(const std::string n) : Player(120, n), shield(false) {}
Warrior::~Warrior(){
	cout << "Warrior destruktor pozvan!" << endl;
}

void Warrior::attackEnemy(Enemy* target) {
    if (target && target->isAlive()) {
        cout << name << " napada neprijatelja " << target->getName() << " macem!" << endl;

        int damage = 20;
        target->takeDamage(damage);
        cout << target->getName() << " primio " << damage << " stete." << endl;

        if (!target->isAlive()) {
            addScore(10);
            cout << name << " dobio 10 bodova!" << endl;
        }
    }
}

void Warrior::specialAbility() {
    cout << name << " aktivira stit!" << endl;
    shield = true;
}

void Warrior::takeDamage(int amount) {
    if (shield) {
        amount /= 2;
        cout << name << " stit smanjio stetu na " << amount << endl;
        shield = false;
    }
    Player::takeDamage(amount);
}

void Warrior::displayStatus() const {
    cout << "Warrior: " << name << ", zdravlje: " << getHealth() << ", bodovi: " << getScore()
        << ", stit aktiviran: " << (shield ? "Da" : "Ne") << endl;
}