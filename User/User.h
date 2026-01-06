#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

enum Role
{
    Manager,
    Staff,
    Customer
};

class User
{

private:
    string userName;
    string passHash;
    bool blocked;
    Role role;

public:
    User(string userName, string password, bool blocked, string role);

    Role getRoleFromString(string role);
    string hash(string pass);
    bool checkPassword(string pass);
    void display();
    
    string getUserName();
    string getPassHash();
    bool isBlocked();
    Role getRole();
    string getRoleAsString();

    void setUserName(string uName);
    void setPassword(string password);
    void setBlocked(bool isBlocked);
    void setRole(string r);
};