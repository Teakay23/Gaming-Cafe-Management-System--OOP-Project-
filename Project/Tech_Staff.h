#pragma once
#include"Manager.h"
#include "Impartial_Tech.h"
#include"RegularEquipment.h"
#include"CybernetComputer.h"
#include"FeedbackSystem.h"
class Tech_Staff:public Person
{
    Schedule Tech_Worker_Schedule;
    Impartial_Tech<string> *I;
    public:
    void view_all_monthly_technical_staff_schedule();
    void view_feedback();
    void View_Inventory_PCs();
    void Allot_Inventory_PCs();
    void View_Inventory_Regular();
    void Allot_Inventory_Regular();
    void delete_account(string, string);
};
