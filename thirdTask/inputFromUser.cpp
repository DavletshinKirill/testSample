#include <iostream>
#include <limits>

using namespace std;

#define SIZE_STRING 100

char* inputString() {
    char* inputString = new char[SIZE_STRING];
    cout << "Enter string (to " << SIZE_STRING - 1 << " characters): ";
    std::cin.getline(inputString, SIZE_STRING);
    return inputString;
}