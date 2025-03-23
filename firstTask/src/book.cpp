#include "../include/book.hpp"

unsigned int countPages(std::vector<Book*>& books) 
{
    unsigned int bookPagesCounter = 0;
    for (const auto& book : books) {
        bookPagesCounter += book->pageAmount;
    }
    return bookPagesCounter;
}

Book::Book(std::string title, std::string author, unsigned int year, unsigned pageAmount): 
title(title), author(author), year(year), pageAmount(pageAmount) {}

