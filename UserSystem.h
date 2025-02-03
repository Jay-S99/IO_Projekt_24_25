#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class UserSystem : User
{
private:
    unordered_map <int, User> users;

public:
    void addUser(int id, const string& name, const string& surname)
    {
        if (users.find(id) != users.end())
        {
            cout << "Uzytkownik o numerze:  " << id << " juz istnieje.\n";
        }
        else
        {
            users[id] = User(id, name, surname);
            cout << "Dodano uzytkownika: " << name << " " << surname << " (ID: " << id << ").\n";
        }
    }

    void deleteUser(int id)
    {
        if (users.erase(id))
        {
            cout << "Uzytkownik o numerze: " << id << "zostal usuniety.\n";
        }
        else
        {
            cout << "Uzytkownik o numerze " << id << " nie istnieje.\n";
        }
    }

    User* login(int id) {
        auto it = users.find(id);
        if (it != users.end())
        {
            return &it->second;
        }
        else
        {
            cout << "Uzytkownik o numerze " << id << " nie istnieje.\n";
            return nullptr;
        }
    }

    void showUsers() const
    {
        if (users.empty())
        {
            cout << "Brak uzytkownikow w systemie.\n";
        }
        else {
            cout << "Lista uzytkownikow:\n";
            for (const auto& para : users)
            {
                const auto& user = para.second;
                cout << "ID: " << user.getID() << ", imie: " << user.getName()
                    << ", nazwisko: " << user.getSurname() << "\n";
            }
        }
    }
};
