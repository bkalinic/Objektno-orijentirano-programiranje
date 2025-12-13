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
	Course(string n = "course", int p = 12345, int e = 0);

	string getName() const;
	int getPass() const;
	int getEcts() const;

	void setName(string n);
	void setPass(int p);
	void setEcts(int e);
};

ostream& operator<<(ostream& os, const Course& other);
istream& operator>>(istream& is, Course& other);

#endif