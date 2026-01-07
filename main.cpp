//main.cpp
#include <iostream>
#include <string>
#include "core/RentalSystem.h"

using namespace std;

void showGuestMenu() {
    cout << "\n===== Welcome to Car Rental System =====" << endl;
    cout << "1. Register (New Customer)" << endl;
    cout << "2. Login" << endl;
    cout << "3. View Available Cars (Guest Mode)" << endl;
    cout << "4. Search for a Car" << endl;
    cout << "5. Add Sample Car (For Test)" << endl;
    cout << "0. Exit" << endl;
    cout << "Selection: ";
}

int main() {
    RentalSystem system;
    int choice;
    bool running = true;

    while (running) {
        showGuestMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string user, pass;
                cout << "Enter Username: "; cin >> user;
                cout << "Enter Password: "; cin >> pass;
                system.registerUser(user, pass, UserRole::CUSTOMER);
                break;
            }
            case 2: {
                string user, pass;
                cout << "Username: "; cin >> user;
                cout << "Password: "; cin >> pass;
                if (system.login(user, pass)) {
                    cout << "Login Successful!" << endl;
                    // اینجا می‌توانید متد showMenu یوزر لاگین شده را صدا بزنید
                } else {
                    cout << "Invalid credentials!" << endl;
                }
                break;
            }
            case 3:
                system.displayAllCars();
                break;
            case 4: {
                string query;
                cout << "Enter Brand or Model: "; cin >> query;
                system.searchCar(query);
                break;
            }
            case 5:
                system.addCar(101, "Toyota", "Camry", 500);
                system.addCar(102, "Honda", "Civic", 450);
                cout << "Sample cars added." << endl;
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Invalid Option!" << endl;
        }
    }

    return 0;
}
