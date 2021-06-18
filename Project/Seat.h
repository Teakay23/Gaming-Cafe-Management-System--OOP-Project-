#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
#include "Time.h"
#include "Booking.h"
using namespace std;

class Seat
{
    protected:
    int seatNo;
    Booking b[10];
    double amountOfCash;
    static int seatNoCounter; //this sets the seat number for all seats in an array
    void printInFile(int bookingNo);

    public:

    Seat();

    bool book(Time start, Time end, int pricePerHour, int& book); // to book a particular seat [Last parameter int& book is to send the booking number to the ticket manager to be stored in customers ticket history]
    bool book(Time start, Time end, int pricePerHour, int numOfTicket, int& book); // to book a random seat
    void cancelBooking(int bookingNo);
    double returnCash();
    double withdrawCash(); // sets the value of amountOfCash to ZERO meaning it has been withdrawed
    void printCurrentBookings();
    void updateAllBookings();
    void freeBooking(int bookingNo);
    void printInfo(int bookingNo);
    void saveSeatInfo(ofstream&);
    void readSeatInfo(ifstream&);
};