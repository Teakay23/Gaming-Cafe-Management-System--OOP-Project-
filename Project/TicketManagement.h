#pragma once
#include<iostream>
#include "TicketingSystem.h"
#include "Seat.h"

Time getCurrentTime();

class TicketManagement: public TicketingSystem
{
    public:

    void cancelTicket();
    void checkAllBookings();
    void checkDayBookings();
    void checkMonthBookings();
    static void withdrawAllCash(); // call before exiting program
    void checkWithdrawHistory();
    void showMenu();
};

