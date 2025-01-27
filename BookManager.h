#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Struktura ksiazki
struct Book {
    int id;
    string title;
    string author;
    bool isAvailable;

    // Konstruktor domyślny
    Book() : id(0), title(""), author(""), isAvailable(true) {}

    // Konstruktor z argumentami
    Book(int bookID, const string& bookTitle, const string& bookAuthor, bool availability = true)
        : id(bookID), title(bookTitle), author(bookAuthor), isAvailable(availability) {}

    // Tworzenie książki z tekstu
    static Book fromString(const string& line);

    // Konwersja książki na tekst do zapisu
    string toString() const;
};

class BookManager
{
private:
    //lista
    vector<Book> books;
    //przypis. ID do ksiazki
    int nextBookID;
    //Plik z knigami
    const string filename; 
    //Wczyt.
    void loadFromFile();
    //Zapis
    void saveToFile() const;
public:
    //konst
    BookManager(const string& file);
    //DEST
    ~BookManager();
    //Usuwanie
    void removeBook(int id);
    //Wyszukiwanie
    void searchBook(const string& keyword) const;
    //Wyświetlanie
    void displayBooks() const;
    //Zmiana dostenosci
    void updateAvailability(int id, bool availability);
};
