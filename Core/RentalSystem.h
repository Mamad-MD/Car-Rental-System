// core/RentalSystem.h
#include "../structures/linklist.h"
#include "../structures/AVLTree.h"
#include "../structures/HashTable.h"
#include "../structures/minheap.h"
#include "../utils/HashHelper.h"
#include "../models/Car.h"
#include "../models/User.h"
#include "../models/Customer.h"
#include "Config.h"
#include <fstream>
#include <sstream>

class RentalSystem {
private:
    LinkList<Car> allCars;
    AVLTree<Car> carSearchIndex;
    Hashtable<string, User*> userTable;
    LinkList<User*> allUsers;

    User* currentUser;

public:
    RentalSystem();
    ~RentalSystem(); // برای آزادسازی حافظه یوزرها

    void registerUser(string username, string password, UserRole role);
    bool login(string username, string password);

    void addCar(int id, string brand, string model, double price); // متد کمکی
    void displayAllCars();
    void searchCar(string brandModel);

    bool checkOverlap(Car* car, int start, int duration);
    void convertReservationToRental(string username, int carId);

    void saveData();
    void loadData();
    void exportRevenueReport();

    double calculateFine(int actualReturnDate, int expectedReturnDate);
    void toggleUserBlock(string username);
};
