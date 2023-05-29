#include <iostream>
using namespace std;

int binarySearchPositive(int *arr, int arraySize, int numberToBeFound)
{
    int left = 0, right = arraySize-1;
    while (left <= right) {
        int m = left + (right - left) / 2;
        if (arr[m] == numberToBeFound)
            return m;
        if (arr[m] > numberToBeFound)
            right = m - 1;
        else
            left = m + 1;
    
}
    return -1;
}
int binarySearchNegative(int *arr, int arraySize, int numberToBeFound)
{
    int left = 0, right = arraySize-1;
    while (left <= right) {
        int m = left + (right - left) / 2;
        if (arr[m] == numberToBeFound)
            return m;
        if (arr[m] > numberToBeFound)
            left = m + 1;
        else
            right = m - 1;
    
}
    return -1;
}

int main()
{
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; ++i) {
        int arraySize = 0, *array = nullptr;
        cin >> arraySize;
        array = new int[arraySize];
        for (int j = 0; j < arraySize; ++j) {
            cin >> array[j];
        
}
        int elementsToBeFound = 0, *elementArray = nullptr;
        cin >> elementsToBeFound;
        elementArray = new int[elementsToBeFound];
        for (int j = 0; j < elementsToBeFound; ++j) {
            cin >> elementArray[j];
        
}
        if (array[0] < array[1]) {
            for (int j = 0; j < elementsToBeFound; ++j) {
                cout << binarySearchPositive(array, arraySize, elementArray[j]) << endl;
            
}
        
}
        else if (array[0] > array[1]) {
            for (int j = 0; j < elementsToBeFound; ++j) {
                cout << binarySearchNegative(array, arraySize, elementArray[j]) << endl;
            
}
        
}
        delete [] array;
        delete [] elementArray;
    
}

    return 0;
}