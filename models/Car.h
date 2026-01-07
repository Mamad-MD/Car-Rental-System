//models/car.h
#include <string>
#include <iostream>
#include "../structures/MinHeap.h"
#include "Reservation.h"

using namespace std;

enum CarStatus  {
    Available,
    Reserved,
    Rented,
    Maintenance
};

class Car {
private:
    int id;
    string brand;
    string model;
    string plate;
    double pricePerDay;
    CarStatus status;
    MinHeap<Reservation> reservationQueue;

public:
    Car() : id(0), brand(""), model(""), plate(""), pricePerDay(0), status(Available) {}
    Car(int id, string brand, string model, string plate, double price);

    int getId() const { return id; }
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    double getPrice() const { return pricePerDay; }
    string getStatusString() const;
    CarStatus getStatus() const { return status; }

    void setStatus(CarStatus newStatus);

    void printDetails() const;

    void addReservation(Reservation res) {
        reservationQueue.push(res);
        this->setStatus(Reserved);
    }

    Reservation processNextReservation() {
        if (!reservationQueue.isEmpty()) {
            return reservationQueue.pop();
        }
        return Reservation();
    }

    // عملگرها برای استفاده در AVL و LinkList
    bool operator<(const Car& other) const;
    bool operator>(const Car& other) const;
    bool operator==(const Car& other) const;
};
