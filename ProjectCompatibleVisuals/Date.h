#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include<assert.h>
using namespace std;

class Date
{
    protected:
    int date[3];
    friend ostream& operator << (ostream&, const Date);
    friend istream& operator >> (istream&, Date&);

    public:

    const Date& operator=(int *);
    const Date& operator=(const Date&);
    const int &operator[](int) const;
    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>=(const Date&) const;
    bool operator>(const Date&) const;

    Date(int ,int ,int ) ; 
    Date(int a[]);
    Date();
    ~Date();
    
    void setDate(int, int ,int);
    void incrementDay();
    void printDate();
    bool compareMonth(const Date&) const;
};