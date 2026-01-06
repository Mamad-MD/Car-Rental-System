#include "reservationPeriod.h"

ReservatiomPeriod::ReservatiomPeriod(date start, date end)
{
    startDate = start;
    endDate = end;
}


date ReservatiomPeriod::getStartDate()
{
    return startDate;
}

date ReservatiomPeriod::getEndDate()
{
    return endDate;
}


void ReservatiomPeriod::setStartDate(date d){
    startDate=d;
}
void ReservatiomPeriod::setEndDate(date d){
    endDate=d;
}



