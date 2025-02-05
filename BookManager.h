#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include "Book.h"
#include <vector>
#include <string>

class BookManager {
public:
    void loadBooks();
    void saveBooks();
    void addBook(const Book& book);
    void removeBook(const std::string& title);
    std::vector<Book> getAllBooks() const;
    Book* searchBook(const std::string& title);
    std::vector<Book>& getBooks();

private:
    std::vector<Book> books;
};

#endif
