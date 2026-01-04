#include <string>
#include <iostream>

using namespace std;

enum UserRole {
    Customer,
    Staff,
    Manager
};

class User {
protected:
    string username;
    string passwordHash;
    UserRole role;

public:
    User() : username(""), passwordHash(""), role(Customer) {}
    User(string user, string pass, UserRole role) : username(user), passwordHash(pass), role(role) {}


    string getusername() const {return username;}

    bool checkpass(string inputpass) const;

    virtual void showmenu() = 0;

    bool operator==(const User& other) const {
        return this->username == other.username;
    }
};
