#pragma once
#include<iostream>
#include<iomanip>
#include "Date.h"
using namespace std;

class Time
{
    protected:
    int hour, minute;

    public:
    Date date;
    
    Time();
    Time(int hr, int min);
    Time(int hr, int min, int day, int month, int year);

    bool operator==(const Time&) const;
    bool operator!=(const Time&) const;
    bool operator<=(const Time&) const;
    bool operator<(const Time&) const;
    bool operator>=(const Time&) const;
    bool operator>(const Time&) const;
    int operator-(const Time&) const;
    Time operator+(const int);
    const Time operator=(const Time&);

    void setTime(int, int);
    void setTimeAndDate(int, int, int, int, int);
    void incrementMinute(int);
    void incrementHour(int);
    void inputDate();


    friend ostream& operator << (ostream&, const Time);
    friend istream& operator >> (istream&, Time&);
};

