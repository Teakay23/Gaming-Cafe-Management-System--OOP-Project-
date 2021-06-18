#pragma once
#include "Time.h"
#include <ctime>
#include <stdlib.h>
#include "TicketingSystem.h"
#include "oneTimeTicket.h"
#include "recurringTicket.h"
#include "TicketManagement.h"
#include "Manager.h"


class Accountant:public Person
{
    TicketManagement TM;
    public:
    void view_personal_details(string,string,int);
    void cancelTicket();
    void checkAllBookings();
    void checkDayBookings();
    void checkMonthBookings();
    void viewTicketInfo();
    void withdrawAllCash();
    void checkWithdrawHistory();
    void delete_account(string, string);
};
