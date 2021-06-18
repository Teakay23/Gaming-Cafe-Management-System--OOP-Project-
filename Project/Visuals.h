#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include<fstream>
#define usleep(x) Sleep(500*x)
using namespace std;
class Pre_Account_Open_Visuals
{
    public:
    void entry_visual();
    void login_display();
    void dragon_display();
    void after_login_display();
    void displaygraph();
    void printdog(int, int);
};
class Post_Account_Open_Visuals
{
    public:
    int plane_welcome();
    void manager_initial_display();
    void receptionist_manager();
    void technical_initial_display();
    void regular_initial_display();
    void Accountant_initial_display();
    void Customer_ticket_display();
    void OneTimeTicketDisplay();
    
};
class Visuals:public Pre_Account_Open_Visuals,public Post_Account_Open_Visuals
{
    public:
    void technical_feedback();
    void Complex_ID_border();
    void person_details_display();
    void food_visual();
    void food_after_visual();


};




