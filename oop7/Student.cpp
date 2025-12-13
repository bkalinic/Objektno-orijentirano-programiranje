#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include "Student.h"
#include "Course.h"
#include "UniversityConstants.h"
#include <utility>

using namespace std;

int Student::total_students = 0;
Student::Student(int i, string n, string sp, int y) 
	: id(i), name(n), study_program(sp), year(y), enrolled_courses(nullptr), enrolled_count(0),
		completed_courses(nullptr), completed_count(0) {
	total_students++;
	cout << "Konstruktor pozvan. Broj studenata: " << total_students << endl;
}
Student::Student(const Student& other) 
	: id(other.id), name(other.name), study_program(other.study_program), year(other.year),
		enrolled_count(other.enrolled_count), completed_count(other.completed_count) {
	total_students++;

	if (other.enrolled_courses && other.enrolled_count > 0) {
		enrolled_courses = new Course[other.enrolled_count];
		copy(other.enrolled_courses, other.enrolled_courses + other.enrolled_count, enrolled_courses);
	}
	else {
		enrolled_courses = nullptr;
	}

	if (other.completed_courses && other.completed_count > 0) {
		completed_courses = new Course[other.completed_count];
		copy(other.completed_courses, other.completed_courses + other.completed_count, completed_courses);
	}
	else {
		completed_courses = nullptr;
	}

	cout << "Copy konstruktor pozvan. Broj studenata: " << total_students << endl;
}
Student& Student::operator=(const Student& other) {
	if (this == &other) {
		return *this;	
	}
	delete[] enrolled_courses;
	delete[] completed_courses;

	id = other.id;
	name = other.name;
	study_program = other.study_program;
	year = other.year;
	enrolled_count = other.enrolled_count;
	completed_count = other.completed_count;

	if (other.enrolled_courses && other.enrolled_count > 0) {
		enrolled_courses = new Course[other.enrolled_count];
		copy(other.enrolled_courses, other.enrolled_courses + other.enrolled_count, enrolled_courses);
	}
	else {
		enrolled_courses = nullptr;
	}

	if (other.completed_courses && other.completed_count > 0) {
		completed_courses = new Course[other.completed_count];
		copy(other.completed_courses, other.completed_courses + other.completed_count, completed_courses);
	}
	else {
		completed_courses = nullptr;
	}
	cout << "Copy assignment pozvan za: " << name << endl;
	return *this;
}
Student::~Student() {
	delete[] enrolled_courses;
	delete[] completed_courses;
	total_students--;
	cout << "Destruktor pozvan. Broj studenata: " << total_students << endl;
}
Student::Student(Student&& other) 
	: id(other.id), name(move(other.name)), study_program(move(other.study_program)), year(other.year),
		enrolled_courses(other.enrolled_courses), enrolled_count(other.enrolled_count), 
		completed_courses(other.completed_courses), completed_count(other.completed_count) {
	
	other.enrolled_courses = nullptr;
	other.enrolled_count = 0;
	other.completed_courses = nullptr;
	other.completed_count = 0;
	other.id = 0;
	other.name = "";
	other.study_program = "";
	other.year = 0;

	total_students++;
	cout << "Move konstruktor pozvan. Broj studenata: " << total_students << endl;
}

Student& Student::operator=(Student&& other) {
	if (this == &other) {
		return *this;
	}
	delete[] enrolled_courses;
	delete[] completed_courses;

	id = other.id;
	name = move(other.name);
	study_program = move(other.study_program);
	year = other.year;

	enrolled_courses = other.enrolled_courses;
	enrolled_count = other.enrolled_count;
	completed_courses = other.completed_courses;
	completed_count = other.completed_count;

	other.enrolled_courses = nullptr;
	other.enrolled_count = 0;
	other.completed_courses = nullptr;
	other.completed_count = 0;
	other.id = 0;
	other.name = "";
	other.study_program = "";
	other.year = 0;

	cout << "Move assignment pozvan za: " << name << endl;
	return *this;
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

bool Student::enroll_course(const Course& course) {
	if (is_enrolled(course)) {
		cout << "Student " << name << " je vec upisan na kolegij " << course.getName() << endl;
	}
	return false;
	if (has_completed(course)) {
		cout << "Student " << name << " je vec polozio kolegij " << course.getName() << endl;
	}
	return false;

	Course* new_enrolled = new Course[enrolled_count + 1];

	for (size_t i = 0; i < enrolled_count; i++) {
		new_enrolled[i] = enrolled_courses[i];
	}

	new_enrolled[enrolled_count] = course;

	delete[] enrolled_courses;
	enrolled_courses = new_enrolled;
	enrolled_count++;

	std::cout << "Student " << name << " upisan u kolegij: "
		<< course.getName() << std::endl;
	return true;
}

bool Student::complete_course(const Course& course) {
	bool found = false;
	size_t index = 0;

	for (size_t i = 0; i < enrolled_count; i++) {
		if (enrolled_courses[i].getName() == course.getName()) {
			found = true;
			index = i;
			break;
		}
	}

	if (!found) {
		std::cout << "Student " << name << " nije upisan na kolegij "
			<< course.getName() << std::endl;
		return false;
	}

	if (has_completed(course)) {
		std::cout << "Student " << name << " je vec polozio kolegij "
			<< course.getName() << std::endl;
		return false;
	}

	Course* new_completed = new Course[completed_count + 1];
	for (size_t i = 0; i < completed_count; i++) {
		new_completed[i] = completed_courses[i];
	}
	new_completed[completed_count] = course;

	delete[] completed_courses;
	completed_courses = new_completed;
	completed_count++;

	Course* new_enrolled = new Course[enrolled_count - 1];
	for (size_t i = 0, j = 0; i < enrolled_count; i++) {
		if (i != index) {
			new_enrolled[j++] = enrolled_courses[i];
		}
	}

	delete[] enrolled_courses;
	enrolled_courses = new_enrolled;
	enrolled_count--;

	std::cout << "Student " << name << " je polozio kolegij: "
		<< course.getName() << " (" << course.getEcts() << " ECTS)" << std::endl;
	return true;
}

bool Student::is_enrolled(const Course& course) const {
	for (size_t i = 0; i < enrolled_count; i++) {
		if (enrolled_courses[i].getName() == course.getName()) {
			return true;
		}
	}
	return false;
}

bool Student::has_completed(const Course& course) const {
	for (size_t i = 0; i < completed_count; i++) {
		if (completed_courses[i].getName() == course.getName()) {
			return true;
		}
	}
	return false;
}

void Student::print_enrolled_courses() const {
	std::cout << "Upisani kolegiji za " << name << ":" << std::endl;
	if (enrolled_count == 0) {
		std::cout << "  Nema upisanih kolegija." << std::endl;
	}
	else {
		for (size_t i = 0; i < enrolled_count; i++) {
			std::cout << "  " << i + 1 << ". " << enrolled_courses[i] << std::endl;
		}
	}
}

void Student::print_completed_courses() const {
	std::cout << "Polozeni kolegiji za " << name << ":" << std::endl;
	if (completed_count == 0) {
		std::cout << "  Nema polozenih kolegija." << std::endl;
	}
	else {
		int totalEcts = 0;
		for (size_t i = 0; i < completed_count; i++) {
			std::cout << "  " << i + 1 << ". " << completed_courses[i];
			totalEcts += completed_courses[i].getEcts();
		}
		std::cout << "  Ukupno ECTS: " << totalEcts << std::endl;
	}
}

int Student::get_total_ects() const {
	int total = 0;
	for (size_t i = 0; i < completed_count; i++) {
		total += completed_courses[i].getEcts();
	}
	return total;
}

int Student::get_ects_for_current_year() const {
	return get_total_ects();
}

void Student::print_all_info() const {
	cout << "\n=== Informacije o studentu ===" << endl;
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Study Program: " << study_program << endl;
	cout << "Year: " << year << endl;
	cout << "Total ECTS: " << get_total_ects() << endl;

	print_enrolled_courses();
	print_completed_courses();
	cout << "================================\n" << endl;
}

Student& Student::operator+=(const Course& course) {
	if (!enroll_course(course)) {
		std::cout << "Upozorenje: Nije moguce upisati kolegij "
			<< course.getName() << " koristeci += operator" << std::endl;
	}
	return *this;
}

Student& Student::operator++() {
	int currentEcts = get_ects_for_current_year();

	if (currentEcts >= UniversityConstants::REQUIRED_ECTS_PER_YEAR) {
		year++;

		std::cout << name << " prelazi na godinu " << year
			<< " (" << currentEcts << " ECTS postignuto, potrebno: "
			<< UniversityConstants::REQUIRED_ECTS_PER_YEAR << ")" << std::endl;
	}
	else {
		std::cout << name << " ne moze preci na iducu godinu. Potrebno je "
			<< (UniversityConstants::REQUIRED_ECTS_PER_YEAR - currentEcts)
			<< " više ECTS (ima " << currentEcts << ", potrebno: "
			<< UniversityConstants::REQUIRED_ECTS_PER_YEAR << ")" << std::endl;
	}

	return *this;
}

Student Student::operator++(int) {
	Student temp = *this;
	++(*this);
	return temp;
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
