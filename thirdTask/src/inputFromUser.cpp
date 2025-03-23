#include <iostream>
#include <cstring>

char* inputString() 
{
    std::string inputString;
    std::cout << "Input message: ";
    std::getline(std::cin, inputString);
    char* inputFromUserChar = new char[inputString.size() + 1];
    std::strcpy(inputFromUserChar, inputString.c_str());
    return inputFromUserChar;
}