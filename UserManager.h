#include <vector>
#include <string>
#include "User.h"

class UserManager {
public:
    void loadUsers();
    void saveUsers();
    void addUser(const User& user);
    User* findUser(const std::string& username);
    void showAllUsers();
    
private:
    std::vector<User> users;
};
