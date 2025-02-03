#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isAvailable;

    Book() : id(0), title(""), author(""), isAvailable(true) {}

    Book(int bookID, const string& bookTitle, const string& bookAuthor, bool availability = true)
        : id(bookID), title(bookTitle), author(bookAuthor), isAvailable(availability) {}

    static Book fromString(const string& line);

    string toString() const;
};

class BookManager
{
private:
    vector<Book> books;
    int nextBookID;
    const string filename; 
    void loadFromFile();
    void saveToFile() const;
public:
    BookManager(const string& file);
    ~BookManager();
    void removeBook(int id);
    void searchBook(const string& keyword) const;
    void displayBooks() const;
    void updateAvailability(int id, bool availability);
void addBook(int id, const string& title, const string& author, bool available);
};
