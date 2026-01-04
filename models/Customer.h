#include "User.h"

class Customer : public User {
private:
    double balance;
    bool isBlocked;

public:
    Customer(string user, string pass) : User(user, pass, Customer), balance(0), isBlocked(false) {}

    void showMenu() override {
        cout << "\n--- Customer Menu ---" << endl;
        cout << "1. Search Cars" << endl;
        cout << "2. Create Reservation" << endl;
        cout << "3. View My Rentals" << endl;
        cout << "4. Extend Rental" << endl;
        cout << "5. Pay Fine" << endl;
        cout << "0. Logout" << endl;
    }
};
