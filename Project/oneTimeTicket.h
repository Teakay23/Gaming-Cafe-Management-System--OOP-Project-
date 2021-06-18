#pragma once
#include "TicketMachine.h"

class oneTimeTicket: public TicketMachine
{
    public:

    void bookTicket();
    void cancelTicket();
    void showMenu(); // will add later
};