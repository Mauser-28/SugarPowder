#include "functions.h"

std::istream& operator>>(std::istream& is, Student& s) {
    is >> s.course >> s.group >> s.surname >> s.name >> s.patronymic >> s.grade1 >> s.grade2 >> s.grade3;
    return is;
}

std::ostream& operator<<(std::ostream& os, Student& s) {
    os << s.course << ' ' << s.group << ' ' << s.surname << ' ' << s.name << ' ' << s.patronymic << ' ' << s.grade1 << ' ' << s.grade2 << ' ' << s.grade3;
    return os;
}

bool operator>(const Student& a, const Student& b) {
    if (a.course != b.course) {
         return a.course > b.course;
    }
    if (a.group != b.group) {
        return a.group > b.group;
    }
    return a.surname + a.name + a.patronymic > b.surname + b.name + b.patronymic;
}

bool operator<(const Student& a, const Student& b) {
    if (a.course != b.course) {
        return a.course < b.course;
    }
    if (a.group != b.group) {
        return a.group < b.group;
    }
    return a.surname + a.name + a.patronymic < b.surname + b.name + b.patronymic;
}

bool operator<=(const Student& a, const Student& b) {
    if (a.course != b.course) {
        return a.course <= b.course;
    }
    if (a.group != b.group) {
        return a.group <= b.group;
    }
    return a.surname + a.name + a.patronymic <= b.surname + b.name + b.patronymic;
}

bool IsReversed() {
	std::cout << "press 1 to reverse increasing sort\nor \npress 0 to continue without changes\n";
	bool reverse{};
	std::cin >> reverse;
	return reverse;
}

void FillRandomArray(int* array, int size) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 1000);
    for (int i = 0; i < size; ++i)
        array[i] = dist(rng);
}

void FillRandomArray(double* array, int size) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(0.0, 1000.0);
    for (int i = 0; i < size; ++i)
        array[i] = dist(rng);
}

void FillRandomArray(char* array, int size) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(33, 126);
    for (int i = 0; i < size; ++i)
        array[i] = static_cast<char>(dist(rng));
}