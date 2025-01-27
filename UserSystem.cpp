#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "UserSystem.h"

using namespace std;

int main() {
    UserSystem system;

    system.addUser(1, "Jan", "Kowalski");
    system.addUser(2, "Anna", "Nowak");

    system.showUsers();

    User* user = system.login(1);
    if (user)
    {
        user->addToHistory("Pan Tadeusz");
        user->addToHistory("W pustyni i w puszczy");

        user->showHistory();
    }

    system.deleteUser(1);

    system.login(1);

    return 0;
}