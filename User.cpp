#include "User.h"
#include <iostream>

using namespace std;

void User::addLoan(const string& bookTitle) {
    loanHistory.push_back(bookTitle);
}

void User::returnBook(const string& bookTitle) {
    loanHistory.erase(remove(loanHistory.begin(), loanHistory.end(), bookTitle), loanHistory.end());
}

void User::showLoanHistory() const {
    cout << "Historia wypozyczen dla uzytkownika " << username << ":" << endl;
    for (const auto& book : loanHistory) {
        cout << book << endl;
    }
}
