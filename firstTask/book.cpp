#include "book.h"

unsigned int countPages(std::vector<Book*> books) {
    unsigned int bookPagesCounter = 0;
    for (Book* book : books) {
        bookPagesCounter += book->pageAmount;
    }
    return bookPagesCounter;
}
