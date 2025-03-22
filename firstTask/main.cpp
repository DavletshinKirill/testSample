#include <iostream>
#include "book.cpp"
#include <cassert>

#define PAGES_AMOUNT 1605

int main()
{
    std::vector<Book*> books; 
    books.push_back(bookFactory("1984", "George Orwell", 1949, 328));
    books.push_back(bookFactory("To Kill a Mockingbird", "Harper Lee", 1960, 281));
    books.push_back(bookFactory("Pride and Prejudice", "Jane Austen", 1813, 432));
    books.push_back(bookFactory("The Master and Margarita", "Mikhail Bulgakov", 1967, 384));
    books.push_back(bookFactory("The Great Gatsby", "F. Scott Fitzgerald", 1925, 180));

    unsigned int result = countPages(books);
    std::cout << "Result " << result << std::endl;
    assert(result == PAGES_AMOUNT);
    std::cout << "Test was passed successfully" << std::endl;
    deleteBookVector(books);
}