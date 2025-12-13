#include "Course.h"
#include <iostream>

using namespace std;

Course::Course(string n, int p, int e) {}

string Course::getName() const {
    return name;
}
int Course::getPass() const {
    return password;
}
int Course::getEcts() const {
    return ects;
}
void Course::setName(string n) {
    name = n;
}
void Course::setPass(int p) {
    password = p;
}
void Course::setEcts(int e) {
    ects = e;
}

ostream& operator<<(ostream& os, const Course& other) {
    return os << "Kolegij " << other.getName() << ", " << other.getEcts() << " bodova" << endl;
}
istream& operator>>(istream& is, Course& other) {
    string newName;
    int newPassword, newEcts;
    if (is >> ws && getline(is, newName) && is >> newPassword && is >> newEcts) {
        other.setName(newName);
        other.setPass(newPassword);
        other.setEcts(newEcts);
    }
    return is;
}