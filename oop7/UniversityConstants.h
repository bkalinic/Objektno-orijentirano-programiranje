#ifndef UNIVERSITYCONSTANTS_H
#define UNIVERSITYCONSTANTS_H

#include <iostream>

struct UniversityConstants {
    static const int MAX_ETCS_PER_YEAR = 60;
    static const int REQUIRED_ECTS_PER_YEAR = 45;
    static const int MINIMAL_YEAR = 1;
    static const int MAXIMAL_YEAR = 5;
    static const double PASSING_GRADE;

    static void print_university_rules();
};

#endif