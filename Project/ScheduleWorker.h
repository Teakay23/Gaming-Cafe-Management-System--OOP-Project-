#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include<assert.h>
#include<cstdlib>
#include<fstream>
#define clear system("cls");
#define ig cin.ignore()
#define nxt cout<<endl
#define pause system("PAUSE")
using namespace std;


class Schedule
{
    friend ostream& operator<<(ostream&, Schedule&);
    friend ostream& operator,(ostream&, Schedule&);
    friend istream& operator>>(istream&, Schedule&);
    friend istream& operator,(istream&, Schedule&);
    int no_of_workers=0;
    int no_of_tasks=0;
    int mon=0;
    const string* tasks;
    int ***random_number;
    const char* month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string worker_file[5]={"Acc_Worker.dat", "Cust_Worker.dat", "Man_Worker.dat", "Tech_Worker.dat", "Reg_Worker.dat"};
    string task_file[5]={"Acc_Tasks.dat", "Cust_Tasks.dat", "Man_Tasks.dat", "Tech_Tasks.dat", "Reg_Tasks.dat"};
    string task_save_file[5]={"Acc_Task_Save.dat", "Cust_Task_Save.dat", "Man_Task_Save.dat", "Tech_Tech_Save.dat", "Reg_Tech_Save.dat"};
    const string* workers;
    public:
    void operator=(int);
    void randomize();
    void worker_count();
    void task_arrange();
    void print_schedule(int);
    void GetParticipaints(string*,string*,int,int);
    void GetParticipaints(string*,int);
    Schedule(string*,string*,int,int);
    Schedule(string*,int b);
    ~Schedule();
    Schedule();
    void INPUT_SCHEDULE_FILE(int);
    void EXTRACT_SCHEDULE_FILE(int);
};



// int main()
// {
// /*TO INPUT/OUTPUT DATA VIA MEMBER INITIALIZER LIST*/
// string names[]={"Calsie", "Bouyer", "Normes","Holdfim"};
// string tasks[]={"Murder a child", "Get rid of the body", "Shatter the bone marrow", "Burn it till the tissue dissipates", "Get coffee"};
// Schedule S2;

// // for the above, the ARGUMENTS ARE (string, string,no. elements of first string,no. elements of second string)

// /* 
// There is an alternate version which takes only names, send argument of(string, no. of elements in string)
// for example: Schedule S3(names, sizeof(names)/sizeof(names[0]));
// */
// //Input month you want
// // S2.INPUT_SCHEDULE_FILE();
// S2.EXTRACT_SCHEDULE_FILE();
// S2=5;
// cout<<S2;
// S2=6;
// cout<<S2;
// S2=5;
// cout<<S2;
// pause;
// clear;
// /*TO INPUT/OUTPUT DATA MANUALLY*/
// Schedule S1;
// cin>>S1;
// cout<<S1;
// pause;
// clear;
// /*TO OUTPUT TWO CONSECUTIVE OBJECTS*/
// cout<<S1,S2;
// pause;
// }