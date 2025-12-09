#include "Course.h"
#include <iostream>

using namespace std;

Course::Course(string n, int p, int e) : name(n), password(p), ects(e) {}

string Course::getName() const {
    return name;
}
int Course::getEcts() const {
    return ects;
}
void Course::setName(string n) {
    name = n;
}
void Course::setEcts(int e) {
    ects = e;
}

ostream& operator<<(ostream& os, const Course& other) {
    return os << "Kolegij " << other.getName() << ", " << other.getEcts() << endl;
}
istream& operator>>(istream& is, Course& other) {
    string newName;
    int newEcts;
    if (is >> ws && getline(is, newName) && is >> newEcts) {
        other.setName(newName);
        other.setEcts(newEcts);
    }
    return is;
}