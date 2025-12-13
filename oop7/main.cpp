#include "StudentOffice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    cout << "=== SUSTAV UPRAVLJANJA SVEUCILISTA ===" << endl;

    StudentOffice office;

    Student student1(1001, "Ana Aniæ", "Informatika", 1);
    Student student2(1002, "Marko Markiæ", "Raèunarstvo", 1);
    Student student3(1003, "Iva Iviæ", "Matematika", 2);
    Student student4(1004, "Petar Petriæ", "Fizika", 1);
    Student student5(1005, "Luka Lukiæ", "Informatika", 3);

    cout << "\n--- Dodavanje studenata na sveuciliste ---" << endl;
    office.add_student(student1);
    office.add_student(student2);
    office.add_student(student3);
    office.add_student(student4);
    office.add_student(student5);

    office.print_all_students();

    office.print_all_courses();

    cout << "\n=== PREMJESTANJE STUDENATA NA NOVI SMJER ===" << endl;
    Student* petar = office.find_student(1004);
    if (petar) {
        cout << "Prije premjestaja: " << petar->getName()
            << ", Smjer: " << petar->getStudyProgram() << endl;
        office.moveStudent(*petar, "Astrofizika");
        cout << "Nakon premjestaja: " << petar->getName()
            << ", Smjer: " << petar->getStudyProgram() << endl;
    }

    cout << "\n=== UPISIVANJE STUDENATA NA KOLEGIJE ===" << endl;

    office.enroll_student(1001, "Matematika 1");
    office.enroll_student(1001, "Fizika 1");
    office.enroll_student(1001, "Programiranje 1");
    office.enroll_student(1001, "Osnove elektrotehnike");
    office.enroll_student(1001, "Baze podataka");
    office.enroll_student(1001, "Web dizajn");

    office.enroll_student(1002, "Matematika 1");
    office.enroll_student(1002, "Programiranje 1");

    office.enroll_student(1003, "Baze podataka");
    office.enroll_student(1003, "Web dizajn");

    cout << "\n=== PROCESIRANJE REZULTATA ISPITA ===" << endl;

    office.process_exam_results(1001, "Matematika 1", true);
    office.process_exam_results(1001, "Fizika 1", false); // Padne
    office.process_exam_results(1001, "Programiranje 1", true);

    office.process_exam_results(1002, "Matematika 1", true);
    office.process_exam_results(1002, "Programiranje 1", true);

    office.process_exam_results(1003, "Baze podataka", true);
    office.process_exam_results(1003, "Web dizajn", true);

    cout << "\n=== AZURIRANJE STUDENTSKIH GODINA ===" << endl;
    office.update_student_years();

    cout << "\n=== SIMULACIJA CIJELE AKADEMSKE GODINE ===" << endl;

    StudentOffice office2;

    Student s1(2001, "Maja Majiæ", "Informatika", 1);
    Student s2(2002, "Karlo Karloviæ", "Raèunarstvo", 1);
    Student s3(2003, "Sara Sariæ", "Matematika", 2);

    office2.add_student(s1);
    office2.add_student(s2);
    office2.add_student(s3);

    office2.add_course(Course("Objektno programiranje", 2001, 5));
    office2.add_course(Course("Strukture podataka", 2002, 5));
    office2.add_course(Course("Arhitektura raèunala", 2003, 5));

    office2.simulate_academic_year();

    cout << "\n=== KONACNO STANJE NAKON SIMULACIJE ===" << endl;
    office2.print_all_students();

    cout << "\n=== RULE OF FIVE DEMONSTRACIJA ===" << endl;
    {
        Student test_student(3001, "Test student", "Test smjer", 1);
        office2.add_student(test_student);

        Student copy_student = test_student;
        cout << "Kopija kreirana: " << copy_student.getName() << endl;

        Student moved_student = move(test_student);
        cout << "Move izvrsen. Originalno ime: " << test_student.getName()
            << ", Premjesteno ime: " << moved_student.getName() << endl;
    }

    cout << "\n=== BROJAC STUDENATA ===" << endl;
    cout << "Ukupan broj studenata kreiranih kroz program: "
        << Student::get_total_students() << endl;

    cout << "\n=== KONACNO STANJE ORIGINALNOG SVEUCILISTA ===" << endl;
    office.print_all_students();

    cout << "\n=== PROGRAM USPJESNO ZAVRSEN ===" << endl;

    return 0;
}