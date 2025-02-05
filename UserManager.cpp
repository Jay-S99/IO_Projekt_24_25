#include "UserSystem.h"
#include "LoanManager.h"
#include "BookManager.h"
#include "Book.h"
#include <iostream>
#include <fstream>

using namespace std;

UserSystem::UserSystem(BookManager& bookManager, UserManager& userManager, LoanManager& loanManager)
    : bookManager(bookManager), userManager(userManager), loanManager(loanManager) {}

void UserSystem::showAllBooks() {
    bookManager.loadBooks();
    std::vector<Book> books = bookManager.getAllBooks();

    if (books.empty()) {
        std::cout << "Brak ksiazek w bibliotece." << std::endl;
        return;
    }

    for (const auto& book : books) {
        std::cout << book.getTitle() << " napisana przez " << book.getAuthor() << std::endl;
    }
}

void UserSystem::showAllUsers() {
    userManager.showAllUsers();
}

void UserSystem::addBook() {
    string title, author;
    cout << "Podaj tytul ksiazki: ";
    cin.ignore();
    getline(cin, title);
    cout << "Podaj autora ksiazki: ";
    getline(cin, author);
    bookManager.addBook(Book(title, author));
}

void UserSystem::searchBook() {
    string title;
    cout << "Podaj tytul ksiazki do wyszukania: ";
    std::cin.ignore();
    getline(std::cin, title);
    Book* book = bookManager.searchBook(title);
    if (book) {
        std::cout << "Znaleziono: " << book->getTitle() << " napisana przez " << book->getAuthor() << std::endl;
    }
    else {
        std::cout << "Ksiazka nie znaleziona." << std::endl;
    }
}

void UserSystem::loanBook() {
    std::string title, author, username;

    std::cout << "Podaj tytul ksiazki do wypozyczenia: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Podaj autora ksiazki do wypozyczenia: ";
    std::getline(std::cin, author);

    std::cout << "Podaj swoje imie i nazwisko: ";
    std::getline(std::cin, username);

    LoanManager loanManager(bookManager);

    bool found = false;
    for (auto& book : bookManager.getBooks()) {
        if (book.getTitle() == title && book.getAuthor() == author) {
            loanManager.loanBook(book, username);
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Nie znaleziono ksiazki do wypozyczenia!" << std::endl;
    }
}

void UserSystem::returnBook() {
    std::string title, author;
    std::cout << "Podaj tytul ksiazki do zwrotu: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::cout << "Podaj autora ksiazki do zwrotu: ";
    std::getline(std::cin, author);

    std::string username;
    std::cout << "Podaj swoje imie i nazwisko: ";
    std::getline(std::cin, username);

    LoanManager loanManager(bookManager);

    bool found = false;
    for (auto& book : bookManager.getBooks()) {
        if (book.getTitle() == title && book.getAuthor() == author) {
            loanManager.returnBook(book, username);
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Nie znaleziono ksiazki do zwrotu!" << std::endl;
    }
}

void UserSystem::viewLoanHistory() {
    std::string username;
    std::cout << "Podaj swoje imie i nazwisko, aby zobaczyc historie wypozyczen: ";
    std::cin.ignore();
    std::getline(std::cin, username);

    std::ifstream loanFile("loanbook.txt");

    if (!loanFile.is_open()) {
        std::cout << "Blad otwierania pliku loanbook.txt!" << std::endl;
        return;
    }

    std::string title, author, user;
    bool found = false;

    std::cout << "\nHistoria wypozyczen dla uzytkownika: " << username << std::endl;

    while (getline(loanFile, title)) {
        if (getline(loanFile, author) && getline(loanFile, user)) {
            if (user == username) {
                std::cout << "Tytul: " << title << std::endl;
                std::cout << "Autor: " << author << std::endl;
                found = true;
            }
        }
    }

    loanFile.close();

    if (!found) {
        std::cout << "Brak historii wypozyczen dla tego uzytkownika!" << std::endl;
    }
}
