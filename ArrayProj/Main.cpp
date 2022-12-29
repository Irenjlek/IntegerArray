#include "IntegerArray.h"
#include "BadLength.h"
#include "BadRange.h"
#include "Array.h"
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

    std::cout << array.FirstIndexOf(12) << std::endl;
    
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
    
    std::cout << "------------------------------" << std::endl;

    //create and fill
    Array<double> aArray(10);
    for (int i = 0; i < aArray.getLength(); ++i) {
        aArray[i] = i * 1.2;
    }
    
    //copy
    Array<double> acopy = aArray;
    std::cout << acopy.getLength() << std::endl; //10

    for (int i = 0; i < acopy.getLength(); ++i) { //0 1.2 2.4 3.6 4.8 6 7.2 8.4 9.6 10.8
        std::cout << acopy[i] << ' ';
    }
    std::cout << std::endl;

    //resize
    acopy.resize(3);
    std::cout << acopy.getLength() << std::endl; //3
    for (int i = 0; i < acopy.getLength(); ++i) { //0 1.2 2.4
        std::cout << acopy[i] << ' ';
    }
    std::cout << std::endl;

    //insert
    aArray.insertBefore(12.8, 3);
    for (int i = 0; i < aArray.getLength(); ++i) { //0 1.2 2.4 12.8 3.6 4.8 6 7.2 8.4 9.6 10.8
        std::cout << aArray[i] << ' ';
    }
    std::cout << std::endl;

    aArray.insertAtBeginning(13.1);
    for (int i = 0; i < aArray.getLength(); ++i) { //13.1 0 1.2 2.4 12.8 3.6 4.8 6 7.2 8.4 9.6 10.8
        std::cout << aArray[i] << ' ';
    }
    std::cout << std::endl;

    aArray.insertAtEnd(14.7);
    for (int i = 0; i < aArray.getLength(); ++i) { //13.1 0 1.2 2.4 12.8 3.6 4.8 6 7.2 8.4 9.6 10.8 14.7
        std::cout << aArray[i] << ' ';
    }
    std::cout << std::endl;

    //remove
    aArray.remove(0);
    for (int i = 0; i < aArray.getLength(); ++i) { //0 1.2 2.4 12.8 3.6 4.8 6 7.2 8.4 9.6 10.8 14.7
        std::cout << aArray[i] << ' ';
    }
    std::cout << std::endl;

    //exceptions
    try {
        Array<double> array(0);
    }
    catch (BadLength& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << aArray[3] << std::endl; //12.8
        double a = aArray[13];
    }
    catch (BadRange& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        aArray.insertBefore(12.9, -1);
    }
    catch (BadRange& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        aArray.remove(50);
    }
    catch (BadRange& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}