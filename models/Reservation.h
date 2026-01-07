//models/reservation.h
#include <string>

struct Reservation {
    std::string username;
    int priority;
    int startDate;
    int duration;

Reservation() : username(""), priority(1000), startDate(0), duration(0) {}

    Reservation(std::string u, int p, int s, int d)
        : username(u), priority(p), startDate(s), duration(d) {}

    bool operator< (const Reservation& other) const {
        // در MinHeap هر چه کمتر باشد اولویت بالاتر است (یا برعکس بسته به منطق شما)
        // اینجا فرض می‌کنیم عدد کمتر = اولویت بالاتر (مثل صف نوبت دهی)
        return this->priority < other.priority;
    }
};
