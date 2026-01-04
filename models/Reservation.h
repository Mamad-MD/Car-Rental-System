#include <string>

struct Reservation {
    std::string username;
    int priority;
    int startDate;
    int duration;

    bool operator< (const Reservation& other) const {
        return this->priority < other.priority;
    }
};
