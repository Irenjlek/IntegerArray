#include "IntegerArray.h"
#include "BadLength.h"
#include "BadRange.h"
#include <iostream>

int main() {
    //create and fill
    IntegerArray array(10);
    for (int i = 0; i < array.getLength(); ++i) {
        array[i] = i;
    }

    //copy
    IntegerArray copy = array;
    std::cout << copy.getLength() << std::endl; //10

    for (int i = 0; i < copy.getLength(); ++i) { //0 1 2 3 4 5 6 7 8 9
        std::cout << copy[i] << ' ';
    }
    std::cout << std::endl;

    //resize
    copy.resize(3);
    std::cout << copy.getLength() << std::endl; //3
    for (int i = 0; i < copy.getLength(); ++i) { //0 1 2
        std::cout << copy[i] << ' ';
    }
    std::cout << std::endl;

    //insert
    array.insertBefore(12, 3);
    for (int i = 0; i < array.getLength(); ++i) { //0 1 2 12 3 4 5 6 7 8 9
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    array.insertAtBeginning(13);
    for (int i = 0; i < array.getLength(); ++i) { //13 0 1 2 12 3 4 5 6 7 8 9
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    array.insertAtEnd(14);
    for (int i = 0; i < array.getLength(); ++i) { //13 0 1 2 12 3 4 5 6 7 8 9 14
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    //remove
    array.remove(0);
    for (int i = 0; i < array.getLength(); ++i) { //0 1 2 12 3 4 5 6 7 8 9 14
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    //exceptions
    try {
        IntegerArray array(0);
    }
    catch (BadLength& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << array[3] << std::endl; //12
        int a = array[13];
    }
    catch (BadRange& e) {
        std::cout << e.what() << std::endl;
    }
      
    try {
        array.insertBefore(12, -1);
    }
    catch (BadRange& e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
        array.remove(50);
    }
    catch (BadRange& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}