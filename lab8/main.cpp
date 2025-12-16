#include <iostream>
#include "GameCharacter.h"
#include "Warrior.h"
#include "Mage.h"
#include "Gnome.h"
#include "Boss.h"
#include <vector>

void playerAttack(Player* attacker, Enemy* target) {
    if (!attacker->isAlive()) {
        cout << attacker->getName() << " je mrtav i ne moze napadati!" << endl;
        return;
    }
    if (!target->isAlive()) {
        cout << target->getName() << " je vec mrtav!" << endl;
        return;
    }
    attacker->attackEnemy(target);

    cout << "Status nakon napada:" << endl;
    attacker->displayStatus();
    target->displayStatus();
}
void enemyAttack(Enemy* attacker, Player* target) {
    if (!attacker->isAlive()) {
        cout << attacker->getName() << " je mrtav i ne moze napadati!" << endl;
        return;
    }
    if (!target->isAlive()) {
        cout << target->getName() << " je vec mrtav!" << endl;
        return;
    }
    cout << "\n=== " << attacker->getName() << " napada " << target->getName() << " ===" << endl;
    attacker->attackPlayer(target);

    cout << "Status nakon napada:" << endl;
    attacker->displayStatus();
    target->displayStatus();
}
void likNajviseZdravlja(const vector<GameCharacter*>& likovi) {
    GameCharacter* najjaci = nullptr;
    int maxHealth = -1;
    for (const auto& lik : likovi) {
        if (lik && lik->isAlive()) {
            if (lik->getHealth() > maxHealth) {
                maxHealth = lik->getHealth();
                najjaci = lik;
            }
        }
    }
    if (najjaci) {
        cout << "\nLik s najvise zdravlja: " << najjaci->getName()
            << " (" << maxHealth << " HP)" << endl;
    }
}

int main() {
    Warrior* conan = new Warrior("Conan");
    Mage* merlin = new Mage("Merlin");
    Gnome* gnomeo = new Gnome("Gnomeo");
    Gnome* sneaky = new Gnome("Sneaky");
    Boss* dragon = new Boss("Dragon");

    vector<GameCharacter*> likovi;
    likovi.push_back(conan);
    likovi.push_back(merlin);
    likovi.push_back(gnomeo);
    likovi.push_back(sneaky);
    likovi.push_back(dragon);

    conan->displayStatus();
    merlin->displayStatus();
    gnomeo->displayStatus();
    sneaky->displayStatus();
    dragon->displayStatus();
    cout << endl;

    playerAttack(conan, gnomeo);

    playerAttack(merlin, sneaky);

    enemyAttack(gnomeo, conan);

    playerAttack(merlin, gnomeo);

    enemyAttack(dragon, merlin);

    playerAttack(merlin, gnomeo);

    playerAttack(conan, dragon);

    playerAttack(merlin, dragon);

    for (auto& lik : likovi) {
        if (lik && lik->isAlive()) {
            cout << "\n" << lik->getName() << " koristi specijalnu sposobnost:" << endl;
            lik->specialAbility();
        }
    }

    for (const auto& lik : likovi) {
        if (lik && lik->isAlive()) {
            lik->displayStatus();
        }
        else if (lik) {
            cout << lik->getName() << " je MRTAV!" << endl;
        }
    }

    likNajviseZdravlja(likovi);

    for (auto& lik : likovi) {
        if (lik) {
            delete lik;
            lik = nullptr;
        }
    }
    likovi.clear();

    return 0;
}