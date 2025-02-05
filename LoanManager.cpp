#include "LoanManager.h"
#include "BookManager.h"
#include <fstream>
#include <iostream>
#include <string>

LoanManager::LoanManager() {
    bookManager = BookManager();
}

LoanManager::LoanManager(BookManager& bm) : bookManager(bm) {}

void LoanManager::loanBook(const Book& book, const std::string& username) {
    std::ofstream loanFile("loanbook.txt", std::ios::app);
    if (!loanFile.is_open()) {
        std::cout << "Blad otwierania pliku loanbook.txt!" << std::endl;
        return;
    }

    loanFile << book.getTitle() << "\n" << book.getAuthor() << "\n" << username << "\n";
    loanFile.close();
    std::cout << "Ksiazka wypozyczona!" << std::endl;

    std::ifstream booksFile("books.txt");
    if (!booksFile.is_open()) {
        std::cout << "Blad otwierania pliku books.txt!" << std::endl;
        return;
    }

    std::vector<Book> books;
    std::string title, author;

    while (std::getline(booksFile, title) && std::getline(booksFile, author)) {
        if (title != book.getTitle() || author != book.getAuthor()) {
            books.emplace_back(title, author);
        }
    }
    booksFile.close();

    std::ofstream newBooksFile("books.txt", std::ios::trunc);
    if (!newBooksFile.is_open()) {
        std::cout << "Blad otwierania pliku books.txt do zapisu!" << std::endl;
        return;
    }

    for (const auto& b : books) {
        newBooksFile << b.getTitle() << "\n" << b.getAuthor() << "\n";
    }

    newBooksFile.close();

    bookManager.loadBooks();
}


void LoanManager::returnBook(const Book& book, const std::string& username) {
    std::ifstream loanFile("loanbook.txt");
    std::ofstream tempFile("temp_loanbook.txt");

    if (!loanFile.is_open()) {
        std::cout << "Blad otwierania pliku loanbook.txt!" << std::endl;
        return;
    }

    if (!tempFile.is_open()) {
        std::cout << "Blad tworzenia pliku tymczasowego temp_loanbook.txt!" << std::endl;
        return;
    }

    std::string title, author, user;
    bool found = false;

    while (std::getline(loanFile, title)) {
        std::getline(loanFile, author);
        std::getline(loanFile, user);

        if (title == book.getTitle() && author == book.getAuthor() && user == username) {
            found = true;
        }
        else {
            tempFile << title << "\n" << author << "\n" << user << "\n";
        }
    }

    loanFile.close();
    tempFile.close();

    if (!found) {
        std::cout << "Nie znaleziono ksiazki w pliku loanbook.txt!" << std::endl;
        return;
    }

    if (remove("loanbook.txt") != 0) {
        std::cout << "Blad podczas usuwania pliku loanbook.txt!" << std::endl;
        return;
    }

    if (rename("temp_loanbook.txt", "loanbook.txt") != 0) {
        std::cout << "Blad podczas zmiany nazwy pliku temp_loanbook.txt!" << std::endl;
        return;
    }

    // Teraz dodajemy książkę do pliku books.txt
    std::ofstream booksFile("books.txt", std::ios::app);
    if (!booksFile.is_open()) {
        std::cout << "Blad otwierania pliku books.txt!" << std::endl;
        return;
    }

    booksFile << book.getTitle() << "\n" << book.getAuthor() << "\n";
    booksFile.close();

    std::cout << "Ksiazka zwrocona!" << std::endl;
}
