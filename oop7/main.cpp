#include <iostream>
#include <vector>
#include "Student.h"
#include "UniversityConstants.h"

using namespace std;

int main() {
	vector<Student> students;

	cout << "Pocetno stanje: " << Student::get_total_students() << endl;

	Student s1(10001, "Bartul", "Racunarstvo", 2023);
	cout << "Trenutno stanje: " << Student::get_total_students() << endl;
	Student s2(10002, "Roko", "Elektronika", 2024);
	cout << "Trenutno stanje: " << Student::get_total_students() << endl;
	Student s3 = s1;
	cout << "Trenutno stanje: " << Student::get_total_students() << endl;
	
	students.push_back(Student(10003, "Dominik", "Racunarstvo", 2025));
	cout << "Trenutno stanje: " << Student::get_total_students() << endl;

    cout << "Direct access to constants:" << endl;
    cout << "Max ECTS: " << UniversityConstants::MAX_ETCS_PER_YEAR << endl;
    cout << "Required ECTS: " << UniversityConstants::REQUIRED_ECTS_PER_YEAR << endl;

    cout << "\n";
    UniversityConstants::print_university_rules();

    cout << "\n=== Student Example ===" << endl;
    int studentEcts = 55;

    if (studentEcts > UniversityConstants::MAX_ETCS_PER_YEAR) {
        cout << "Warning: Student has " << studentEcts
            << " ECTS, exceeding maximum of "
            << UniversityConstants::MAX_ETCS_PER_YEAR << endl;
    }
    if (studentEcts >= UniversityConstants::REQUIRED_ECTS_PER_YEAR) {
        cout << "Student meets the required ECTS ("
            << UniversityConstants::REQUIRED_ECTS_PER_YEAR
            << ")" << endl;
    }
    else {
        cout << "Student does NOT meet the required ECTS ("
            << UniversityConstants::REQUIRED_ECTS_PER_YEAR
            << " required, has " << studentEcts << ")" << endl;
    }

	return 0;
}