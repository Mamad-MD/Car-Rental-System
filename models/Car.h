#include <string>

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

public:
    Car(string brand, string model, string plate, double price);

    string getbrand() const;
    string getmodel() const;
    string getplate() const;
    double getprice() const;
    string getstatus() const;

    void setstatus(CarStatus newStatus);

    void printDetails() const;
};
