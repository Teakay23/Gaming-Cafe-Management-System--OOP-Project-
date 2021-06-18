#pragma once
#include"Manager.h"
class Regular_Staff:public Person
{
    Schedule Regular_Worker_Schedule;
    public:
    void view_all_monthly_regular_schedule();
    void delete_account(string,string);
    
};
