#ifndef USERSYSTEM_H
#define USERSYSTEM_H

#include "BookManager.h"
#include "UserManager.h"
#include "LoanManager.h"

class UserSystem {
public:
    UserSystem(BookManager& bookManager, UserManager& userManager, LoanManager& loanManager);

    void showAllBooks();
    void addBook();
    void searchBook();
    void loanBook();
    void returnBook();
    void viewLoanHistory();
    void showAllUsers();

private:
    BookManager& bookManager;
    UserManager& userManager;
    LoanManager& loanManager;
};

#endif
