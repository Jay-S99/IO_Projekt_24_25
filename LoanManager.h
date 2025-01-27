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
    unordered_map<int, int> loans; // mapa: klucz (id u¿ytkownika) -> id ksi¹¿ki
    const string loanFilename;    // plik do zapisywania wypo¿yczeñ

    // Wczytywanie danych z pliku
    void loadFromFile();
    // Zapisywanie danych do pliku
    void saveToFile() const;

public:
    LoanManager(const string& file);
    ~LoanManager();

    // Wypo¿yczenie ksi¹¿ki
    void borrowBook(int userId, int bookId, BookManager& bookManager, UserManager& user);
    // Zwrot ksi¹¿ki
    void returnBook(int userId, int bookId, BookManager& bookManager, UserManager& user);
    // Generowanie raportu
    void generateReport(const BookManager& bookManager, const UserManager& user) const;
};
