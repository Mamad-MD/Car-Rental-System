//models/customer.h
#include "User.h"

class Customer : public User {
private:
    double balance;
    bool isBlocked;

public:
Customer(std::string user, std::string pass)
        : User(user, pass, UserRole::CUSTOMER), balance(0), isBlocked(false) {}

    bool getBlockStatus() const { return isBlocked; }
    void setBlockStatus(bool status) { isBlocked = status; }

  void showMenu() override {
        std::cout << "\n--- Customer Menu ---" << std::endl;
        std::cout << "1. Search Cars" << std::endl;
        std::cout << "2. Create Reservation" << std::endl;
        std::cout << "3. View My Rentals" << std::endl;
        std::cout << "4. Extend Rental" << std::endl;
        std::cout << "5. Pay Fine" << std::endl;
        std::cout << "0. Logout" << std::endl;
    }
};
