#include "User.h"
User::User(string userName, string password, bool blocked, string role)
{
    this->userName = userName;
    this->passHash = hash(password);
    this->blocked = blocked;
    this->role = getRoleFromString(role);
}

Role User::getRoleFromString(string role)
{
    transform(role.begin(), role.end(), role.begin(), ::tolower);
    try
    {
        if (role == "manager")
            return Manager;
        else if (role == "staff")
            return Staff;
        else if (role == "customer")
            return Customer;
        else
            throw "role isnt defined!";
    }
    catch (string msg)
    {
        cout << msg << endl;
    }
}

string User::hash(string pass)
{
    string hashPass;
    for (char c : pass)
    {
        hashPass += char((c * 33 + 1) % 128);
    }
    return hashPass;
}

bool User::checkPassword(string pass)
{
    return this->passHash == hash(pass);
}

void User::display()
{
    cout << "User_name:   " << userName << endl;
    cout << "Role:    " << getRoleAsString() << endl;
    cout << "Access Status:   ";
    if (this->blocked)
        cout << "Block " << endl;
    else
        cout << "Allow " << endl;
}

string User::getUserName() { return userName; }
string User::getPassHash() { return passHash; }
bool User::isBlocked() { return blocked; }
Role User::getRole() { return role; }

string User::getRoleAsString()
{
    try
    {
        switch (role)
        {
        case Customer:
            return "Customer";
        case Staff:
            return "Staff";
        case Manager:
            return "Manager";
        default:
            throw "role unsupported";
        }
    }
    catch (string msg)
    {
        cout << msg << endl;
    }
}

void User::setUserName(string uName) { userName = uName; }
void User::setPassword(string password) { passHash = hash(password); }
void User::setBlocked(bool isBlocked) { blocked = isBlocked; }
void User::setRole(string r) { role = getRoleFromString(r); }