#include"Tech_Staff.h"
void Tech_Staff::delete_account(string a, string b)
{
    Password P;
    int c=4;
    remove_all_personal_data(a,b,c);
    P.delete_ID(a,b,c);
    P.delete_password(a,b,c);
}
void Tech_Staff::view_feedback()
{
    clear;
    FeedbackSystem T;
    cout<<T;
    pause;
}
void Tech_Staff::view_all_monthly_technical_staff_schedule()
{
    int choice;
    Tech_Worker_Schedule.EXTRACT_SCHEDULE_FILE(4);
    monthselector:
    clear;
    cout<<"Select Month To View Schedule for:"<<endl;
    cout<<"1. January\n2. February\n3. March\n4. April\n5. May\n6. June\n7. July\n8. August\n9. September\n10. October\n11. November\n12. December\n13. Return"<<endl;
    cin>>choice;
    if(choice<1 || choice>13)
    goto monthselector;
    if(choice==13)
    return;
    else
    {
        Tech_Worker_Schedule=choice;
        cout<<Tech_Worker_Schedule;
        cout<<"\n0 INDICATES NO TASK, THEREFORE A HOLIDAY.\n";
        pause;
        goto monthselector;
    }
}
void Tech_Staff::View_Inventory_PCs()
{
    I=new CybernetComputer<string>;
    clear;
    I->displayer();
    pause;
}
void Tech_Staff::Allot_Inventory_PCs()
{
    clear;
    CybernetComputer<string>C1;
    C1.get_data();

}
void Tech_Staff::View_Inventory_Regular()
{
    clear;
    I=new RegularEquipment<string>;
    clear;
    I->displayer();
    pause;
}
void Tech_Staff::Allot_Inventory_Regular()
{
    RegularEquipment<string> R1;
    clear;
    R1.get_data();
}