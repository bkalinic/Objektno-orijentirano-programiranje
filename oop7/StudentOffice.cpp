#include "StudentOffice.h"
#include "UniversityConstants.h"
#include <iostream>
#include <algorithm>

using namespace std;

StudentOffice::StudentOffice() {
    available_courses.push_back(Course("Matematika 1", 1001, 5));
    available_courses.push_back(Course("Fizika 1", 1002, 5));
    available_courses.push_back(Course("Programiranje 1", 1003, 5));
    available_courses.push_back(Course("Osnove elektrotehnike", 1004, 5));
    available_courses.push_back(Course("Baze podataka", 1005, 5));
    available_courses.push_back(Course("Web dizajn", 1006, 5));
    available_courses.push_back(Course("Raèunalne mreže", 1007, 5));
    available_courses.push_back(Course("Operacijski sustavi", 1008, 5));
}

void StudentOffice::add_student(const Student& student) {
    students.push_back(student);
    cout << "Student/ica " << student.getName() << " dodan/a u uredske zapise." << endl;
}

void StudentOffice::remove_student(int student_id) {
    auto it = remove_if(students.begin(), students.end(),
        [student_id](const Student& s) { return s.getId() == student_id; });

    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Student/ica sa id-em " << student_id << " izbrisan/a." << endl;
    }
    else {
        cout << "Student sa id-em " << student_id << " nije pronadjen." << endl;
    }
}

void StudentOffice::add_course(const Course& course) {
    available_courses.push_back(course);
    cout << "Kolegij " << course.getName() << " dodan u dostupne kolegije." << endl;
}

void StudentOffice::remove_course(const string& course_name) {
    auto it = remove_if(available_courses.begin(), available_courses.end(),
        [&course_name](const Course& c) { return c.getName() == course_name; });

    if (it != available_courses.end()) {
        available_courses.erase(it, available_courses.end());
        cout << "Kolegij " << course_name << " izbrisan." << endl;
    }
    else {
        cout << "Kolegij " << course_name << " nije pronadjen." << endl;
    }
}

void StudentOffice::moveStudent(Student& student, const string& new_program) {
    string old_program = student.getStudyProgram();

    Student temp_student(student);
    temp_student.setStudyProgram(new_program);

    student = move(temp_student);

    cout << "Student/ica " << student.getName() << " prebacen/a iz '"
        << old_program << "' u '" << new_program << "'" << endl;
}

void StudentOffice::enroll_student(int student_id, const string& course_name) {
    Student* student = find_student(student_id);
    Course* course = find_course(course_name);

    if (!student || !course) {
        if (!student) cout << "Student/ica s id-em " << student_id << " nije pronadjen/a." << endl;
        if (!course) cout << "Kolegij " << course_name << " nije pronadjen." << endl;
        return;
    }

    int current_ects = calculate_current_year_ects(*student);

    if (current_ects + course->getEcts() > UniversityConstants::MAX_ETCS_PER_YEAR) {
        cout << "Nije moguce upisati " << student->getName() << " u " << course_name
            << ". Trenutni ECTS: " << current_ects
            << ", kolegij ECTS: " << course->getEcts()
            << ", maksimalno dozvoljeno: " << UniversityConstants::MAX_ETCS_PER_YEAR << endl;
        return;
    }

    if (student->is_enrolled(*course)) {
        cout << student->getName() << " je vec upisan/a u " << course_name << endl;
        return;
    }

    *student += *course;
    cout << student->getName() << " upisan/a u " << course_name
        << " (" << course->getEcts() << " ECTS)" << endl;
}

void StudentOffice::process_exam_results(int student_id, const string& course_name, bool passed) {
    Student* student = find_student(student_id);
    Course* course = find_course(course_name);

    if (!student || !course) {
        if (!student) cout << "Student/ica s id-em " << student_id << " nije pronadjen/a." << endl;
        if (!course) cout << "Kolegij " << course_name << " nije pronadjen." << endl;
        return;
    }

    if (passed) {
        if (student->complete_course(*course)) {
            cout << student->getName() << " POLOZIO/LA " << course_name
                << " (" << course->getEcts() << " ECTS)" << endl;
        }
        else {
            cout << student->getName() << " ne moze poloziti " << course_name
                << " (nije upisan/a ili je vec polozio/la)" << endl;
        }
    }
    else {
        cout << student->getName() << " JE PAO/LA " << course_name << endl;
    }
}

void StudentOffice::update_student_years() {
    cout << "\n=== AZURIRANJE STUDENTSKIH GODINA (KRAJ AKADEMSKE GODINE) ===" << endl;

    for (auto& student : students) {
        int current_year = student.getYear();

        student++;

        int ects = calculate_current_year_ects(student);
        if (ects >= UniversityConstants::REQUIRED_ECTS_PER_YEAR) {
            student.setYear(student.getYear() + 1);
            cout << student.getName() << " prebacen/a na godinu " << student.getYear()
                      << " (" << ects << " ECTS)" << endl;
        } else {
            cout << student.getName() << " ostaje na godini " << student.getYear()
                      << " (treba " << (UniversityConstants::REQUIRED_ECTS_PER_YEAR - ects)
                      << " vise ECTS)" << endl;
        }
    }
}

Student* StudentOffice::find_student(int student_id) {
    for (auto& student : students) {
        if (student.getId() == student_id) {
            return &student;
        }
    }
    return nullptr;
}

Course* StudentOffice::find_course(const string& course_name) {
    for (auto& course : available_courses) {
        if (course.getName() == course_name) {
            return &course;
        }
    }
    return nullptr;
}

int StudentOffice::calculate_current_year_ects(const Student& student) const {
    return student.get_total_ects();
}

void StudentOffice::simulate_academic_year() {
    cout << "\n=== SIMULACIJA AKADEMSKE GODINE ===" << endl;

    for (auto& student : students) {
        for (int i = 0; i < 3 && i < available_courses.size(); i++) {
            enroll_student(student.getId(), available_courses[i].getName());
        }
    }

    cout << "\n--- REZULTATI ISPITA ---" << endl;
    for (auto& student : students) {
        for (int i = 0; i < available_courses.size(); i++) {
            if (student.is_enrolled(available_courses[i])) {
                bool passed = (rand() % 100) < 50;
                process_exam_results(student.getId(), available_courses[i].getName(), passed);
            }
        }
    }

    update_student_years();
}

void StudentOffice::print_all_students() const {
    cout << "\n=== SVI STUDENTI ===" << endl;
    for (const auto& student : students) {
        cout << student << endl;
        student.print_enrolled_courses();
        student.print_completed_courses();
        cout << endl;
    }
}

void StudentOffice::print_all_courses() const {
    cout << "\n=== DOSTUPNI KOLEGIJI ===" << endl;
    for (const auto& course : available_courses) {
        cout << course << endl;
    }
}