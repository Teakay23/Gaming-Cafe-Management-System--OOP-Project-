#include"Manager.h"
Manager::Manager()
{
    
}
void Manager::show_manager_details(string username, string password, int a)
{
    Get_Info(username,password,a);
}
void Manager::show_all_worker_IDs()
{
    clear;
    ID ID; 
    ID.EXTRACT_FROM_FILE();
    ID=1;
    cout<<ID;
    V.Complex_ID_border();
    ID=2;
    cout<<ID;
    V.Complex_ID_border();
    ID=3;
    cout<<ID;
    V.Complex_ID_border();
    ID=4;
    cout<<ID;
    V.Complex_ID_border();
    ID=5;
    cout<<ID;
    V.Complex_ID_border();
    pause;
}
void Manager::set_regular_worker_schedule()
{
    clear;
    int reg=0,random;
    ifstream file("ID.dat", ios::out);
    file.seekg(0);
    int temp=file.tellg();
    file.seekg(temp+sizeof(int)+sizeof(int)+sizeof(int)+sizeof(int));
    file.read((char*)(&reg), sizeof(reg));
    file.close();
    string regular[reg];     
    ifstream file2("Regular.dat", ios::out);
    for(int i=0;i<reg-1;i++)
    {
        getline(file2, regular[i], '\0');
        file2>>random;
    }
    Regular_Worker_Schedule.GetParticipaints(regular, reg-1);
    Regular_Worker_Schedule.INPUT_SCHEDULE_FILE(5);
}
void Manager::delete_account(string a, string b)
{
    Password P;
    int c=3;
    remove_all_personal_data(a,b,c);
    P.delete_ID(a,b,c);
    P.delete_password(a,b,c);
    
}
void Manager::set_technical_worker_schedule()
{
    clear;
    int tech=0,random;
    ifstream file("ID.dat", ios::out);
    file.seekg(0);
    int temp=file.tellg();
    file.seekg(temp+sizeof(int)+sizeof(int)+sizeof(int));
    file.read((char*)(&tech), sizeof(tech));
    file.close();
    string technical[tech];     
    ifstream file2("Tech.dat", ios::out);
    file2.seekg(0);
    for(int i=0;i<tech-1;i++)
    {
        getline(file2, technical[i], '\0');
        file2>>random;
    }
    Regular_Worker_Schedule.GetParticipaints(technical, tech-1);
    Regular_Worker_Schedule.INPUT_SCHEDULE_FILE(4);
}
void Manager::view_all_monthly_regular_schedule()
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
void Manager::view_all_monthly_technical_schedule()
{
    int choice;
    Technical_Worker_Schedule.EXTRACT_SCHEDULE_FILE(4);
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
        Technical_Worker_Schedule=choice;
        cout<<Technical_Worker_Schedule;
        cout<<"\n0 INDICATES NO TASK, THEREFORE A HOLIDAY.\n";
        pause;
        goto monthselector;
    }
 
}

void Manager::set_food_menu()
{
    clear;
    V.food_visual();
    pause;
    clear;
    cin>>f;
    f.Insert_In_file();
}
void Manager::view_food_menu()
{
    clear;
    f.Extract_from_file();
    cout<<f;
    nxt;
    V.food_after_visual();
    nxt;
    pause;
    char choice=' ';
    menucustom:
    cout<<"Would you like to see a customized filtered menu based on a user-specified price point?(y/n)";
    cin>>choice;
    if(choice!='y' && choice!='n')
    {
      goto menucustom;
    }
    else if(choice=='y')
    {
    long int price;
    priceloop:
    cout<<"Enter Price: $";
    cin>>price;
    if(price<0 || price >9999)
    goto priceloop;

    f.customshow(price);
    }
    else if(choice =='n')
    {}
    pause;
}

