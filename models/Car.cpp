#include "Car.h"
#include <iostream>

Car::Car(string brand, string model, string plate, double price)
: brand(brand), model(model), priceperday(price), status(Available) {}

bool Car::operator<(const Car& other) const {
    return (this->brand + this->model) < (other.brand + other.model);
}

bool Car::operator>(const Car& other) const {
    return (this->brand + this->model) > (other.brand + other.model);
}

bool Car::operator==(const Car& other) const {
    return this->id == other.id;
}

void Car::printDetails() const {
    cout << "Brand: " << brand << " | Model: " << model << " | Price/Dey: " << priceperday << " | Status: " << getstatus() << endl;
}

string Car::getstatus() const {
    switch (status) {
        case Available: return "Available"; // [cite: 15]
        case Reserved: return "Reserved"; // [cite: 15]
        case Rented: return "Rented"; // [cite: 15]
        case Maintenance: return "Maintenance"; // [cite: 24]
        default: return "Unknown";
    }
}
