#pragma once
#include "Time.h"
#include <ctime>
#include <stdlib.h>
#include "TicketingSystem.h"
#include "oneTimeTicket.h"
#include "recurringTicket.h"
#include "TicketManagement.h"
#include "Manager.h"
#include "FeedbackSystem.h"
#include "chatsystem.h"
class Customer:public Person
{
    recurringTicket RT;
    ChatSystem ChatMachine;
    public:
    void chatmachine(string);
    void view_personal_details(string,string,int);
    void bookTicket();
    void bookSpecificSeat();
    void cancelTicket();
    void checkBookingHistory();
    void inputUsername(string);
    void saveAllSeatInfo();
    void getfeedback(string, string);
    void delete_account(string, string);
    Customer();
};

   

  