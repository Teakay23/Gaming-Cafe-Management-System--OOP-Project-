#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Time.h"
#include <ctime>
#include <stdlib.h>
#include "TicketingSystem.h"
#include "oneTimeTicket.h"
#include "recurringTicket.h"
#include "TicketManagement.h"


int main()
{
    recurringTicket RT;
    RT.bookTicket();
    RT.bookSpecificSeat();
    RT.checkBookingHistory();
    RT.cancelTicket();
    RT.checkBookingHistory();

    // oneTimeTicket OT;
    // OT.checkPricing();
    // OT.viewTicketInfo();
    // OT.bookTicket();
    // OT.cancelTicket();

    TicketManagement TM;
    TM.cancelTicket();
    TM.checkAllBookings();
    TM.checkDayBookings();
    TM.checkMonthBookings();
    TM.viewTicketInfo();
    TM.withdrawAllCash();
    TM.checkWithdrawHistory();
}

