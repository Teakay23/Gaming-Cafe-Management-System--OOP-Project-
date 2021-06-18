#include"RegularStaff.h"
void Regular_Staff::view_all_monthly_regular_schedule()
{
    int choice;
    Regular_Worker_Schedule.EXTRACT_SCHEDULE_FILE(5);
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
        Regular_Worker_Schedule=choice;
        cout<<Regular_Worker_Schedule;
        cout<<"\n0 INDICATES NO TASK, THEREFORE A HOLIDAY.\n";
        pause;
        goto monthselector;
    }
}
void Regular_Staff::delete_account(string a, string b)
{
    Password P;
    int c=5;
    remove_all_personal_data(a,b,c);
    P.delete_ID(a,b,c);
    P.delete_password(a,b,c);
}
