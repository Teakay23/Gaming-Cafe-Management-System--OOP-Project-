#include<iostream>
#include<iomanip>
#include "Time.h"

struct Booking // for multiple bookings per class
{
    Time startTime;
    Time endTime;
    int booked = 0; // 0 = FREE, 1 = BOOKED 
    int bookingNum;
    int amountPaid;
};
