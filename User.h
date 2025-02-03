#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "BookManager.h"

using namespace std;


class User: Book
{
private:
    int id;
    string name;
    string surname;
    vector<string> LoanHistory;

public:

    User() : id(0), name(""), surname("") {}

    User(int id, const string& name, const string& surname)
        : id(id), name(name), surname(surname) {}

    int getID() const { return id; }
    string getName() const { return name; }
    string getSurname() const { return surname; }

    void addToHistory(const string& book) {
        LoanHistory.push_back(book);
    }

    void showHistory() const {
        cout << "Historia wypozyczen dla " << name << " " << surname << " (ID: " << id << "):\n";
        if (LoanHistory.empty())
            cout << "Historia wypozyczen pusta.\n";
        else {
            for (const auto& book : LoanHistory) {
                cout << "- " << book << "\n";
            }
        }
    }
};
