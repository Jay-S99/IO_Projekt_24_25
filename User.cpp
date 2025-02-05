#include "User.h"
#include <iostream>

void User::addLoan(const std::string& bookTitle) {
    loanHistory.push_back(bookTitle);
}

void User::returnBook(const std::string& bookTitle) {
    loanHistory.erase(std::remove(loanHistory.begin(), loanHistory.end(), bookTitle), loanHistory.end());
}

void User::showLoanHistory() const {
    std::cout << "Historia wypozyczen dla uzytkownika " << username << ":" << std::endl;
    for (const auto& book : loanHistory) {
        std::cout << book << std::endl;
    }
}
