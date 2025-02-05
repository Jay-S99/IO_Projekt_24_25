#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
public:
    User(const std::string& username) : username(username) {}
    
    std::string getUsername() const { return username; }
    void addLoan(const std::string& bookTitle);
    void returnBook(const std::string& bookTitle);
    void showLoanHistory() const;
    
private:
    std::string username;
    std::vector<std::string> loanHistory;
};

#endif
