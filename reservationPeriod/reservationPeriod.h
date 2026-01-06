#pragma once
#include <iostream>
using namespace std;

typedef struct Date
{
    int year;
    int month;
    int day;
} date;

class ReservatiomPeriod
{
private:
    date startDate;
    date endDate;

public:
    ReservatiomPeriod(date start, date end);

    date getStartDate();
    date getEndDate();

    void setStartDate(date d);
    void setEndDate(date d);

    void display();
    static bool hadInterferenceTime(date d1, date d2);
    date reserveTime();
}