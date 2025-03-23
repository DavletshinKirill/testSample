#include <iostream>
#include "bookFactory.cpp"

#define EMPTY_VECTOR 0
#define PAGES_AMOUNT 1605

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