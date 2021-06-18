#include <iostream>
#include "Seat.h"

// global function

Time getCurrentTime() // global function for now, don't know if i should implement it inside a class
{
    const time_t now = time(nullptr) ; //get the current absolute time
    const tm calendar_time = *localtime(addressof(now)) ; //convert it to local time

    Time currentTime(calendar_time.tm_hour, calendar_time.tm_min, calendar_time.tm_mday, calendar_time.tm_mon+1, calendar_time.tm_year+1900);

    return currentTime;
}

//actual class starts here

Seat::Seat()
{
    // bookingNoCounter = 0;
    amountOfCash = 0;
    seatNo = ++seatNoCounter;
}

void Seat::printCurrentBookings() // prints all the currently booked slots
{
    cout << "\nThe current bookings are as follows:\n\n" << left << setw(20) << "Seat No." << left << setw(20) << "Booking No." << left << setw(20) << "Start Time" << left << setw(20) << "End Time" << "Amount Paid" << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n" << endl;

    for(int i=0;i<10;i++)
    {
        if(b[i].booked == 1)
            printInfo(i);
    }
}

void Seat::cancelBooking(int bookingNo)
{
    Time current = getCurrentTime();

    updateAllBookings();

    if(b[bookingNo].booked == 0)
    {
        cout << "\nSuch booking does not exist." << endl;
    }

    if(bookingNo<10 && b[bookingNo].booked == 1) // checking if the booking number is valid 
    {
        ofstream outfile("SeatBookings.txt", fstream::app);
        amountOfCash -= b[bookingNo].amountPaid; // returning cash to customer then printing out cancellation in SeatBooking.txt file
        outfile << current.date << "          " << "SN#" << left << setw(3) << seatNo << "              " << left << setw(2) << bookingNo +1 << "                  " << b[bookingNo].startTime << "   " << b[bookingNo].endTime << "   " << left << setw(5) << -b[bookingNo].amountPaid << " (CANCELLATION TICKET)" << endl;
        outfile.close();

        int bN = bookingNo+1, amnt = -b[bookingNo].amountPaid;
        ofstream file("BinaryBookings.bin", ios::app | ios::binary);
        file.write(reinterpret_cast<char*> (&current.date), sizeof(current.date));
        file.write(reinterpret_cast<char*> (&seatNo), sizeof(seatNo));
        file.write(reinterpret_cast<char*> (&bN), sizeof(bN));
        file.write(reinterpret_cast<char*> (&b[bookingNo].startTime), sizeof(b[bookingNo].startTime));
        file.write(reinterpret_cast<char*> (&b[bookingNo].endTime), sizeof(b[bookingNo].endTime));
        file.write(reinterpret_cast<char*> (&amnt), sizeof(amnt));
        file.close();

        freeBooking(bookingNo); // cancelling the booking

        cout << "\nSpecified booking has been cancelled." << endl;
    }
}

void Seat::freeBooking(int bookingNo) // when the time for booking has ended or booking is cancelled, this function will free the time slot
{
    if(bookingNo<10 && b[bookingNo].booked == 1)
    {
        b[bookingNo].booked = 0;
    }
}

void Seat::updateAllBookings() // runs whenever a customer clicks on "Book Seat", so that all the free and occupied time slots are updated
{
    Time currentTime = getCurrentTime();

    for(int i=0;i<10;i++)
    {
        if(currentTime > b[i].endTime)
        {    
            freeBooking(i);
        }
    }
}

void Seat::printInfo(int bookingNo) // if you want to change formatting, be sure to change the formatting of the labels/headings (i.e. Seat#   Booking#   Start Time   End Time) on top accordingly
{
    if(b[bookingNo].booked == 0)
    {
        cout << "\nSuch booking does not exist!" << endl;
        return;
    }

    // if(b[bookingNo].endTime - b[bookingNo].startTime >= 1)
        cout << "SN#" << left << setw(3) << seatNo << "              " << left << setw(2) << bookingNo +1 << "                  " << b[bookingNo].startTime << "   " << b[bookingNo].endTime << "   " << left << setw(2) << b[bookingNo].amountPaid << endl;
}

void Seat::printInFile(int bookingNo)
{
    Time current = getCurrentTime();

    ofstream outfile("SeatBookings.txt", fstream::app); // writing booking info to file
    outfile << current.date << "          " << "SN#" << left << setw(3) << seatNo << "              " << left << setw(2) << bookingNo +1 << "                  " << b[bookingNo].startTime << "   " << b[bookingNo].endTime << "   " << left << setw(5) << b[bookingNo].amountPaid << "                      " << endl;
    outfile.close();

    // writing in binary file for the management to read
    int bN = bookingNo+1;
    ofstream file("BinaryBookings.bin", ios::app | ios::binary);
    file.write(reinterpret_cast<char*> (&current.date), sizeof(current.date));
    file.write(reinterpret_cast<char*> (&seatNo), sizeof(seatNo));
    file.write(reinterpret_cast<char*> (&bN), sizeof(bN));
    file.write(reinterpret_cast<char*> (&b[bookingNo].startTime), sizeof(b[bookingNo].startTime));
    file.write(reinterpret_cast<char*> (&b[bookingNo].endTime), sizeof(b[bookingNo].endTime));
    file.write(reinterpret_cast<char*> (&b[bookingNo].amountPaid), sizeof(b[bookingNo].amountPaid));
    file.close();
}

int Seat::seatNoCounter = 0;

double Seat::returnCash() // returns all the revenue from this seat (from all bookings)
{
    return amountOfCash;
}

double Seat::withdrawCash()
{
    double temp = amountOfCash;
    amountOfCash = 0;
    return temp;
}

bool Seat::book(Time start, Time end, int pricePerHour, int& book) // to book a seat and switch it to occupied
{
    updateAllBookings();

    for(int i=0;i<10;i++) // checks if the time entered intersects with another booking
    {
        if(b[i].booked == 1 && ((start < b[i].startTime && end > b[i].startTime) || (start >= b[i].startTime && start < b[i].endTime) || (end > b[i].startTime && end <= b[i].endTime)))
        {
            cout << "\nThis seat is booked at this time and date. Try another." << endl;
            system("PAUSE");
            return false;
        }
    }

    for(int i=0;i<10;i++)
    {
        if(b[i].booked == 0)
        {
            b[i].booked = 1;
            b[i].startTime = start;
            b[i].endTime = end;
            if(b[i].endTime - b[i].startTime >= 1)
                b[i].amountPaid = pricePerHour*(b[i].endTime - b[i].startTime); // price increases per hour
            else
                b[i].amountPaid = pricePerHour/2; // if seat is booked for 30 minutes

            amountOfCash += b[i].amountPaid;
            
            system("cls");
            cout << "\nSeat Booked!" << endl;
            cout << "\nCollect your ticket:\n\n" << left << setw(20) << "Seat No." << left << setw(20) << "Booking No." << left << setw(20) << "Start Time" << left << setw(20) << "End Time" << "Amount Paid" << endl;
            cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n" << endl;
        
            printInfo(i);
            printInFile(i);
            // bookingNoCounter++;
            book = i;
            system("PAUSE");
            return true;
        }
    }
    
    cout << "\nCapacity for this seat is full at this time slot." << endl; // REMINDER TO PUT SOMETHING HERE TO TELL THE PROGRAM TO CHECK NEXT SEAT
    system("PAUSE");
    return false;
}

bool Seat::book(Time start, Time end, int pricePerHour, int numOfTicket, int& book) // to book a seat and switch it to occupied
{
    updateAllBookings();

    for(int i=0;i<10;i++) // checks if the time entered intersects with another booking
    {
        if(b[i].booked == 1 && ((start < b[i].startTime && end > b[i].startTime) || (start >= b[i].startTime && start < b[i].endTime) || (end > b[i].startTime && end <= b[i].endTime)))
        {
            return false;
        }
    }

    for(int i=0;i<10;i++)
    {
        if(b[i].booked == 0)
        {
            b[i].booked = 1;
            b[i].startTime = start;
            b[i].endTime = end;
            if(b[i].endTime - b[i].startTime >= 1)
                b[i].amountPaid = pricePerHour*(b[i].endTime - b[i].startTime); // price increases per hour
            else
                b[i].amountPaid = pricePerHour/2; // if seat is booked for 30 minutes

            amountOfCash += b[i].amountPaid;

            if(numOfTicket == 1)
            {
            system("cls");
            cout << "\nCollect your ticket:\n\n" << left << setw(20) << "Seat No." << left << setw(20) << "Booking No." << left << setw(20) << "Start Time" << left << setw(20) << "End Time" << "Amount Paid" << endl;
            cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n" << endl;
            }

            printInfo(i);
            printInFile(i);
            // bookingNoCounter++;

            book = i;
            return true;
        }
    }

    return false;
}

void Seat::saveSeatInfo(ofstream& outfile)
{
    outfile.write(reinterpret_cast<char*> (&b), sizeof(b));
}

void Seat::readSeatInfo(ifstream& infile)
{
    infile.read(reinterpret_cast<char*> (&b), sizeof(b));
}