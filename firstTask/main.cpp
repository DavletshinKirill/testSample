#include <iostream>
#include "book.cpp"
#include <cassert>

#define PAGES_AMOUNT 1605

int main()
{
    std::vector<Book*> books(5, nullptr); 
    books[0] = new Book;
    books[0]->title = "1984";
    books[0]->author = "George Orwell";
    books[0]->year = 1949;
    books[0]->pageAmount = 328;

    books[1] = new Book;
    books[1]->title = "To Kill a Mockingbird";
    books[1]->author = "Harper Lee";
    books[1]->year = 1960;
    books[1]->pageAmount = 281;

    books[2] = new Book;
    books[2]->title = "Pride and Prejudice";
    books[2]->author = "Jane Austen";
    books[2]->year = 1813;
    books[2]->pageAmount = 432;

    books[3] = new Book;
    books[3]->title = "The Master and Margarita";
    books[3]->author = "Mikhail Bulgakov";
    books[3]->year = 1967;
    books[3]->pageAmount = 384;

    books[4] = new Book;
    books[4]->title = "The Great Gatsby";
    books[4]->author = " F. Scott Fitzgerald";
    books[4]->year = 1925;
    books[4]->pageAmount = 180;

    unsigned int result = countPages(books);
    std::cout << "Result " << result << std::endl;
    assert(result == PAGES_AMOUNT);
    std::cout << "Test was passed successfully" << std::endl;
    for (Book* bookPtr : books) {
        if (bookPtr != nullptr) {
            delete bookPtr;
            bookPtr = nullptr; 
        }
    }
}