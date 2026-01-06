#include <iostream>
#include <cassert>
#include "User.h"
using namespace std;

int main() {
    cout << "===== User Class Test =====" << endl;

    // 1️⃣ تست سازنده
    User u1("Ali", "1234", false, "Customer");

    // 2️⃣ تست گترها
    assert(u1.getUserName() == "Ali");
    assert(u1.getRole() == Customer);
    assert(u1.isBlocked() == false);
    cout << "Initial getters passed!" << endl;

    // 3️⃣ تست checkPassword
    assert(u1.checkPassword("1234") == true);
    assert(u1.checkPassword("wrong") == false);
    cout << "Password check passed!" << endl;

    // 4️⃣ تست display
    cout << "Display user info:" << endl;
    u1.display();

    // 5️⃣ تست ستترها
    u1.setUserName("Reza");
    u1.setPassword("5678");
    u1.setBlocked(true);
    u1.setRole("Manager");

    assert(u1.getUserName() == "Reza");
    assert(u1.getRole() == Manager);
    assert(u1.isBlocked() == true);
    assert(u1.checkPassword("5678") == true);

    cout << "\nAfter setters:" << endl;
    u1.display();

    cout << "\nAll tests passed successfully!" << endl;

    return 0;
}
