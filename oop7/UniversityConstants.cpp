#include "UniversityConstants.h"
#include <iostream>

using namespace std;

const double UniversityConstants::PASSING_GRADE = 2.0;

void UniversityConstants::print_university_rules() {
    cout << "=== University Rules ===" << endl;
    cout << "1. Maximum ECTS per year: " << MAX_ETCS_PER_YEAR << endl;
    cout << "2. Required ECTS per year: " << REQUIRED_ECTS_PER_YEAR << endl;
    cout << "3. Minimal study year: " << MINIMAL_YEAR << endl;
    cout << "4. Maximal study year: " << MAXIMAL_YEAR << endl;
    cout << "5. Passing grade: " << PASSING_GRADE << endl;
    cout << "=========================" << endl;
}
