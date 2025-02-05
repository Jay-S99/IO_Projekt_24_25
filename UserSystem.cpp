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
    vector<Book> books = bookManager.getAllBooks();

    if (books.empty()) {
        cout << "Brak ksiazek w bibliotece." << std::endl;
        return;
    }

    for (const auto& book : books) {
        cout << book.getTitle() << " napisana przez " << book.getAuthor() << endl;
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
    cin.ignore();
    getline(cin, title);
    Book* book = bookManager.searchBook(title);
    if (book) {
        cout << "Znaleziono: " << book->getTitle() << " napisana przez " << book->getAuthor() << endl;
    }
    else {
        cout << "Ksiazka nie znaleziona." << endl;
    }
}

void UserSystem::loanBook() {
    string title, author, username;

    cout << "Podaj tytul ksiazki do wypozyczenia: ";
    cin.ignore();
    getline(cin, title);

    cout << "Podaj autora ksiazki do wypozyczenia: ";
    getline(cin, author);

    cout << "Podaj imie i nazwisko uzytkownika: ";
    getline(cin, username);

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
        cout << "Nie znaleziono ksiazki do wypozyczenia!" << endl;
    }
}

void UserSystem::returnBook() {
    string title, author;
    cout << "Podaj tytul ksiazki do zwrotu: ";
    cin.ignore();
    getline(cin, title);

    cout << "Podaj autora ksiazki do zwrotu: ";
    getline(cin, author);

    string username;
    cout << "Podaj imie i nazwisko uzytkownika: ";
    getline(cin, username);

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
        cout << "Nie znaleziono ksiazki do zwrotu!" << std::endl;
    }
}

void UserSystem::viewLoanHistory() {
    string username;
    cout << "Podaj imie i nazwisko uzytkownika, aby zobaczyc historie wypozyczen: ";
    cin.ignore();
    getline(cin, username);

    ifstream loanFile("loanbook.txt");

    if (!loanFile.is_open()) {
        cout << "Blad otwierania pliku loanbook.txt!" << endl;
        return;
    }

    string title, author, user;
    bool found = false;

    cout << "\nHistoria wypozyczen dla uzytkownika: " << username << endl;

    while (getline(loanFile, title)) {
        if (getline(loanFile, author) && getline(loanFile, user)) {
            if (user == username) {
                cout << "Tytul: " << title << endl;
                cout << "Autor: " << author << endl;
                found = true;
            }
        }
    }

    loanFile.close();

    if (!found) {
        cout << "Brak historii wypozyczen dla tego uzytkownika!" << endl;
    }
}
