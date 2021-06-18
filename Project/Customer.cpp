#include"Customer.h"
void Customer::delete_account(string a, string b)
{
    Password P;
    int c=2;
    remove_all_personal_data(a,b,c);
    P.delete_ID(a,b,c);
    P.delete_password(a,b,c);
}
void Customer::chatmachine(string name)
{
    ChatMachine.getinfo(name);
}
void Customer::getfeedback(string a,string b)
{
    clear;
    FeedbackSystem t;
    t.getFeedback(a,b);
}
void Customer::saveAllSeatInfo()
{
    RT.saveAllSeatInfo();
}
void Customer::inputUsername(string a)
{
    RT.inputUsername(a);
}

Customer::Customer()
{
    RT.readAllSeatInfo();
}
void Customer::view_personal_details(string a, string b, int c)
{
    Get_Info(a,b,c);
}
void Customer::bookTicket()
{
    RT.bookTicket();
}
void Customer::checkBookingHistory()
{
    RT.checkBookingHistory();
}
void Customer::bookSpecificSeat()
{
    RT.bookSpecificSeat();
}
void Customer::cancelTicket()
{
    RT.cancelTicket();
}