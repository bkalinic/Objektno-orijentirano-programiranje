#include "Mage.h"
#include "Player.h"
#include "Enemy.h"
#include <string>

Mage::Mage(const std::string n) : Player(80, n), mana(100) {}

Mage::~Mage() {
    cout << "Mage destruktor pozvan!" << endl;
}

void Mage::attackEnemy(Enemy* target) {
    if (target && target->isAlive()) {
        if (mana >= 20) {
            cout << name << " baca vatrenu kuglu na " << target->getName() << "!" << endl;
            int damage = 40;
            target->takeDamage(damage);
            mana -= 20;
            cout << target->getName() << " primio " << damage << " stete." << endl;
            cout << "Mana: " << mana << endl;
        }
        else {
            cout << name << " napada stapom " << target->getName() << "!" << endl;
            int damage = 20;
            target->takeDamage(damage);
            cout << target->getName() << " primio " << damage << " stete." << endl;
        }

        if (!target->isAlive()) {
            addScore(10);
            cout << name << " dobio 10 bodova!" << endl;
        }
    }
}

void Mage::specialAbility() {
    if (health > 50) {
        cout << name << " teleportira se na sigurnu lokaciju!" << endl;
    }
    else {
        cout << name << " premalo zdravlja za teleport!" << endl;
    }
}

void Mage::displayStatus() const {
    cout << "Mage: " << name << ", zdravlje: " << health << ", bodovi: " << score << ", mana: " << mana << endl;
}

int Mage::getMana() const {
    return mana;
}
