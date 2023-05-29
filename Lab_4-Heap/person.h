#ifndef HEAPS_PERSON_H
#define HEAPS_PERSON_H
#include <iostream>
#include <string>

class Person {
public:
    static bool comparator;
    std::string name;
    std::string date;

    static void switchComparator();

    friend bool operator<(const Person& left, const Person& right);
    friend bool operator>(const Person& left, const Person& right);
    friend bool operator<=(const Person& left, const Person& right);
    friend bool operator>=(const Person& left, const Person& right);
    friend bool operator==(const Person& left, const Person& right);

    friend std::ostream& operator<<(std::ostream& os, const Person& person);
};


#endif //HEAPS_PERSON_H