#include "BookManager.h"
#include "Book.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype> 

using namespace std;

void BookManager::loadBooks() {
    ifstream file("books.txt");
    string title, author;

    if (!file.is_open()) {
        cout << "Blad otwierania pliku ksiazek!" << endl;
        return;
    }

    books.clear();
    while (getline(file, title) && getline(file, author)) {
        if (!title.empty() && !author.empty()) {
            books.push_back(Book(title, author));
        }
    }

    file.close();
}

void BookManager::saveBooks() {
    ofstream file("books.txt");

    if (!file.is_open()) {
        cout << "Blad otwierania pliku do zapisu!" << endl;
        return;
    }

    for (const auto& book : books) {
        file << book.getTitle() << "\n" << book.getAuthor() << "\n";
    }

    file.close();
}

void BookManager::addBook(const Book& book) {
    books.push_back(book);
    saveBooks();
}

void BookManager::removeBook(const string& title) {
    vector<Book> updatedBooks;

    for (const auto& book : books) {
        if (book.getTitle() != title) {
            updatedBooks.push_back(book);
        }
    }

    books = updatedBooks;
    saveBooks();
}

vector<Book> BookManager::getAllBooks() const {
    return books;
}

Book* BookManager::searchBook(const string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title) {
            return &book;
        }
    }
    return nullptr;
}

std::vector<Book>& BookManager::getBooks() {
    return books;
}
