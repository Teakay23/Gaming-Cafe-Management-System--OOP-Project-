#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include "Seat.h"

class TicketingSystem // base class
{
    protected:
    static const int numSeats = 25;
    static Seat seats[numSeats];
    int basePricePerHour;

    public:

    TicketingSystem();
    virtual void viewTicketInfo(); // virtual function, will be redefined in ticket machine, used in ticket managment (NEEDS EXCEPTION HANDLING)
    virtual void cancelTicket() = 0;
    void saveAllSeatInfo(); // call before exiting program
    void readAllSeatInfo(); // call at the start of program
};

