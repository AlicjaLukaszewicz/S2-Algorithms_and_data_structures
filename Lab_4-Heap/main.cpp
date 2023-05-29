#include <iostream>
#include "Heap.h"

int main() {
    Heap heap;
    char command;

    int n;
    while (true) {
        std::cin >> command;
        if (command == '+') {
            std::cin >> n;
            for (int i = 0; i < n; ++i) {
                Person newPerson;
                std::cin >> newPerson.date; 
                std::cin >> newPerson.name;
                heap.push(newPerson);
            
}
        
} else if (command == '-') {
            std::cin >> n;
            for (int i = 0; i < n; ++i) {
                heap.printRoot();
                heap.pop();
            
}
            std::cout << std::endl;
        
} else if (command == 'p') {
            heap.print();
        
} else if (command == 'r') {
            Person::switchComparator();
            heap.buildHeap();
        
} else if (command == 'q')
            break;
    
}
    return 0;
}