#include"Accountant.h"
void Accountant::delete_account(string a, string b)
{
    Password P;
    int c=1;
    remove_all_personal_data(a,b,c);
    P.delete_ID(a,b,c);
    P.delete_password(a,b,c);
}
void Accountant::view_personal_details(string a, string b, int c)
{
    Get_Info(a,b,c);
}

void Accountant::cancelTicket()
{
    clear;
    checkAllBookings();
    TM.cancelTicket();
}
void Accountant::checkAllBookings()
{
    clear;
    TM.checkAllBookings();
}
void Accountant::checkDayBookings()
{
    TM.checkDayBookings();
}
void Accountant::checkMonthBookings()
{
    TM.checkMonthBookings();
}
void Accountant::viewTicketInfo()
{
    TM.viewTicketInfo();
}
void Accountant::withdrawAllCash()
{
    TM.withdrawAllCash();
}
void Accountant::checkWithdrawHistory()
{
    TM.checkWithdrawHistory();
}