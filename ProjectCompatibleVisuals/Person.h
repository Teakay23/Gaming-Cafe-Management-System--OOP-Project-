#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include<assert.h>
#include<cstdlib>
#include <fstream>
#include"Visuals.h"
#define clear system("cls");
#define ig cin.ignore()
#define nxt cout<<endl
#define pause system("PAUSE")
using namespace std;

class Person
{
    Visuals V;
    int temp_file_name=0;
    string cin_name;
    string name;
    char gender;
    int age;
    string city;
    string file_name[5]={"Acc_Details.dat", "Cust_Details.dat", "Man_Details.dat", "Tech_Details.dat", "Reg_Details.dat"};
    string participants[5]={"Accountant_Password.dat", "Customer_Password.dat", "Manager_Password.dat","Technical_Password.dat", "Regular_Password.dat"};
    public:
    friend ostream& operator<<(ostream&, Person&);
    friend ostream& operator,(ostream&, Person&);
    friend istream& operator>>(istream&, Person&);
    friend istream& operator,(istream&, Person&);
    void operator =(int);
    void Append_Info(string*, char*,int*,string *,int,int);
    void Insert_Info(string*, char*,int*,string *,int,int);
    void Get_Info(string,string,int);
    void Print_Info();
    void get_details(int);
    string return_name(string, string, int);
    string return_name(string, int);
    void remove_all_personal_data(string,string,int);

    string return_name();
};

