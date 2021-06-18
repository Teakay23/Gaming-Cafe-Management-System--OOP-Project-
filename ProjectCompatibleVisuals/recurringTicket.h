#pragma once
#include<string>
#include "TicketMachine.h"
#include "ticketInfo.h"

class recurringTicket: public TicketMachine
{
    int pricePerHour, discountCounter;
    string username;

    int additionalServices(); // private function
    bool discountChecker();
    void feedbackFile(int seatNumber);

    public:

    recurringTicket();
    void inputUsername(string);
    void bookTicket(); // book a random seat
    void bookSpecificSeat(); // book a specific seat
    void checkBookingHistory(); // past and future bookings
    void cancelTicket(); //(NEEDS EXCEPTION HANDLING) only customers with account can do this without emailing our cafe since
    void showMenu(); //will add later
};