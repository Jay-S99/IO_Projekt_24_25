#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author) : title(title), author(author) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }

private:
    std::string title;
    std::string author;
};

#endif
