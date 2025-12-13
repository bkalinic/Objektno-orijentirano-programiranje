#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <ostream>
#include <istream>
#include "Course.h"
using namespace std;

class Student {
private:
	int id;
	string name;
	string study_program;
	int year;
	static int total_students;

	Course* enrolled_courses;
	size_t enrolled_count;
	Course* completed_courses;
	size_t completed_count;
public:
	Student(int i = 0, string n = "", string sp = "", int y = 0);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();
	Student(Student&& other);
	Student& operator=(Student&& other);

	int getId() const;
	string getName() const;
	string getStudyProgram() const;
	int getYear() const;

	void setId(int newId);
	void setName(string newN);
	void setStudyProgram(string newSp);
	void setYear(int newY);

	static int get_total_students();

	bool enroll_course(const Course& course);
	bool complete_course(const Course& course);
	bool is_enrolled(const Course& course) const;
	bool has_completed(const Course& course) const;

	void print_enrolled_courses() const;
	void print_completed_courses() const;
	int get_total_ects() const;
	int get_ects_for_current_year() const;

	void print_all_info() const;

	Student& operator+=(const Course& course);
	Student& operator++();
	Student operator++(int);

	friend class StudentOffice;
};
std::ostream& operator<<(std::ostream& os, const Student& student);
std::istream& operator>>(std::istream& is, Student& student);

#endif