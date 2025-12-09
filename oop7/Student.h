#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <ostream>
#include <istream>
using namespace std;

class Student {
private:
	int id;
	string name;
	string study_program;
	int year;
	static int total_students;
public:
	Student(int i = 10000, string n = "John", string sp = "default", int y = 2025);
	Student(const Student& other);
	~Student();

	int getId() const;
	string getName() const;
	string getStudyProgram() const;
	int getYear() const;

	void setId(int newId);
	void setName(string newN);
	void setStudyProgram(string newSp);
	void setYear(int newY);

	static int get_total_students();
};
std::ostream& operator<<(std::ostream& os, const Student& student);
std::istream& operator>>(std::istream& is, Student& student);

#endif