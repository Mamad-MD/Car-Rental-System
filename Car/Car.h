#pragma once
#include <iostream>
using namespace std;

enum carStatus
{
    Available,
    Rented,
    Reserved,
    Maintenance
};

class Car
{
private:
    string carId;
    string brand;
    string model;
    int year;
    float pricePerDay;
    carStatus status;

public:
    Car(string carId, string brand, string model, int year, float pricePerDay, carStatus status);
    void display();
    bool isReservable();


    string getCarId();
    string getBrand();
    string getModel();
    int getYear();
    float getPricePerDay();
    carStatus getStatus();

    
    void setCarId(string id);
    void setBrand(string b);
    void setModel(string m);
    void setYear(int y);
    void setPricePerDay(float price);
    void setStatus(carStatus s);
};