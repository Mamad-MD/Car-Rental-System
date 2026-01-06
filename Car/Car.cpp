#include "Car.h"

// Constructor
Car::Car(string carId, string brand, string model, int year, float pricePerDay, carStatus status)
{
    this->carId = carId;
    this->brand = brand;
    this->model = model;
    this->year = year;
    this->pricePerDay = pricePerDay;
    this->status = status;
}

void Car::display()
{
    cout << "Car ID:        " << carId << endl;
    cout << "Brand:         " << brand << endl;
    cout << "Model:         " << model << endl;
    cout << "Year:          " << year << endl;
    cout << "Price / Day:   " << pricePerDay << endl;
    switch (status)
    {
    case Available:
        cout << "Available"<< endl;
        break;
    case Rented:
        cout << "Rented"<< endl;
        break;
    case Reserved:
        cout << "Reserved"<< endl;
        break;
    case Maintenance:
        cout << "Maintenance"<< endl;
        break;
    default:
        cout<<"status undefined !"<<endl;
    }
}

bool Car::isReservable(){
    return status==Available;
}

// Getters
string Car::getCarId()
{
    return carId;
}

string Car::getBrand()
{
    return brand;
}

string Car::getModel()
{
    return model;
}

int Car::getYear()
{
    return year;
}

float Car::getPricePerDay()
{
    return pricePerDay;
}

carStatus Car::getStatus()
{
    return status;
}


// Setters
void Car::setCarId(string id)
{
    carId = id;
}

void Car::setBrand(string b)
{
    brand = b;
}

void Car::setModel(string m)
{
    model = m;
}

void Car::setYear(int y)
{
    year = y;
}

void Car::setPricePerDay(float price)
{
    pricePerDay = price;
}

void Car::setStatus(carStatus s)
{
    status = s;
}