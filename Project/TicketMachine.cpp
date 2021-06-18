#include "TicketMachine.h"

void TicketMachine::enterTiming()
{
    int hr, in, i=0;

    system("cls");
    cout << "\nBook ticket(s) for:\n\n1. Current time\n2. Custom Time\n\nEnter a number: ";
    cin >> in;
   
    switch(in)
    {
        case 1:
            start = getCurrentTime();
            break;     
        case 2: //(NEEDS EXCEPTION HANDLING)
            cout << "\nEnter the date of booking in format [DD/MM/YYYY]: "; 
            cin >> start.date;

            cout << "\nEnter the time of booking in format [HH:MM]: ";
            cin >> start;

            break;
        default:
            cout << "\nInput Invalid." << endl;
            system("PAUSE");
            enterTiming();
            return;
    }

    if(start < getCurrentTime())
    {
        cout << "\nTime slot invalid. Please try again." << endl;
        system("PAUSE");
        enterTiming();
        return;
    }

    while(1)
    {
        cout << "\nEnter the number of hours of booking [max 5 hours]: "; // NEEDS EXCEPTION HANDLING
        cin >> hr;

        if(hr > 5 || hr < 1)
        {
            cout << "\nMaximum number of hours exceeded. Please try again." << endl;
            continue;
        }

        break;
    }


    end = start + hr;
    system("cls");
}

void TicketMachine::enterSeatInfo() //NEEDS EXCEPTION HANDLING
{
    system("cls");
    cout << "\nEnter Seat number: ";
    cin >> seatNo;
    cout << "\nEnter Booking number: ";
    cin >> bookingNo;
}

void::TicketMachine::viewTicketInfo()
{
    enterSeatInfo();

    system("cls");
    cout << "\n" << left << setw(20) << "Seat No." << left << setw(20) << "Booking No." << left << setw(20) << "Start Time" << left << setw(20) << "End Time" << "Amount Paid" << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n" << endl;
    seats[seatNo-1].printInfo(bookingNo-1);
    system("PAUSE");
}

void TicketMachine::checkPricing()
{
    system("cls");
    cout << "\nOur cafe offers internet and media services at affordable prices. All prices are on *per hour* basis:"
    "\n\nBase Price: " << basePricePerHour << "/Hr" << endl <<
    "Price with Premium Account: " << basePricePerHour-(basePricePerHour*0.1) << "/Hr" << endl <<
    "\nAdditional Premium Service Charges:\n\nVPN: +20/Hr\nGaming: +50/Hr" << endl;
    system("PAUSE");
}