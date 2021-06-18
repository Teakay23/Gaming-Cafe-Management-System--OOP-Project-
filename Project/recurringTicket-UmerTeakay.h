#pragma once
#include<string>
#include "TicketMachine.h"

struct bookHistory
{
    string ticketInfo;
    int seatNum, bookingNum;
    Time timeOfBooking;
};

class recurringTicket: public TicketMachine
{
    int pricePerHour, discountCounter, historyCount;
    bookHistory bookingHistory[100];
    string name;

    int additionalServices(); // private function
    bool discountChecker();
    void feedbackFile();

    public:

    recurringTicket(string);
    void bookTicket(); // book a random seat
    void bookSpecificSeat(); // book a specific seat
    void checkBookingHistory(); // past and future bookings
    void cancelTicket(); //(NEEDS EXCEPTION HANDLING) only customers with account can do this without emailing our cafe since
    void showMenu(); //will add later
};