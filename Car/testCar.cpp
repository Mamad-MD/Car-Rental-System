#include <iostream>
#include <cassert>
#include "Car.h"

using namespace std;

int main() {
    cout << "===== Car Class Test =====" << endl;

    Car car(
        "C101",
        "Toyota",
        "Corolla",
        2020,
        50.0,
        Available
    );

    // Test getters
    assert(car.getCarId() == "C101");
    assert(car.getBrand() == "Toyota");
    assert(car.getModel() == "Corolla");
    assert(car.getYear() == 2020);
    assert(car.getPricePerDay() == 50.0);
    assert(car.getStatus() == Available);

    cout << "Initial getters passed!" << endl;

    // Test reservable
    assert(car.isReservable() == true);
    cout << "Reservable check (Available) passed!" << endl;

    // Change status to Rented
    car.setStatus(Rented);
    assert(car.isReservable() == false);
    cout << "Reservable check (Rented) passed!" << endl;

    // Change status to Maintenance
    car.setStatus(Maintenance);
    assert(car.isReservable() == false);
    cout << "Reservable check (Maintenance) passed!" << endl;

    // Test setters
    car.setCarId("C202");
    car.setBrand("BMW");
    car.setModel("X5");
    car.setYear(2023);
    car.setPricePerDay(120.5);
    car.setStatus(Available);

    assert(car.getCarId() == "C202");
    assert(car.getBrand() == "BMW");
    assert(car.getModel() == "X5");
    assert(car.getYear() == 2023);
    assert(car.getPricePerDay() == 120.5);
    assert(car.getStatus() == Available);

    cout << "Setters passed!" << endl;

    // Display test (visual)
    cout << "\nDisplay car info:" << endl;
    car.display();

    cout << "\nAll Car tests passed successfully!" << endl;

    return 0;
}
