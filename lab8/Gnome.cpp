#include "Gnome.h"
#include "Player.h"
#include <iostream>
#include <string>

Gnome::Gnome(const std::string n) : Enemy(90, n, 3) {}

Gnome::~Gnome() {
    cout << "Gnome destruktor pozvan!" << endl;
}

void Gnome::attackPlayer(Player* target) {
    if (target && target->isAlive()) {
        int damage = 5 * difficulty;
        cout << name << " puca strijelom na " << target->getName() << "!" << endl;
        cout << "Nanosi " << damage << " stete!" << endl;

        target->takeDamage(damage);
    }
}

void Gnome::specialAbility() {
    if (health > 20) {
        cout << name << " svira trubu! Poziva druge gnomove u pomoc!" << endl;
    }
    else {
        cout << name << " premalo zdravlja za sviranje trube!" << endl;
    }
}

void Gnome::displayStatus() const {
    cout << "Gnome: " << name << ", zdravlje: " << health 
        << "/90, tezina: " << difficulty << " (Luk i strijela)" << endl;
}