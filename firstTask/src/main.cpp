#include <iostream>
#include "bookFactory.cpp"

int main()
{
    BookFactory* bookFactory = new BookFactory();
    unsigned int result = countPages(bookFactory->getBooks());
    std::cout << "Result " << result << "\nEmpty vector" << std::endl;

    bookFactory->fillVectorFiveBooks();
    result = countPages(bookFactory->getBooks());
    std::cout << "Result " << result << "\nVector filled with 5 items " << std::endl;

    bookFactory->fillVectorFiveBooks();
    result = countPages(bookFactory->getBooks());
    std::cout << "Result " << result << "\nVector filled with 10 items " << std::endl;

    delete bookFactory;
    return 0;
}