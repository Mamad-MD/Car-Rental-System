#include "Car.h"

Car::Car(int id, string brand, string model, string plate, double price)
    : id(id), brand(brand), model(model), plate(plate), pricePerDay(price), status(Available) {}

bool Car::operator<(const Car& other) const {
    // جستجو بر اساس ترکیب برند و مدل
    return (this->brand + this->model) < (other.brand + other.model);
}

bool Car::operator>(const Car& other) const {
    return (this->brand + this->model) > (other.brand + other.model);
}

bool Car::operator==(const Car& other) const {
    // برای جستجو در AVL شاید نیاز به تطابق نام باشد، اما برای حذف از لیست ID دقیق‌تر است
    if (this->id != 0 && other.id != 0) return this->id == other.id;
    return (this->brand + this->model) == (other.brand + other.model);
}

void Car::printDetails() const {
    cout << "ID: " << id << " | " << brand << " " << model
         << " | Price: " << pricePerDay << " | Status: " << getStatusString() << endl;
}

void Car::setStatus(CarStatus newStatus) {
    status = newStatus;
}

string Car::getStatusString() const {
    switch (status) {
        case Available: return "Available";
        case Reserved: return "Reserved";
        case Rented: return "Rented";
        case Maintenance: return "Maintenance";
        default: return "Unknown";
    }
}
