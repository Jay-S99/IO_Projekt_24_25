#include "Book.h"
#include "BookManager.h"
#include <iostream>
#include <vector>

class LoanManager {
private:
    BookManager bookManager;

public:
    LoanManager();
    LoanManager(BookManager& bm);

    void loanBook(const Book& book, const std::string& username);
    void returnBook(const Book& book, const std::string& username);
};
