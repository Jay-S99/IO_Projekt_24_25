#include <iostream>
#include <string>
#include <cstdlib>
#include "BookManager.h"
#include "UserManager.h"
#include "LoanManager.h"
#include "UserSystem.h"
#include <windows.h>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    SetConsoleOutputCP(65001); // Ustawienie konsoli na UTF-8

    BookManager bookManager;
    UserManager userManager;
    LoanManager loanManager;
    UserSystem userSystem(bookManager, userManager, loanManager);

    bookManager.loadBooks();
    userManager.loadUsers();

    int choice;
    do {
        clearScreen();
        cout << "Wybierz dzialanie:" << endl;
        cout << "1. Wyswietl wszystkie ksiazki" << endl;
        cout << "2. Dodaj ksiazke" << endl;
        cout << "3. Wyszukaj ksiazke" << endl;
        cout << "4. Wypozycz ksiazke" << endl;
        cout << "5. Zwroc ksiazke" << endl;
        cout << "6. Historia wypozyczen" << endl;
        cout << "7. Wyswietl liste uzytkownikow" << endl;
        cout << "8. Wyjdz" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            userSystem.showAllBooks();
            break;
        case 2:
            userSystem.addBook();
            break;
        case 3:
            userSystem.searchBook();
            break;
        case 4:
            userSystem.loanBook();
            break;
        case 5:
            userSystem.returnBook();
            break;
        case 6:
            userSystem.viewLoanHistory();
            break;
        case 7:
            userSystem.showAllUsers();
            break;
        case 8:
            cout << "Zamykanie aplikacji." << endl;
            break;
        default:
            cout << "Niepoprawny wybor." << endl;
        }
        cout << endl << "Nacisnij dowolny klawisz, aby kontynuowac..." << endl;
        cin.ignore();
        cin.get();
    } while (choice != 8);

    return 0;
}
