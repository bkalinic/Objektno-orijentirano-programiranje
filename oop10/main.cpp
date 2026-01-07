#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>

void zadatak1() {
    std::vector<int> brojevi = { 2, 4, 6, 8, 10, 3, 12, 5, 16, 7, 1, 32 };

    auto prviNeparni = std::find_if(brojevi.begin(), brojevi.end(),
        [](int n) { return n % 2 != 0; });
    if (prviNeparni != brojevi.end()) {
        std::cout << "Prvi neparni broj: " << *prviNeparni << std::endl;
    }

    int brojNeparnih = std::count_if(brojevi.begin(), brojevi.end(),
        [](int n) { return n % 2 != 0; });
    std::cout << "Ukupno neparnih brojeva: " << brojNeparnih << std::endl;

    int sumaNeparnih = std::accumulate(brojevi.begin(), brojevi.end(), 0,
        [](int acc, int n) { return n % 2 != 0 ? acc + n : acc; });
    if (brojNeparnih > 0) {
        double prosjekNeparnih = static_cast<double>(sumaNeparnih) / brojNeparnih;
        std::cout << "Prosjek neparnih brojeva: " << prosjekNeparnih << std::endl;
    }

    std::transform(brojevi.begin(), brojevi.end(), brojevi.begin(),
        [](int n) {
            if (n <= 0) return n;
            return (n & (n - 1)) == 0 ? 2 : n;
        });

    std::cout << "Nakon zamjene: ";
    for (int n : brojevi) std::cout << n << " ";
    std::cout << std::endl;

    std::vector<int> parni, neparni;
    for (int n : brojevi) {
        if (n % 2 == 0) parni.push_back(n);
        else neparni.push_back(n);
    }

    std::sort(parni.begin(), parni.end());
    std::sort(neparni.begin(), neparni.end());

    std::cout << "Parni (sortirani): ";
    for (int n : parni) std::cout << n << " ";
    std::cout << std::endl;

    std::cout << "Neparni (sortirani): ";
    for (int n : neparni) std::cout << n << " ";
    std::cout << std::endl;
}

namespace math_utils {
    struct Point {
        double x, y;

        Point() : x(0), y(0) {}
        Point(double x_, double y_) : x(x_), y(y_) {}
    };

    double distance(const Point& p1, const Point& p2) {
        return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
    }

    Point centroid(const std::vector<Point>& points) {
        if (points.empty()) return Point(0, 0);

        double sumX = std::accumulate(points.begin(), points.end(), 0.0,
            [](double acc, const Point& p) { return acc + p.x; });
        double sumY = std::accumulate(points.begin(), points.end(), 0.0,
            [](double acc, const Point& p) { return acc + p.y; });

        return Point(sumX / static_cast<double>(points.size()),
            sumY / static_cast<double>(points.size()));
    }
}

void zadatak2() {
    std::ifstream file("points.txt");
    if (!file.is_open()) {
        std::cout << std::endl << "Nije moguce otvoriti datoteku points.txt" << std::endl;
        return;
    }

    std::vector<math_utils::Point> points;
    double x, y;
    while (file >> x >> y) {
        points.emplace_back(x, y);
    }
    file.close();

    if (points.empty()) {
        std::cout << std::endl << "Datoteka je prazna ili nema tocaka." << std::endl;
        return;
    }

    math_utils::Point ishodiste(0, 0);
    std::sort(points.begin(), points.end(),
        [&ishodiste](const math_utils::Point& p1, const math_utils::Point& p2) {
            double d1 = math_utils::distance(p1, ishodiste);
            double d2 = math_utils::distance(p2, ishodiste);
            return d1 < d2;
        });

    std::cout << std::endl << "Tocke sortirane po udaljenosti od ishodista:" << std::endl;
    for (const auto& p : points) {
        std::cout << "(" << p.x << ", " << p.y << ") ";
    }
    std::cout << std::endl;

    int prviKvadrant = std::count_if(points.begin(), points.end(),
        [](const math_utils::Point& p) {
            return p.x > 0 && p.y > 0;
        });
    std::cout << "Broj tocaka u prvom kvadrantu: " << prviKvadrant << std::endl;

    math_utils::Point cent = math_utils::centroid(points);
    std::cout << "Centroid: (" << cent.x << ", " << cent.y << ")" << std::endl;

    std::transform(points.begin(), points.end(), points.begin(),
        [](const math_utils::Point& p) {
            return math_utils::Point(p.x + 5, p.y + 3);
        });

    std::cout << "Tocke nakon pomaka za (5, 3):" << std::endl;
    for (const auto& p : points) {
        std::cout << "(" << p.x << ", " << p.y << ") ";
    }
    std::cout << std::endl;

    auto it = std::remove_if(points.begin(), points.end(),
        [](const math_utils::Point& p) {
            return p.x < 0 && p.y < 0;
        });
    points.erase(it, points.end());

    std::cout << "Tocke nakon uklanjanja onih s obje koordinate negativne:" << std::endl;
    for (const auto& p : points) {
        std::cout << "(" << p.x << ", " << p.y << ") ";
    }
    std::cout << std::endl;
}

namespace student_records {
    class Student {
    public:
        std::string ime;
        std::string prezime;
        int bodovi;

        Student() : bodovi(0) {}
        Student(std::string i, std::string p, int b) : ime(i), prezime(p), bodovi(b) {}

        friend std::ostream& operator<<(std::ostream& os, const Student& s) {
            os << s.prezime << ", " << s.ime << ": " << s.bodovi << " bodova";
            return os;
        }
    };

    int bodovi_u_ocjenu(int bodovi) {
        if (bodovi >= 85 && bodovi <= 100) return 5;
        else if (bodovi >= 70 && bodovi <= 84) return 4;
        else if (bodovi >= 55 && bodovi <= 69) return 3;
        else if (bodovi >= 40 && bodovi <= 54) return 2;
        else return 1;
    }
}

void zadatak3() {
    std::ifstream file("studenti.txt");
    if (!file.is_open()) {
        std::cout << std::endl << "Nije moguce otvoriti datoteku studenti.txt" << std::endl;
        return;
    }

    std::vector<student_records::Student> studenti;
    std::string ime, prezime;
    int bodovi;

    while (file >> ime >> prezime >> bodovi) {
        studenti.emplace_back(ime, prezime, bodovi);
    }
    file.close();

    if (studenti.empty()) {
        std::cout << std::endl << "Nema studenata u datoteci." << std::endl;
        return;
    }

    std::cout << std::endl << "Studenti:" << std::endl;
    for (const auto& s : studenti) {
        std::cout << s << std::endl;
    }

    auto it = std::remove_if(studenti.begin(), studenti.end(),
        [](const student_records::Student& s) {
            return s.bodovi < 40;
        });
    studenti.erase(it, studenti.end());

    std::cout << "\nNakon filtera:" << std::endl;
    for (const auto& s : studenti) {
        std::cout << s << std::endl;
    }

    std::transform(studenti.begin(), studenti.end(), studenti.begin(),
        [](student_records::Student s) {
            s.bodovi = student_records::bodovi_u_ocjenu(s.bodovi);
            return s;
        });

    std::cout << "\nNakon map-a:" << std::endl;
    for (const auto& s : studenti) {
        std::cout << s.prezime << ", " << s.ime << ": ocjena " << s.bodovi << std::endl;
    }

    if (!studenti.empty()) {
        double sumaOcjena = std::accumulate(studenti.begin(), studenti.end(), 0.0,
            [](double acc, const student_records::Student& s) {
                return acc + s.bodovi;
            });
        double prosjekOcjena = sumaOcjena / static_cast<double>(studenti.size());
        std::cout << "\nProsjek ocjena: " << prosjekOcjena << std::endl;
    }

    std::sort(studenti.begin(), studenti.end(),
        [](const student_records::Student& s1, const student_records::Student& s2) {
            return s1.prezime < s2.prezime;
        });

    std::cout << "\nKonacni izvjestaj:" << std::endl;
    for (const auto& s : studenti) {
        std::cout << s.prezime << ", " << s.ime << ": ocjena " << s.bodovi << std::endl;
    }
}

int main() {
    zadatak1();
    zadatak2();
    zadatak3();

    return 0;
}