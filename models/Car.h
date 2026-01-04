#include <string>
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
    string brand;
    string model;
    string plate;
    double priceperday;
    CarStatus status;
    MinHeap<Reservation> reservationQueue;

public:
    Car(string brand, string model, string plate, double price);

    string getbrand() const;
    string getmodel() const;
    string getplate() const;
    double getprice() const;
    string getstatus() const;

    void setstatus(CarStatus newStatus);

    void printDetails() const;

    void addReservation(Reservation res) {
        // ۱. ابتدا باید تداخل زمانی چک شود (Double-booking)
        // ۲. اگر تداخلی نبود، رزرو اضافه شود
        reservationQueue.push(res);
        this->setStatus(RESERVED); [cite: 22]
    }

    Reservation processNextReservation() {
        if (!reservationQueue.isEmpty()) {
            return reservationQueue.pop(); // تخصیص به نفر اول صف [cite: 25]
        }
        // بازگرداندن یک رزرو خالی در صورت نبود رزرو
        return {};
    }
};
