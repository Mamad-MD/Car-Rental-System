// core/RentalSystem.h
#include "../structures/linklist.h"
#include "../structures/AVLTree.h"
#include "../structures/HashTable.h"
#include "../models/Car.h"
#include "../models/User.h"
#include <fstream>
#include <sstream>

class RentalSystem {
private:
    LinkList<Car> allCars;
    AVLTree<Car> carSearchIndex;
    Hashtable<string, User*> userTable;

    User* currentUser;

public:
    RentalSystem() : currentUser(nullptr) {}

    void registerUser(string username, string password, UserRole role) {
    }

    bool login(string username, string password) {
    }
};
bool RentalSystem::login(string username, string password) {
    string hashed = HashHelper::hashPassword(password);
    User** userPtr = userTable.search(username);

    if (userPtr != nullptr && (*userPtr)->checkPassword(hashed)) {
        currentUser = *userPtr;
        return true;
    }
    return false;
}
void RentalSystem::searchCar(string brandModel) {
    Car tempCar(0, brandModel, "", 0);
    Car* found = carSearchIndex.search(tempCar);

    if (found) {
        found->printDetails();
    } else {
        cout << "Car not found!" << endl;
    }
}
void RentalSystem::searchCar(string brandModel) {
    Car tempCar(0, brandModel, "", 0);
    Car* found = carSearchIndex.search(tempCar);

    if (found) {
        found->printDetails();
    } else {
        cout << "Car not found!" << endl;
    }
}

bool RentalSystem::checkOverlap(Car* car, int start, int duration) {
    // در اینجا باید لیست رزروهای فعلی خودرو بررسی شود
    // اگر بازه [start, start+duration] با رزرو دیگری تداخل داشت:
    // return true;
    return false;
}

void RentalSystem::convertReservationToRental(string username, int carId) {
    // ۱. پیدا کردن خودرو از لیست [cite: 42]
    // ۲. چک کردن اینکه آیا نفر اول صف رزرو همین کاربر است؟ [cite: 25]
    // ۳. تغییر وضعیت خودرو به Rented
    // ۴. ثبت تاریخ تحویل برای محاسبه جریمه در آینده [cite: 23]
}

void RentalSystem::saveData() {
    // ۱. ذخیره خودروها
    ofstream carFile("cars.txt");
    allCars.traverse([&carFile](const Car& c) {
        carFile << c.getId() << "," << c.getBrand() << "," << c.getModel()
                << "," << c.getPrice() << "," << (int)c.getStatus() << "\n";
    });
    carFile.close();

    // ۲. ذخیره کاربران
    ofstream userFile("users.txt");
    // فرض بر این است که یک لیست از تمام یوزرها داریم
    allUsers.traverse([&userFile](User* u) {
        userFile << u->getUsername() << "," << u->getPassword() << "," << (int)u->getRole() << "\n";
    });
    userFile.close();
}

void RentalSystem::loadData() {
    ifstream carFile("cars.txt");
    string line;
    while (getline(carFile, line)) {
        // جدا کردن مقادیر با استفاده از stringstream و ","
        // ساختن شیء Car و افزودن به allCars و carSearchIndex
    }
}
void RentalSystem::exportRevenueReport() {
    ofstream report("revenue_report.csv");
    report << "Date,User,CarID,Amount,Type\n"; // Header

    // در اینجا باید لیست تراکنش‌ها (که قبلاً در یک لیست ذخیره کردید) را بنویسید
    // مثال:
    // report << "2023-10-27,ali_80,102,500000,Rental\n";

    report.close();
    cout << "Report exported successfully to revenue_report.csv" << endl;
}
// در core/RentalSystem.cpp
double RentalSystem::calculateFine(int actualReturnDate, int expectedReturnDate) {
    if (actualReturnDate <= expectedReturnDate) return 0;

    int delayDays = actualReturnDate - expectedReturnDate;
    return delayDays * Config::DAILY_FINE_RATE;
}
void RentalSystem::toggleUserBlock(string username) {
    User** uPtr = userTable.search(username);
    if (uPtr) {
        // اگر کاربر از نوع Customer بود، فیلد isBlocked را تغییر بده
        Customer* customer = dynamic_cast<Customer*>(*uPtr);
        if (customer) {
            customer->setBlockStatus(!customer->getBlockStatus());
            cout << "User status updated." << endl;
        }
    }
}
