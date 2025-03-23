#include <iostream>
#include "bookFactory.cpp"
#include <cassert>

#define EMPTY_VECTOR 0
#define PAGES_AMOUNT 1605

int main()
{
    BookFactory* bookFactory = new BookFactory();
     unsigned int result = countPages(bookFactory->getBooks());
     assert(result == EMPTY_VECTOR);
     std::cout << "Result " << result << "\nExpected value " << EMPTY_VECTOR << "\nFirst test was passed successfully" << std::endl;
     bookFactory->fillVectorFiveBooks();
     result = countPages(bookFactory->getBooks());
     assert(result == PAGES_AMOUNT);
     std::cout << "Result " << result << "\nExpected value " << PAGES_AMOUNT << "\nSecond test was passed successfully" <<std::endl;
 
     bookFactory->fillVectorFiveBooks();
     result = countPages(bookFactory->getBooks());
     assert(result == PAGES_AMOUNT * 2);
     std::cout << "Result " << result << "\nExpected value " << PAGES_AMOUNT * 2 <<"\nThird test was passed successfully" <<std::endl;
 
     delete bookFactory;
}