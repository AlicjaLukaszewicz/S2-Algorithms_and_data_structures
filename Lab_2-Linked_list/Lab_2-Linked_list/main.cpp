#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    char operation = 0;
    int index, value;
    LinkedList list;
    while (operation != 'q') {
        cin >> operation;
        if (operation == 'i') {
            cin >> value;
            cin >> index;
            list.i(index,value);
        
} else if (operation == 'q') list.q();
        else if (operation == 'g') {
            cin >> index;
            cout << list.g(index) << endl;
        
} else if (operation == 'd') {
            cin >> index;
            list.d(index);
        
}
    
}

    return 0;
}