#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include"ticketInfo.h"

using namespace std;

Time getCurrentTime();

class ChatSystem
{
    protected:
        int s_seat = 0, r_seat = 0;
        string name, message;

    private:
        int c=0, count=2;      //Things used to implemet the blocker
        int blocker[16];
        int func_value = 0;
    public:
        void getinfo(string name);
        void actions();
        void sendmessage();
        void writingprocedure();
        void recievemessage();
        void block();
        void checkvalidity(string name, int check_s);
        void clearfiles(int check_s);
        void clearfiles_support();
};

