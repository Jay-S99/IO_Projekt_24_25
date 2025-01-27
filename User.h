#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class UserManager : Book //u¿ytkownik
{
private:
	int id;
	string name;
	string surname;
	vector<string> LoanHistory; //implementacja historii wypo¿yczeñ

public:
	UserManager(int id, const string& name, const string& surname) //konstruktor
		: id(id), name(name), surname(surname) {}

	int getID() const { return id; }
	string getName() const { return name; }
	string getSurname() const { return surname; } //odczytywanie wartosci

	void addToHistory(const string& book) { //dodawanie ksiazki do historii wypozyczen
		LoanHistory.push_back(book);
	}

	void showHistory() const {
		cout << "Loan history for " << name << " " << surname << " (ID: " << id << "):\n";
		if (LoanHistory.empty())
			cout << "Loan history is empty.\n";
		else {
			for (const auto% book : LoanHistory) {
				cout << "- " << book << "\n"
			}
		}
	}
};

