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
            cout << "User with ID:  " << id << " already exist.\n";
        }
        else
        {
            users[id] = users(id, name, surname);
            cout << "Added user: " << name << " " << surname << " (ID: " << id << ").\n";
        }
    }

    void deleteUser(int id)
    {
        if (users.erase(id))
        {
            cout << "User with ID: " << id << "has been deleted.\n";
        }
        else
        {
            cout << "User with ID " << id << " doesn't exist.\n";
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
            cout << "User with ID " << id << " doesn't exist.\n";
            return nullptr;
        }
    }

    void showUsers() const
    {
        if (users.empty())
        {
            cout << "No users in the system.\n";
        }
        else {
            cout << "User list:\n";
            for (const auto& para : users)
            {
                const auto& user = para.second;
                cout << "ID: " << user.getId() << ", name: " << name.getImie()
                    << ", surname: " << user.getNazwisko() << "\n";
            }
        }
    }
};
