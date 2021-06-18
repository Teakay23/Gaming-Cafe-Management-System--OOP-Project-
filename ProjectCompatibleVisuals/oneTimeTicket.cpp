#include "oneTimeTicket.h"

void oneTimeTicket::bookTicket()
{
    int i, dummy;
    enterTiming();

    for(i=0; !seats[i].book(start, end, basePricePerHour, 1, dummy) && i<numSeats ; i++)
    {
    }

    if(i == numSeats)
        cout << "\nSorry! No seats are free on the specified time slot." << endl;
        
    saveAllSeatInfo();
    system("PAUSE");
}

void oneTimeTicket::cancelTicket()
{
    system("cls");
    cout << "\nPlease Email or Call our 24/7 helpline to cancel your ticket.\nNon account holders can not cancel booking directly as to prevent accidental/intentional cancellation of random tickets.\nThank you for understanding!" << endl;
    system("PAUSE");
}