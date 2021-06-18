#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<conio.h>
#include"ticketInfo.h"
#include"Person.h"
using namespace std;

Time getCurrentTime();

class FeedbackSystem
{
    private:
        // Time getCurrentTime();
        string name;
        int seat;
        string Problem;
        float amount;
        string feedback;
    public:
        FeedbackSystem();
        void Feedback();    //string name, int seat, string feedback, string *appliances, float *price, int x);
        void getFeedback(string,string);
        float viewFeedback();
        void FilteredFeedback();
        ~FeedbackSystem();
        void returnmain();
        friend ostream& operator<< (ostream& os, FeedbackSystem& TS);
        //friend istream& operator>> (istream& is, FeedbackSystem& TS);
};

