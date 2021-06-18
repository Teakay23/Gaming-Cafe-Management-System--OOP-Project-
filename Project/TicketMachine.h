#pragma once
#include<iostream>
#include "TicketingSystem.h"

Time getCurrentTime();

class TicketMachine: public TicketingSystem // abstract class
{
    protected:
    int seatNo, bookingNo;
    Time start, end;

    void enterTiming(); // protected function (NEEDS EXCEPTION HANDLING IN TWO PLACES)
    void enterSeatInfo(); // protected function (NEEDS EXCEPTION HANDLING)
    
    public:

    virtual void bookTicket() = 0; // pure virtual function, used in oneTimeTicket and recurringTicket
    void checkPricing();
    void viewTicketInfo();
};

