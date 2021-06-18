#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include<assert.h>
#include<cstdlib>
#include <fstream>
#include"Visuals.h"
#include"Complex_ID.h"
#define clear system("cls");
#define ig cin.ignore()
#define nxt cout<<endl
#define pause system("PAUSE")
using namespace std;


class Password
{
string name;
string password;
string participants[5]={"Accountant_Password.dat", "Customer_Password.dat", "Manager_Password.dat","Technical_Password.dat", "Regular_Password.dat"};
public:
friend ostream& operator<<(ostream&, Password&);
friend ostream& operator,(ostream&, Password&);
friend istream& operator>>(istream&, Password&);
friend istream& operator,(istream&, Password&);
void Append_Info(string*, string *, int, int);
void Insert_Info(string*, string *, int, int);
bool check_password(string, string, int);
void Get_Password_From_User(int);
void return_password(string, int);
void delete_ID(string,string,int);
void delete_password(string,string,int);
};
