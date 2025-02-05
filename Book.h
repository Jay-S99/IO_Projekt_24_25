#include <string>

using namespace std;

class Book {
public:
    Book(const std::string& title, const std::string& author) : title(title), author(author) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }

private:
    string title;
    string author;
};
