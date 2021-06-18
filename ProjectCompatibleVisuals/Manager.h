#pragma once
#include"Password.h"
#include"ScheduleWorker.h"
#include"Complex_ID.h"
#include"Visuals.h"
#include"Person.h"
#include"Foodmenu.h"
#include <conio.h>

class Manager:public Person
{
    Visuals V;
    food f;
    Schedule Technical_Worker_Schedule;
    Schedule Regular_Worker_Schedule;
    public:
    void show_manager_details(string,string,int);
    void show_all_worker_IDs();
    void set_regular_worker_schedule();
    void view_all_monthly_regular_schedule();
    void set_technical_worker_schedule();
    void view_all_monthly_technical_schedule();
    void set_food_menu();
    void view_food_menu();
    void delete_account(string a, string b);
    Manager();
};
