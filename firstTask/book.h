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
};

unsigned int countPages(std::vector<Book*> books);
Book* bookFactory(std::string title, std::string author, unsigned int year, unsigned pageAmount);
void deleteBookVector(std::vector<Book*> books);

#endif
