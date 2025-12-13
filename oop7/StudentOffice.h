#ifndef STUDENTOFFICE_H
#define STUDENTOFFICE_H

#include "Student.h"
#include "UniversityConstants.h"
#include <vector>

class StudentOffice {
private:
    vector<Student> students;
    vector<Course> available_courses;

public:
    StudentOffice();

    void add_student(const Student& student);
    void remove_student(int student_id);

    void add_course(const Course& course);
    void remove_course(const string& course_name);

    void moveStudent(Student& student, const string& new_program);
    void enroll_student(int student_id, const string& course_name);
    void process_exam_results(int student_id, const string& course_name, bool passed);
    void update_student_years();

    Student* find_student(int student_id);
    Course* find_course(const string& course_name);
    int calculate_current_year_ects(const Student& student) const;

    void simulate_academic_year();
    void print_all_students() const;
    void print_all_courses() const;
};

#endif