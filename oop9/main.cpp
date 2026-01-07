#include <iostream>
#include <memory>
#include <stdexcept>
#include "lion.h"
#include "elephant.h"
#include "dolphin.h"
#include "seaturtle.h"
#include "zoosection.h"
#include "zookeeper.h"

int main() {
    auto lion = std::make_unique<Lion>("Lino", 5, 190.0);
    auto elephant = std::make_unique<Elephant>("Slonko", 10, 5000.0);
    auto dolphin = std::make_unique<Dolphin>("Dino", 7, 200.0);
    auto seaTurtle = std::make_unique<SeaTurtle>("Korni", 50, 150.0);

    try {
        auto invalidAnimal = std::make_unique<Lion>("", 5, 190.0);
    }
    catch (const std::invalid_argument& e) {
        std::cout << std::endl << "Iznimka pri kreiranju zivotinje: " << e.what() << std::endl;
    }

    ZooSection<Animal> zoo;
    zoo.addAnimal(std::move(lion));
    zoo.addAnimal(std::move(elephant));
    zoo.addAnimal(std::move(dolphin));
    zoo.addAnimal(std::move(seaTurtle));

    ZooKeeper keeper;
    for (size_t i = 0; i < zoo.size(); ++i) {
        Animal* animal = zoo.getAnimal(i);
        keeper.processAnimal(animal);
    }

    try {
        auto tinyTurtle = std::make_unique<SeaTurtle>("Robi", 1, 0.001);
        tinyTurtle->getDailyFood();
    }
    catch (const std::logic_error& e) {
        std::cout << std::endl << "Logic_error iznimka: " << e.what() << std::endl;
    }

    try {
        zoo.addAnimal(nullptr);
    }
    catch (const std::runtime_error& e) {
        std::cout << std::endl << "Runtime_error iznimka: " << e.what() << std::endl;
    }

    std::cout << "Ukupna dnevna kolicina hrane: " << zoo.totalFood() << "kg" << std::endl;
    std::cout << "Broj nahranjenih zivotinja: " << ZooKeeper::getTotalAnimalsServed() << std::endl;
    std::cout << "Broj zivotinja u zoo sektoru: " << zoo.size() << std::endl;

    return 0;
}