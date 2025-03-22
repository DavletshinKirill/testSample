#include "book.h"

unsigned int countPages(std::vector<Book*> books) {
    unsigned int bookPagesCounter = 0;
    for (Book* book : books) {
        bookPagesCounter += book->pageAmount;
    }
    return bookPagesCounter;
}

Book* bookFactory(std::string title, std::string author, unsigned int year, unsigned pageAmount)
{
    Book* book = new Book;
    book->author = author;
    book->title = title;
    book-> year = year;
    book->pageAmount = pageAmount;
    return book;
}

void deleteBookVector(std::vector<Book*> books)
{
    for (Book* bookPtr : books) {
        if (bookPtr != nullptr) {
            delete bookPtr;
            bookPtr = nullptr; 
        }
    }
}
