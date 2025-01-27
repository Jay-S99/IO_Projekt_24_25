#include "BookManager.h"
#include <fstream>
#include <sstream>
#include <algorithm>

Book::Book(int bookID, const string& bookTitle, const string& bookAuthor, bool availability)
    : id(bookID), title(bookTitle), author(bookAuthor), isAvilable(availability) {}

Book Book::fromString(const string& line) {
    stringstream ss(line);
    int id;
    string title, author;
    bool isAvailable;
    ss >> id;
    ss.ignore();
    getline(ss, title, '|');
    getline(ss, author, '|');
    ss >> isAvailable;
    return Book(id, title, author, isAvailable);
}

string Book::toString() const {
    stringstream ss;
    ss << id << " " << title << "|" << author << "|" << isAvilable;
    return ss.str();
}

BookManager::BookManager(const string& file) : filename(file), nextBookID(1) {
    loadFromFile();
}

BookManager::~BookManager() {
    saveToFile();
}

void BookManager::loadFromFile() {
    ifstream inFile(filename);
    if (!inFile.is_open()) return;

    string line;
    while (getline(inFile, line)) {
        Book book = Book::fromString(line);
        books.push_back(book);
        nextBookID = max(nextBookID, book.id + 1);
    }

    inFile.close();
}

void BookManager::saveToFile() const {
    ofstream outFile(filename);
    if (!outFile.is_open()) return;

    for (const auto& book : books) {
        outFile << book.toString() << "\n";
    }

    outFile.close();
}

void BookManager::removeBook(int id) {
    auto it = remove_if(books.begin(), books.end(), [id](const Book& book) { return book.id == id; });
    if (it != books.end()) {
        books.erase(it, books.end());
        cout << "Book with ID " << id << " has been removed.\n";
    }
    else {
        cout << "No book found with ID " << id << ".\n";
    }
}

void BookManager::searchBook(const string& keyword) const {
    cout << "Search results for: " << keyword << "\n";
    for (const auto& book : books) {
        if (book.title.find(keyword) != string::npos || book.author.find(keyword) != string::npos) {
            cout << "ID: " << book.id << " | Title: " << book.title << " | Author: " << book.author
                << " | Available: " << (book.isAvilable ? "Yes" : "No") << "\n";
        }
    }
}

void BookManager::displayBooks() const {
    cout << "Book List:\n";
    for (const auto& book : books) {
        cout << "ID: " << book.id << " | Title: " << book.title << " | Author: " << book.author
            << " | Available: " << (book.isAvilable ? "Yes" : "No") << "\n";
    }
}

void BookManager::updateAvailability(int id, bool availability) {
    for (auto& book : books) {
        if (book.id == id) {
            book.isAvilable = availability;
            cout << "Availability of book with ID " << id << " updated to " << (availability ? "Available" : "Not Available") << ".\n";
            return;
        }
    }
    cout << "No book found with ID " << id << ".\n";
}
