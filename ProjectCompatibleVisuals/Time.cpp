#include "Time.h"

bool Time::operator==(const Time& t) const
{
    if(t.hour == hour && t.minute == minute && t.date == date)
        return true;
    else
        return false;
}

bool Time::operator!=(const Time& t) const
{
    if(t.hour != hour || t.minute != minute || t.date != date)
        return true;
    else
        return false;
}

bool Time::operator<=(const Time& t) const
{
    if(*this == t || *this < t)
        return true;
    else
        return false;
}

bool Time::operator<(const Time& t) const
{
    if(date < t.date)
        return true;
    if(date == t.date && hour < t.hour)
        return true;
    if(date == t.date && hour == t.hour && minute < t.minute)
        return true;
    else
        return false;
}

bool Time::operator>=(const Time& t) const
{
    if(*this == t || *this > t)
        return true;
    else
        return false;
}

bool Time::operator>(const Time& t) const
{
    if(date > t.date)
        return true;
    if(date == t.date && hour > t.hour)
        return true;
    if(date == t.date && hour == t.hour && minute > t.minute)
        return true;
    else
        return false;
}

int Time::operator-(const Time& t) const
{
    if(t.date == date)
        return hour - t.hour;
    
    if(t.date < date)
        return (hour+24)-t.hour;
}

const Time Time::operator=(const Time& t)
{
    hour = t.hour;
    minute = t.minute;
    date = t.date;
}

ostream& operator << (ostream& output, const Time t)
{
    if(t.hour < 10)
        output << "0";
    output << t.hour << ":";
    
    if(t.minute < 10)
        output << "0";

    output << t.minute << "  " << t.date;

    return output;
}

istream& operator >> (istream& input, Time& t) // input in format HH/MM
{
    int hr, min;
    input >> hr;
    input.ignore(); // ignore ":"
    input >> min;

    if(hr >= 0 && hr <= 23)
        t.hour = hr;
    else
        t.hour = 0;
    
    if(min >= 0 && min <= 59)
        t.minute = min;
    else
        t.minute = 0;

    return input;
}

void Time::inputDate()
{
    cin >> date;
}

Time::Time(){}

Time::Time(int hr, int min)
{
    if(hr >= 0 && hr <= 23)
        hour = hr;
    else
        hour = 0;
    
    if(min >= 0 && min <= 59)
        minute = min;
    else
        minute = 0;
}

Time::Time(int hr, int min, int day, int month, int year)
{
    if(hr >= 0 && hr <= 23)
        hour = hr;
    else
        hour = 0;
    
    if(min >= 0 && min <= 59)
        minute = min;
    else
        minute = 0;
    
    date.setDate(day, month, year);
}

void Time::setTime(int hr, int min)
{
    if(hr >= 0 && hr <= 23)
        hour = hr;
    else
        hour = 0;
    
    if(min >= 0 && min <= 59)
        minute = min;
    else
        minute = 0;
}

void Time::setTimeAndDate(int hr, int min, int day, int month, int year)
{
    if(hr >= 0 && hr <= 23)
        hour = hr;
    else
        hour = 0;
    
    if(min >= 0 && min <= 59)
        minute = min;
    else
        minute = 0;
    
    date.setDate(day, month, year);
}

void Time::incrementMinute(int min)
{
    minute += min;
    if(minute > 59)
    {
        minute -= 60;
        incrementHour(1);
    }
}

void Time::incrementHour(int hr)
{
    hour += hr;
    if(hour > 23)
    {
        hour -= 24;
        date.incrementDay();
    }
}

Time Time::operator+(const int hr)
{
    Time temp = *this;

    temp.hour += hr;
    if(temp.hour > 23)
    {
        temp.hour -= 24;
        temp.date.incrementDay();
    }

    return temp;
}