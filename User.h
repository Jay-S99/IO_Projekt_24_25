#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

class User {
public:
    User(const string& username) : username(username) {}

    string getUsername() const { return username; }
    void addLoan(const string& bookTitle);
    void returnBook(const string& bookTitle);
    void showLoanHistory() const;

private:
    string username;
    vector<string> loanHistory;
};

#endif
