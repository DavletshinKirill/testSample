#include "../include/bookFactory.hpp"
#include "book.cpp"

BookFactory::BookFactory()
{
    books = new std::vector<Book*>();
}

BookFactory::~BookFactory()
{
    for (Book* bookPtr : *books) {
        if (bookPtr != nullptr) {
            delete bookPtr;
            bookPtr = nullptr; 
        }
    }
    delete books;
}

void BookFactory::fillVectorFiveBooks()
{
    books->push_back(new Book("1984", "George Orwell", 1949, 328));
    books->push_back(new Book("To Kill a Mockingbird", "Harper Lee", 1960, 281));
    books->push_back(new Book("Pride and Prejudice", "Jane Austen", 1813, 432));
    books->push_back(new Book("The Master and Margarita", "Mikhail Bulgakov", 1967, 384));
    books->push_back(new Book("The Great Gatsby", "F. Scott Fitzgerald", 1925, 180));
}

std::vector<Book *>& BookFactory::getBooks()
{
    return *books;
}
