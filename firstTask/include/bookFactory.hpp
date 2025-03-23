#include "book.hpp"

class BookFactory
{
    private:
     std::vector<Book*>* books;
    public:
     BookFactory();
     ~BookFactory();
     void fillVectorFiveBooks();
     std::vector<Book*>& getBooks();
};
