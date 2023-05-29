#ifndef OPENADDRESSING_HASHTABLE_H
#define OPENADDRESSING_HASHTABLE_H
#include "string"

class HashTable {

    class HashElement {
    public:
        std::string key;
        int value;

        HashElement() : key("") {
            this->value = 0;

        }
        HashElement(const std::string& newKey, int newValue) : key(newKey) {
            this->value = newValue;

        }
        ~HashElement() = default;

    };

    int currentSize;
    HashElement** arr;
    HashElement* deletedElement;

    int HashFunction(const std::string& key);
public:
    HashTable();

    void Insert(const std::string& key, int value);
    int Search(const std::string& key);
    void Remove(const std::string& key);
    void IncrementValue(const std::string& key);
    int GetValue(const std::string& key);
};


#endif //OPENADDRESSING_HASHTABLE_H