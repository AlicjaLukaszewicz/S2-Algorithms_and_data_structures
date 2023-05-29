#include <iostream>
#include "LinkedList.h"
using namespace std;

int shellSort(LinkedList list[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i += 1) {
            LinkedList temp = list[i];
            int j;
            for (j = i; j >= gap && list[j - gap] > temp; j -= gap)
                list[j] = list[j - gap];
            list[j] = temp;

        }

    }
    return 0;
}

void printLists(LinkedList list[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < list[i].getSize(); ++j) {
            cout << (char)list[i].Search(j);

        }
        cout << endl;

    }
}

int main() {
    int number;
    cin >> number;
    cin.ignore();
    LinkedList* list = new LinkedList[number];

    for (int i = 0; i < number; ++i) {
        int size = 0;
        char c = cin.get();
        while (c != '\n') {
            list[i].Insert(size, c);
            c = cin.get();
            size++;

        }

    }

    shellSort(list, number);
    printLists(list, number);

    for (int i = 0; i < number; ++i) {
        list[i].FreeUpMemory();

    }
    delete[] list;
    return 0;
}