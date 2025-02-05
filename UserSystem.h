#include "BookManager.h"
#include "UserManager.h"
#include "LoanManager.h"

using namespace std;

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
