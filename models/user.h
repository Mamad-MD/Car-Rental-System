//models/user.h
#include <string>
#include <iostream>
#include "../utils/HashHelper.h"

using namespace std;

enum class UserRole {
    CUSTOMER = 0,
    STAFF = 1,
    MANAGER = 2
};

class User {
protected:
    string username;
    string passwordHash;
    UserRole role;

public:
    User() : username(""), passwordHash(""), role(UserRole::CUSTOMER) {}
    User(string user, string pass, UserRole r) : username(user), passwordHash(pass), role(r) {}
    virtual ~User() {}

    string getusername() const {return username;}
    string getPassword() const { return passwordHash; }
    bool checkPassword(string inputHash) const {
        return passwordHash == inputHash;
    }
    UserRole getRole() const { return role; }

    virtual void showMenu() = 0;

    bool operator==(const User& other) const {
        return this->username == other.username;
    }
};
