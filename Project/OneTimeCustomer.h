#pragma once
#include "Time.h"
#include <ctime>
#include <stdlib.h>
#include "TicketingSystem.h"
#include "oneTimeTicket.h"
#include "recurringTicket.h"
#include "TicketManagement.h"
#include "Manager.h"

class OneTimeCustomer:public Person
{
    public:
    oneTimeTicket OT;
    void checkPricing();
    void viewTicketInfo();
    void bookTicket();
    void cancelTicket();
};
