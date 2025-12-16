#include "Boss.h"
#include "Player.h"
#include <string>

Boss::Boss(const std::string n) : Enemy(300, n, 8) {}

Boss::~Boss() {
    cout << "Boss destruktor pozvan!" << endl;
}

void Boss::attackPlayer(Player* target) {
    if (target && target->isAlive()) {
        int damage = 10 * difficulty;
        cout << "BOSS " << name << " razbija zemlju pod " << target->getName() << "!" << endl;
        cout << "Nanosi " << damage << " stete!" << endl;

        target->takeDamage(damage);
    }
}

void Boss::specialAbility() {
    int originalHealth = health;
    health += 50;

    if (health > 300) {
        health = 300;
    }

    int healed = health - originalHealth;
    if (healed > 0) {
        cout << "BOSS " << name << " regenerira " << healed << " zdravlja!" << endl;
        cout << "Trenutno zdravlje: " << health << "/300" << endl;
    }
    else {
        cout << "BOSS " << name << " vec ima maksimalno zdravlje!" << endl;
    }
}

void Boss::displayStatus() const {
    cout << "BOSS: " << name << ", zdravlje: " << health 
        << "/300, tezina: " << difficulty << " (Konacni neprijatelj)" << endl;
}