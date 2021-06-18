#include "Date.h"

Date::Date(int day,int month,int year) 
{
  //day
  if(day < 0 || ((month == 4 || month == 6 || month == 9 || month == 11) && day>30) || ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) || (month == 2 && day > 28) || day > 31 )
    date[0] = 1;
  else
    date[0] = day;

  //month
  if(month > 0 && month <= 11)
    date[1] = month;
  else
    date[1] = 1;
  
  //year
  if(year >= 1950 && year <= 2030)
    date[2] = year;
  else
    date[2] = 1999;
}
const Date& Date::operator=(int a[3])
{
  if(this->date!=a)
  {
    //day
    if(a[0] < 0 || ((a[1] == 4 || a[1] == 6 || a[1] == 9 || a[1] == 11) && a[0]>30) || ((a[1] == 1 || a[1] == 3 || a[1] == 5 || a[1] == 7 || a[1] == 8 || a[1] == 10 || a[1] == 12) && a[0] > 31) || (a[1] == 2 && a[0] > 28) || a[0] > 31 )
      date[0] = 1;
    else
      date[0] = a[0];

    //month
    if(a[1] > 0 && a[1] <= 11)
      date[1] = a[1];
    else
      date[1] = 1;

    //year
    if(a[2] >= 1950 && a[2] <= 2030)
      date[2] = a[2];
    else
      date[2] = 1999;
    }
  return *this;

}
Date::Date(int a[3])
{
  //day
  if(a[0] < 0 || ((a[1] == 4 || a[1] == 6 || a[1] == 9 || a[1] == 11) && a[0]>30) || ((a[1] == 1 || a[1] == 3 || a[1] == 5 || a[1] == 7 || a[1] == 8 || a[1] == 10 || a[1] == 12) && a[0] > 31) || (a[1] == 2 && a[0] > 28) || a[0] > 31 )
    date[0] = 1;
  else
    date[0] = a[0];

  //month
  if(a[1] > 0 && a[1] <= 11)
    date[1] = a[1];
  else
    date[1] = 1;
  
  //year
  if(a[2] >= 1950 && a[2] <= 2030)
    date[2] = a[2];
  else
    date[2] = 1999;
}

Date::~Date()
{
}
Date::Date()
{
    date[0]=0;date[1]=0;date[2]=0;
}
bool Date::operator>=(const Date& a) const
{
if(*this>a || *this==a)
return true;
else return false;
}
bool Date::operator>(const Date& a) const
{
if (!(*this<a) && *this!=a)
return true;
else
{
  return false;
}
}
bool Date::operator<=(const Date& a) const
{
if(*this==a || *this<a)
return true;
else return false;
}
bool Date::operator<(const Date& a) const
{
    if(date[2]<a.date[2])
      return true;
    else if(date[2]==a.date[2] && date[1]<a.date[1])
      return true;
    else if(date[2]==a.date[2] && date[1]==a.date[1] && date[0]<a.date[0])
      return true;
    else
      return false;
}
bool Date::operator!=(const Date& a) const
{
if(date[2]==a.date[2] && date[1]==a.date[1] && date[0]==a.date[0])
return false;
else return true;
}

bool Date::operator==(const Date& a) const
{

if(date[2]==a.date[2] && date[1]==a.date[1] && date[0]==a.date[0])
return true;
else return false;
}
const int& Date::operator[](int index) const
{
assert(0 >= index && index < sizeof(date));
return date[index];
}
const Date& Date::operator=(const Date& a)
{
if (this!=&a)
{
date[0]=a.date[0];
date[1]=a.date[1];
date[2]=a.date[2];
}
return *this;

}
ostream& operator << (ostream& a, const Date b) 
{
  if(b.date[0] < 10)
        a << "0";
    a << b.date[0] << "/";
    
    if(b.date[1] < 10)
        a << "0";

    a << b.date[1] << "/" << b.date[2];

  return a;
}
istream& operator >> (istream& a, Date& b) // input in format DD/MM/YYYY
{
  int day, month, year;
  a >> day;
  a.ignore(); // ignore "/"
  a >> month;
  a.ignore(); // ignore "/"
  a >> year;

  if(day < 0 || ((month == 4 || month == 6 || month == 9 || month == 11) && day>30) || ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) || (month == 2 && day > 28) || day > 31)
    b.date[0] = 1;
  else
    b.date[0] = day;

  //month
  if(month > 0 && month <= 11)
    b.date[1] = month;
  else
    b.date[1] = 1;
  
  //year
  if(year >= 1950 && year <= 2030)
    b.date[2] = year;
  else
    b.date[2] = 1999;

  return a;
}

void Date::incrementDay()
{
  date[0]++;

  if(((date[1] == 1 || date[1] == 3 || date[1] == 5 || date[1] == 7 || date[1] == 8 || date[1] == 10 || date[1] == 12) && date[0] > 31) || (date[1] == 2 && date[0] > 28) || ((date[1] == 4 || date[1] == 6 || date[1] == 9 || date[1] == 11) && date[0]>30))
  {
    date[1]++;
    date[0] = 1;
  }

  if(date[1] > 12)
  {
    date[2]++;
    date[1] = 1;
  }
}

void Date::setDate(int day, int month, int year)
{
  //day
  if(day < 0 || ((month == 4 || month == 6 || month == 9 || month == 11) && day>30) || ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) || (month == 2 && day > 28) || day > 31)
    date[0] = 1;
  else
    date[0] = day;

  //month
  if(month > 0 && month <= 11)
    date[1] = month;
  else
    date[1] = 1;
  
  //year
  if(year >= 1950 && year <= 2030)
    date[2] = year;
  else
    date[2] = 1999;
}

bool Date::compareMonth(const Date& a) const
{
  if(date[2]==a.date[2] && date[1]==a.date[1])
    return true;
  else
    return false;
}
