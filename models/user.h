#include <string>

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
    User(string user, string pass, UserRole role);

    string getusername() const;
    bool checkpass(string inputpass) const;

    virtual void showmenu() = 0;
};
