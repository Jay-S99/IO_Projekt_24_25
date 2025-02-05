#include "Book.h"
#include <vector>
#include <string>

using namespace std;

class BookManager {
public:
    void loadBooks();
    void saveBooks();
    void addBook(const Book& book);
    void removeBook(const string& title);
    vector<Book> getAllBooks() const;
    Book* searchBook(const string& title);
    vector<Book>& getBooks();

private:
    vector<Book> books;
};
