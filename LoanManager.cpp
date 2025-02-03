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
        cout << "Uzytkownik juz wypozyczyl ksiazke.\n";
        return;
    }

    bookManager.updateAvailability(bookId, false);
    loans[userId] = bookId;

    string bookTitle = to_string(bookId);
    user.addToHistory(bookTitle);

    cout << "Ksiazka o numerze " << bookId << " zostala wypozyczona przez uzytkonika o numerze " << userId << ".\n";
}

void LoanManager::returnBook(int userId, int bookId, BookManager& bookManager, UserManager& user) {
    if (!loans.count(userId) || loans[userId] != bookId) {
        cout << "Ten uzytkownik nie wypozyczyl tej ksiazki.\n";
        return;
    }

    bookManager.updateAvailability(bookId, true);
    loans.erase(userId);

    cout << "Ksiazka o numerze " << bookId << " zostala zwrocona przez uzytkownika o numerze " << userId << ".\n";
}

void LoanManager::generateReport(const BookManager& bookManager, const UserManager& user) const {
    cout << "Aktywnosc biblioteki:\n";
    for (const auto& loan : loans) {
        cout << "Numer uzytkownika: " << loan.first << " -> numer ksiazki: " << loan.second << "\n";
    }
}
