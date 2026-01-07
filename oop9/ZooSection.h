#ifndef ZOOSECTION_H
#define ZOOSECTION_H

#include <memory>
#include <vector>
#include <stdexcept>
#include "animal.h"

template<typename T>
class ZooSection {
private:
    std::vector<std::unique_ptr<T>> animals;

public:
    void addAnimal(std::unique_ptr<T> animal) {
        if (!animal) {
            throw std::runtime_error("Ne moze se dodati nullptr zivotinja");
        }
        animals.push_back(std::move(animal));
    }

    double totalFood() const {
        double total = 0;
        for (const auto& animal : animals) {
            total += animal->getDailyFood();
        }
        return total;
    }

    size_t size() const {
        return animals.size();
    }

    T* getAnimal(size_t index) const {
        if (index >= animals.size()) {
            throw std::out_of_range("Index van rangea");
        }
        return animals[index].get();
    }
};

#endif