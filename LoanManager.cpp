#include "LoanManager.h"

#include <fstream>
#include <sstream>

LoanManager::LoanManager(const string& file) : loanFilename(file) {
    loadFromFile();
}

LoanManager::~LoanManager() {
    saveToFile();
}

void LoanManager::loadFromFile() {
    ifstream inFile(loanFilename);
    if (!inFile.is_open()) return;

    int userId, bookId;
    while (inFile >> userId >> bookId) {
        loans[userId] = bookId;
    }
    inFile.close();
}

void LoanManager::saveToFile() const {
    ofstream outFile(loanFilename);
    if (!outFile.is_open()) return;

    for (const auto& loan : loans) {
        outFile << loan.first << " " << loan.second << "\n";
    }
    outFile.close();
}

void LoanManager::borrowBook(int userId, int bookId, BookManager& bookManager, UserManager& user) {
    if (loans.count(userId)) {
        cout << "User already has a borrowed book.\n";
        return;
    }

    bookManager.updateAvailability(bookId, false);
    loans[userId] = bookId;

    string bookTitle = to_string(bookId); // Zmodyfikuj zgodnie z nazw¹ ksi¹¿ki
    user.addToHistory(bookTitle);

    cout << "Book with ID " << bookId << " has been borrowed by user " << userId << ".\n";
}

void LoanManager::returnBook(int userId, int bookId, BookManager& bookManager, UserManager& user) {
    if (!loans.count(userId) || loans[userId] != bookId) {
        cout << "Invalid return. The user didn't borrow this book.\n";
        return;
    }

    bookManager.updateAvailability(bookId, true);
    loans.erase(userId);

    cout << "Book with ID " << bookId << " has been returned by user " << userId << ".\n";
}

void LoanManager::generateReport(const BookManager& bookManager, const UserManager& user) const {
    cout << "Library Activity Report:\n";
    for (const auto& loan : loans) {
        cout << "User ID: " << loan.first << " -> Book ID: " << loan.second << "\n";
    }
}