#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include "Time.h"
#include "Date.h"

class ticketInfo
{
    public:
    Date currentFile;
    Time startFile, endFile;
    int priceFile, seatFile, bookingFile;

    ticketInfo();
    ticketInfo(Date cur, Time st, Time en, int pr, int se, int bo);
    void writeInfoToFile(string);
};