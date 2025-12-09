#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course {
private:
	string name;
	int password;
	int ects;
public:
	Course(string n, int p, int e);

	string getName() const;
	int getEcts() const;

	void setName(string n);
	void setEcts(int e);
};

ostream& operator<<(ostream& os, const Course& other);
istream& operator>>(istream& is, Course& other);

#endif