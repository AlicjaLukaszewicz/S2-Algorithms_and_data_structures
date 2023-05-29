#include <iostream>
#include "HashTable.h"
#define STARTING_VALUE 1

using namespace std;
int main() {
    HashTable* hashTable = new HashTable();
    string key;

    while (!feof(stdin)) {
        cin >> key;

        if (key[0] == '?') {
            key.erase(0, 1);
            cout << hashTable->GetValue(key) << endl;

        }
        else if (key[0] == '-') {
            key.erase(0, 1);
            hashTable->Remove(key);

        }
        else if (key == "q") {
            return 0;

        }
        else {
            int index = hashTable->Search(key);
            if (index == -1) {
                hashTable->Insert(key, STARTING_VALUE);

            }
            else {
                hashTable->IncrementValue(key);

            }

        }

    }
}