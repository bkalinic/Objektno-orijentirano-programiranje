#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include "Student.h"

using namespace std;

int Student::total_students = 0;
Student::Student(int i, string n, string sp, int y) : id(i), name(n), study_program(sp), year(y) {
	total_students++;
	cout << "Konstruktor pozvan. Broj studenata: " << total_students << endl;
}
Student::Student(const Student& other) 
	: id(other.id), name(other.name), study_program(other.study_program), year(other.year) {
	total_students++;
	cout << "Copy konstruktor pozvan. Broj studenata: " << total_students << endl;
}
Student::~Student() {
	total_students--;
	cout << "Destruktor pozvan. Broj studenata: " << total_students << endl;
}

int Student::getId() const {
	return id;
}
string Student::getName() const {
	return name;
}
string Student::getStudyProgram() const {
	return study_program;
}
int Student::getYear() const {
	return year;
}
void Student::setId(int newId) {
	id = newId;
}
void Student::setName(string newN) {
	name = newN;
}
void Student::setStudyProgram(string newSp) {
	study_program = newSp;
}
void Student::setYear(int newY) {
	year = newY;
}

int Student::get_total_students() {
	return total_students;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
	return os << "Name: " << student.getName() 
		<< "(" << student.getId() << ")" 
		<< ", study program: " << student.getStudyProgram()
		<< "(" << student.getYear() << ")" << endl;
}
std::istream& operator>>(std::istream& is, Student& student) {
	string newName, newStudyProgram;
	int newId, newYear;
	if (is >> newId >> ws && getline(is, newName) && getline(is, newStudyProgram) && is >> newYear) {
		student.setId(newId);
		student.setName(newName);
		student.setStudyProgram(newStudyProgram);
		student.setYear(newYear);
	}
	return is;
}
