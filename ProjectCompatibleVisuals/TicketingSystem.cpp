#include "TicketingSystem.h"

Seat TicketingSystem::seats[numSeats];

TicketingSystem::TicketingSystem():basePricePerHour(100)
{}

void TicketingSystem::viewTicketInfo() //NEEDS EXCEPTION HANDLING
{
    system("cls");
    int seatNo, bookingNo;

    cout << "\nEnter Seat number: ";
    cin >> seatNo;
    cout << "\nEnter Booking number: ";
    cin >> bookingNo;

    system("cls");
    cout << left << setw(20) << "Seat No." << left << setw(20) << "Booking No." << left << setw(20) << "Start Time" << left << setw(20) << "End Time" << "Amount Paid" << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n" << endl;
     
    seats[seatNo-1].printInfo(bookingNo-1);
    system("PAUSE");
}

void TicketingSystem::saveAllSeatInfo()
{
    ofstream outfile("SeatInfo.dat", ios::binary);

    for(int i=0; i<numSeats; i++)
    {
        seats[i].saveSeatInfo(outfile);
    }

    outfile.close();
}

void TicketingSystem::readAllSeatInfo()
{
    ifstream infile("SeatInfo.dat", ios::binary);

    for(int i=0; i<numSeats; i++)
    {
        seats[i].readSeatInfo(infile);
    }

    infile.close();
}