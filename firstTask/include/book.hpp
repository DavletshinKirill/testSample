#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

struct Book 
{
    std::string title;
    std::string author;
    unsigned int year;
    unsigned int pageAmount;

    Book(std::string title, std::string author, unsigned int year, unsigned pageAmount);
};

unsigned int countPages(const std::vector<Book*>& books);

#endif
