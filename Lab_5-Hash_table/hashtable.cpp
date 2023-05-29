#include "HashTable.h"
#include <cmath>

using namespace std;
#define MAX_TABLE_SIZE 100000
#define DIGIT_GROUP_UP 5

HashTable::HashTable() {
    currentSize = 0;
    arr = new HashElement * [MAX_TABLE_SIZE];

    for (int i = 0; i < MAX_TABLE_SIZE; ++i) {
        arr[i] = nullptr;

    }

    deletedElement = new HashElement("", -1);
}

int HashTable::HashFunction(const std::string& key) {
    unsigned int digitPos = 0;
    unsigned int keyValue = 0;
    for (int c : key) {
        if (c >= 'a' && c <= 'z') {
            int digit = c - 'a';
            keyValue = keyValue + digit * pow('z' - 'a' + 1, digitPos);
            digitPos = (digitPos + 1) % (DIGIT_GROUP_UP + 1);

        }

    }
    keyValue %= MAX_TABLE_SIZE;

    return keyValue;
}

void HashTable::Insert(const std::string& key, int value) {
    if (currentSize >= MAX_TABLE_SIZE)
        return;

    auto* temp = new HashElement(key, value);
    int hashIndex = HashFunction(key);

    while (arr[hashIndex] != nullptr &&
        !arr[hashIndex]->key.empty()) {
        ++hashIndex;
        hashIndex %= MAX_TABLE_SIZE;

    }

    if (arr[hashIndex] == nullptr ||
        arr[hashIndex]->key.empty()) {
        ++currentSize;
        arr[hashIndex] = temp;

    }
}

int HashTable::Search(const std::string& key) {
    if (currentSize >= MAX_TABLE_SIZE)
        return -1;

    int hashIndex = HashFunction(key);
    while (arr[hashIndex] != nullptr &&
        arr[hashIndex]->key != deletedElement->key) {
        if (arr[hashIndex]->key == key)
            return arr[hashIndex]->value;
        ++hashIndex;
        hashIndex %= MAX_TABLE_SIZE;

    }

    return -1;
}

void HashTable::Remove(const std::string& key) {
    int hashIndex = HashFunction(key);

    while (arr[hashIndex] != nullptr &&
        arr[hashIndex] != deletedElement) {
        if (arr[hashIndex]->key == key) {
            arr[hashIndex] = deletedElement;
            --currentSize;
            return;

        }
        ++hashIndex;
        hashIndex %= MAX_TABLE_SIZE;

    }
}

void HashTable::IncrementValue(const std::string& key) {
    int hashIndex = HashFunction(key);

    while (true) {
        if (arr[hashIndex]->key == key) {
            arr[hashIndex]->value++;
            return;

        }
        ++hashIndex;
        hashIndex %= MAX_TABLE_SIZE;

    }
}

int HashTable::GetValue(const string& key) {
    int hashIndex = HashFunction(key);

    while (arr[hashIndex] != nullptr &&
        arr[hashIndex]->key != deletedElement->key) {
        if (arr[hashIndex]->key == key) {
            return arr[hashIndex]->value;

        }
        ++hashIndex;
        hashIndex %= MAX_TABLE_SIZE;

    }
    return 0;
}