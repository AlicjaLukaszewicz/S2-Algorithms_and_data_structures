#include "Person.h"
bool Person::comparator = false;

void Person::switchComparator() {
    if (comparator)
        comparator = false;
    else
        comparator = true;
}

bool operator<(const Person& left, const Person& right) {
    if (!Person::comparator)
        return left.name < right.name;
    else { //dd-mm-yyyy
        int arr[] = { 6, 7, 8, 9, 3, 4, 0, 1
        };

        for (int i = 0; i < 8; ++i) {
            if (left.date[arr[i]] < right.date[arr[i]])
                return true;
            else if (left.date[arr[i]] > right.date[arr[i]])
                return false;

        }
        return false;

    }
}

bool operator>(const Person& left, const Person& right) {
    return right < left;
}

bool operator<=(const Person& left, const Person& right) {
    return !(left > right);
}

bool operator>=(const Person& left, const Person& right) {
    return !(left < right);
}

bool operator==(const Person& left, const Person& right) {
    return (!(left < right) && !(right < left));
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    std::cout << person.date << " " << person.name;
    return os;
}