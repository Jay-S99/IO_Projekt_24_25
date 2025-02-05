#include "BookManager.h"
#include "Book.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype> 

void BookManager::loadBooks() {
    std::ifstream file("books.txt");
    std::string title, author;

    if (!file.is_open()) {
        std::cout << "Blad otwierania pliku ksiazek!" << std::endl;
        return;
    }

    books.clear();
    while (std::getline(file, title) && std::getline(file, author)) {
        if (!title.empty() && !author.empty()) {
            books.push_back(Book(title, author));
        }
    }

    file.close();
}

void BookManager::saveBooks() {
    std::ofstream file("books.txt");

    if (!file.is_open()) {
        std::cout << "Blad otwierania pliku do zapisu!" << std::endl;
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

void BookManager::removeBook(const std::string& title) {
    std::vector<Book> updatedBooks;

    for (const auto& book : books) {
        if (book.getTitle() != title) {
            updatedBooks.push_back(book);
        }
    }

    books = updatedBooks;
    saveBooks();
}

std::vector<Book> BookManager::getAllBooks() const {
    return books;
}

Book* BookManager::searchBook(const std::string& title) {
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
