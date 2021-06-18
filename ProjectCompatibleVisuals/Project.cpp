#include"Accountant.h"
#include"Manager.h"
#include"RegularStaff.h"
#include"Customer.h"
#include"Tech_Staff.h"
#include"OneTimeCustomer.h"

int main()
{
    system("mode 650");
    /* ALL DATA BEING LOADED FROM THE FILE FOR RELEVANT USE */
    // ID ID; 
    // ID.EXTRACT_FROM_FILE();
    // Schedule Accountant_Schedule;
    // Schedule Customer_Schedule;
    // Schedule Manager_Schedule;
    // Schedule Technical_Department_Schedule;
    // Schedule Regular_Worker_Schedule;
    // Accountant_Schedule.EXTRACT_SCHEDULE_FILE(1);
    // Customer_Schedule.EXTRACT_SCHEDULE_FILE(2);
    // Manager_Schedule.EXTRACT_SCHEDULE_FILE(3);
    // Technical_Department_Schedule.EXTRACT_SCHEDULE_FILE(4);
    // Regular_Worker_Schedule.EXTRACT_SCHEDULE_FILE(5);
    // food f;
    // f.Extract_from_file();
      // Person Details;
    // clear;
    int initial_choice;
    Visuals V;
    Password Personnel;
    Person Person;
    Regular_Staff RegularWorker;
    Tech_Staff Tech;
    Manager Manager;
    Accountant Accountant;
    Customer Customer;
    ID ID;
    string name, password;
    //----------->Customer
    // string name="Henry Cavern", password= "Shelbie"; //------------>Accountant
    // string name="Adrian"; string password="12345"; //----------->Manager
    // string name="Mejjie"; string password="Elephant Boy"; //----------->Tech
    // string name="Sora"; string password="12345"; //------------->Regular

    //Code:g++ -g Project.cpp Manager.cpp RegularStaff.cpp Password.cpp Complex_ID.cpp Person.cpp Foodmenu.cpp ScheduleWorker.cpp Visuals.cpp Seat.cpp oneTimeTicket.cpp recurringTicket.cpp TicketingSystem.cpp TicketMachine.cpp TicketManagement.cpp Date.cpp Time.cpp Impartial_Tech.cpp RegularEquipment.cpp CybernetComputer.cpp ticketInfo.cpp Accountant.cpp FeedbackSystem.cpp Customer.cpp chatsystem.cpp Tech_Staff.cpp OneTimeCustomer.cpp
    V.entry_visual();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
    initiation_point:
    clear;    
    V.dragon_display();
    // cout<<"1. Make New Account.\n2. Access Pre-existing Account.\n3. Book A Ticket Without An Account.\n4. View Userbase Infographic.\n5. Exit"<<endl;
    cin>>initial_choice;
    if(initial_choice==1)
    {
        newaccountantmaker:
        int account_choice;
        clear;
        cout<<"1. Make A Fresh Account For Customer.\n2. Make A Fresh Account For Accountant.\n3. Make A Fresh Account For Manager.\n4. Make A Fresh Account For Technical Staff.\n5. Make A Fresh Account For Regular Staff.\n6. Return to Login Select."<<endl;
        cin>>account_choice;
        clear;
        if(account_choice==1)
        {
            Personnel.Get_Password_From_User(2);
            Person.get_details(2);
            ID.EXTRACT_FROM_FILE();
            ID=2;
            ID=Person.return_name();
            ID.INSERT_IN_FILE();
            goto initiation_point;
        }
        else if(account_choice==2)
        {
            Personnel.Get_Password_From_User(1);
            Person.get_details(1);
            ID.EXTRACT_FROM_FILE();
            ID=1;
            ID=Person.return_name();
            ID.INSERT_IN_FILE();
            goto initiation_point;
        }
        else if(account_choice==3)
        {
            Personnel.Get_Password_From_User(3);
            Person.get_details(3);
            ID.EXTRACT_FROM_FILE();
            ID=3;
            ID=Person.return_name();
            ID.INSERT_IN_FILE();
            goto initiation_point;
        }
        else if(account_choice==4)
        {
            Personnel.Get_Password_From_User(4);
            Person.get_details(4);
            ID.EXTRACT_FROM_FILE();
            ID=4;
            ID=Person.return_name();
            ID.INSERT_IN_FILE();
            goto initiation_point;
        }
        else if(account_choice==5)
        {
            Personnel.Get_Password_From_User(5);
            Person.get_details(5);
            ID.EXTRACT_FROM_FILE();
            ID=5;
            ID=Person.return_name();
            ID.INSERT_IN_FILE();
            goto initiation_point;
        }
         else if(account_choice==6)
        {
            goto initiation_point;
        }
        else if(account_choice<1 || account_choice>6)
        {
            goto newaccountantmaker;
        }
    }
    else if(initial_choice==2)
    {
        V.after_login_display();
        cin.ignore();
        login:
        clear;
        V.login_display();                               
        cout<<"\nEnter Username:___________\b\b\b\b\b\b\b\b\b\b\b";
        getline(cin,name);
        cout<<"\nEnter Password:___________\b\b\b\b\b\b\b\b\b\b\b";
        getline(cin,password);
        clear;
        /*-------------------------------------ACCOUNTANT SECTION-------------------------------------*/
        if(Personnel.check_password(name, password,1))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
            clear;
            int choice;
            cout<<"Welcome Accountant "<<name<<"!"<<endl;
            pause;
            accountant_reception:
            clear;
            V.Accountant_initial_display();
            // choice=V.plane_welcome();
            cin>>choice;
            if(choice==1)
            {
                Accountant.Get_Info(name,password,1);
                goto accountant_reception;
            }
            else if(choice==2)
            {      
                Accountant.viewTicketInfo();
                goto accountant_reception;
            }
            else if(choice==3)
            {
                Accountant.checkDayBookings();
                goto accountant_reception;
            }
            else if(choice==4)
            {
                Accountant.checkMonthBookings();
                goto accountant_reception;
            }
            else if(choice==5)
            {  
                Accountant.checkAllBookings();
                goto accountant_reception;
            }
            else if(choice==6)
            {
                Accountant.withdrawAllCash();
                goto accountant_reception;
            }
            else if(choice==7)
            {
                Accountant.checkWithdrawHistory();
                goto accountant_reception;
            }
            else if(choice==8)
            {
                Accountant.cancelTicket();
                goto accountant_reception;
            }
            else if(choice==9)
            {
                Accountant.delete_account(name,password);
                goto initiation_point;
            }
             else if(choice==10)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
                goto initiation_point;
            }
             else if(choice==11)
            {
                exit(0);
            }
            else if(choice<1 || choice>11)
                goto accountant_reception;
        }
        /*-------------------------------------CUSTOMER SECTION------------------------------------- */
        else if(Personnel.check_password(name, password,2))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),79);
            clear;
            Customer.inputUsername(name);
            int choice;
            cout<<"Welcome Customer "<<name<<"!"<<endl;
            pause;
            customerbeginnerpoint:
            clear;
            cout<<"1. Chat With Other Seat Holders.\n2. Book Ticket For Seat.\n3. Return to Login Menu\n4. Delete Account.\n5. Exit"<<endl;
            cin>>choice;
            if(choice==1)
            {
                Customer.chatmachine(name);
                goto customerbeginnerpoint;
            }
            else if(choice==2)
            {
                customer_reception:
                clear;
                V.Customer_ticket_display();
                // choice=V.plane_welcome();
                cin>>choice;
                if(choice==1)
                {
                    Customer.Get_Info(name,password,2);
                    goto customer_reception;
                }
                else if(choice==2)
                {         
                    Customer.bookTicket();
                    goto customer_reception;
                }
                else if(choice==3)
                {
                    Customer.bookSpecificSeat();
                    goto customer_reception;
                }
                else if(choice==4)
                {
                    Customer.cancelTicket();
                    goto customer_reception;
                }
                else if(choice==5)
                {  
                    Customer.checkBookingHistory();
                    goto customer_reception;
                }
                else if(choice==6)
                {  
                    clear;
                    Customer.getfeedback(name,password);
                    goto customer_reception;
                }
                else if(choice==7)
                {  
                    Customer.saveAllSeatInfo();
                    goto customerbeginnerpoint;
                }
                else if(choice==8)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
                    Customer.saveAllSeatInfo();
                    goto initiation_point;
                }
                else if(choice==9)
                {
                    Customer.saveAllSeatInfo();
                    exit(0);
                }
        
                else if(choice<1 || choice>9)
                goto customer_reception;
            }
            else if(choice==3)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
                goto initiation_point;
            }
            else if(choice==4)
            {
                Customer.delete_account(name,password);
                goto initiation_point;
            }
            else if(choice==5)
            {
                exit(0);
            }
        }
        /*------------------------------------- MANAGER SECTION -------------------------------------*/
        else if(Personnel.check_password(name, password,3))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);
            clear;
            int choice;
            cout<<"Welcome Manager "<<name<<"!"<<endl;
            pause;
            clear;
            V.manager_initial_display();
            pause;
           
            reception:
            clear;
            V.receptionist_manager();
            // choice=V.plane_welcome();
            cin>>choice;
            if(choice==1)
            {
                Manager.Get_Info(name,password,3);
                goto reception;
            }
            else if(choice==2)
            {      
                Manager.show_all_worker_IDs();
                goto reception;
            }
            else if(choice==3)
            {
                Manager.set_regular_worker_schedule();
                goto reception;
            }
            else if(choice==4)
            {
                Manager.view_all_monthly_regular_schedule();
                goto reception;
            }
            else if(choice==5)
            {    
                Manager.set_technical_worker_schedule();
                goto reception;
            }
            else if(choice==6)
            {
                Manager.view_all_monthly_technical_schedule();   
                goto reception;
            }
            else if(choice==7)
            {
                Manager.set_food_menu();
                goto reception;
            }
            else if(choice==8)
            {
                Manager.view_food_menu();
                goto reception;
            }
            else if(choice==9)
            {    
                Manager.delete_account(name,password);
                goto initiation_point;
            }
            else if(choice==10)
            {
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
               goto initiation_point;
            }
            else if(choice==11)
            {
                exit(0);
            }
            else if(choice<1 || choice>11)
                goto reception;
        }
        /*-------------------------------------TECHNICAL DEPARTMENT SECTION-------------------------------------*/
        else if(Personnel.check_password(name, password,4))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),111);
            clear;
            int choice;
            cout<<"Welcome Technical Department Employee "<<name<<"!"<<endl;
            pause;
            tech_reception:
            clear;
            V.technical_initial_display();
            // choice=V.plane_welcome();
            cin>>choice;
            if(choice==1)
            {
                Tech.Get_Info(name,password, 4);
                goto tech_reception;
            }
            else if(choice==2)
            {
                Tech.view_all_monthly_technical_staff_schedule();
                goto tech_reception;
            }
            else if(choice==3)
            {
                Tech.view_feedback();
                goto tech_reception;
            }
            else if(choice==4)
            {
                Tech.View_Inventory_PCs();
                goto tech_reception;
            }
            else if(choice==5)
            {
                Tech.Allot_Inventory_PCs();
                goto tech_reception;
            }
            else if(choice==6)
            {
                Tech.View_Inventory_Regular();
                goto tech_reception;
            }
            else if(choice==7)
            {
                Tech.Allot_Inventory_Regular();
                goto tech_reception;
            }
            else if(choice==8)
            {
                Tech.delete_account(name,password);
                goto initiation_point; 
            }
            else if(choice==9)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
                goto initiation_point;
            }
            else if(choice==10)
            {
                exit(0);
            }
             else if(choice<1 || choice>10)
                goto tech_reception;
        }
        /*-------------------------------------REGULAR DEPARTMENT SECTION-------------------------------------*/
        else if(Personnel.check_password(name, password,5))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),112);
            clear;
            int choice;
            cout<<"Welcome Service Department Worker "<<name<<"!"<<endl;
            pause;
            regular_reception:
            clear;
            V.regular_initial_display();
            // choice=V.plane_welcome();
            cin>>choice;
            if(choice==1)
            {
                RegularWorker.Get_Info(name,password, 5);
                goto regular_reception;
            }
            else if(choice==2)
            {
                RegularWorker.view_all_monthly_regular_schedule();
                goto regular_reception;
            }
            else if(choice==3)
            {
                RegularWorker.delete_account(name,password);
                goto initiation_point;
            }
              else if(choice==4)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
                goto initiation_point;
            }
              else if(choice==5)
            {
                exit(0);
            }
            else if(choice<1 || choice>5)
                goto regular_reception;
        }
        else if(!Personnel.check_password(name, password,5) && !Personnel.check_password(name, password,4) && !Personnel.check_password(name, password,3) && !Personnel.check_password(name, password,3) && !Personnel.check_password(name, password,2) && !Personnel.check_password(name, password,1))
        {
            cout<<"Password/Username entered is incorrect!";
            pause;
            goto login;
        }
    }
    else if(initial_choice==3)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
        OneTimeCustomer ONE;    
        int choice;
        onetime_reception:
        clear;
        V.OneTimeTicketDisplay();
        cin>>choice;
        if(choice==1)
        {
            ONE.checkPricing();
            goto onetime_reception;
        }
        else if(choice==2)
        {
            ONE.viewTicketInfo();
            goto onetime_reception;
        }
        else if(choice==3)
        {
            ONE.bookTicket();
            goto onetime_reception;
        }
        else if(choice==4)
        {
            ONE.cancelTicket();
            goto onetime_reception;
        }
        else if(choice==5)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
            goto initiation_point;
        }
        else if(choice==6)
        {
            exit(0);
        }
        else if(choice<1 || choice>6)
            goto onetime_reception;
    }
    else if(initial_choice==4)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        V.displaygraph();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
        goto initiation_point;
    }
    else if(initial_choice==5)
    {
        exit(0);
    }
}
