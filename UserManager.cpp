#include "UserManager.h"
#include "User.h"
#include <iostream>
#include <fstream>

void UserManager::loadUsers() {
    std::ifstream file("users.txt");
    std::string name;

    if (!file.is_open()) {
        std::cout << "Blad otwierania pliku uzytkownikow!" << std::endl;
        return;
    }

    while (getline(file, name)) {
        if (!name.empty()) {
            users.push_back(User(name));
        }
    }

    file.close();
}

void UserManager::saveUsers() {
    std::ofstream file("users.txt");

    if (!file.is_open()) {
        std::cout << "Blad otwierania pliku do zapisu uzytkownikow!" << std::endl;
        return;
    }

    for (const auto& user : users) {
        file << user.getUsername() << std::endl;
    }

    file.close();
}

void UserManager::addUser(const User& user) {
    users.push_back(user);
    saveUsers();
}

void UserManager::showAllUsers() {
    if (users.empty()) {
        std::cout << "Brak uzytkownikow." << std::endl;
        return;
    }

    for (const auto& user : users) {
        std::cout << user.getUsername() << std::endl;
    }
}

User* UserManager::findUser(const std::string& username) {
    for (auto& user : users) {
        if (user.getUsername() == username) {
            return &user;
        }
    }
    return nullptr;
}
