#include "Vector.h"

Vector::Vector(int capacity) {
    this->capacity = capacity;
    this->length = 0;
    this->arr = new Person[capacity];
}

void Vector::push_back(Person& person) {
    if (length == capacity) {
        Person* old = arr;
        arr = new Person[capacity * 2];
        for (int i = 0; i < capacity; ++i) {
            arr[i] = old[i];

        }
        capacity *= 2;
        delete[] old;

    }
    arr[length] = person;
    length++;
}

Person Vector::pop_back() {
    length--;
    return arr[length];
}

int Vector::size() const {
    return length;
}

Person& Vector::operator[](int index) {
    return *(arr + index);
}

Person& Vector::operator[](int index) const {
    return *(arr + index);
}

void Vector::deleteObjects() {
    delete[] arr;
}