#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include<assert.h>
#include<cstdlib>
#include<fstream>
#include <stdio.h> 
#include <stdlib.h> 
#define clear system("cls");
#define ig cin.ignore()
#define nxt cout<<endl
#define pause system("PAUSE")
using namespace std;


template<class U>
class Impartial_Tech
{
    protected:
    int no_of_models=0;
    int *inventory;
    int items=0;
    double price=78.9;
    double amount;
    void input_file();
    void extract_file();
    public:
    void *type;
    void get_data();
    void modelsetter(U *,int *,int);
    virtual void displayer()=0;
    int intlength(int);
    int itemnamelength(U name);
};



template class Impartial_Tech<string>;