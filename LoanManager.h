#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "BookManager.h"
#include "User.h"

using namespace std;

class LoanManager {
private:
    unordered_map<int, int> loans;
    const string loanFilename;

    void loadFromFile();
    void saveToFile() const;

public:
    LoanManager(const string& file);
    ~LoanManager();

    void borrowBook(int userId, int bookId, BookManager& bookManager, UserManager& user);
    void returnBook(int userId, int bookId, BookManager& bookManager, UserManager& user);
    void generateReport(const BookManager& bookManager, const UserManager& user) const;
};
