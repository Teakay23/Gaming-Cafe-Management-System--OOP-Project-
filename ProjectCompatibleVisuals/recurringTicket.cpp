#include "recurringTicket.h"

recurringTicket::recurringTicket(): pricePerHour(basePricePerHour-(basePricePerHour*0.1)), discountCounter(0)
{}

void recurringTicket::inputUsername(string u_name)
{
    username = u_name;
}

void recurringTicket::bookTicket()
{
    int numTicket,i,j,price, bookNum, totalAmount=0, sCounter=0;
    Time current = getCurrentTime();

    system("cls");
    cout << "\nEnter the number of seats you want to book [max 10 seats per ticket]: ";
    cin >> numTicket;

    if(numTicket > 10)
    {
        cout << "\nMaximum number of seats you can book at once is 10." << endl;
        system("PAUSE");
        bookTicket();
        return;
    }
    if(numTicket < 1)
    {
        cout << "\nInput invalid!" << endl;
        system("PAUSE");
        bookTicket();
        return;
    }

    price = additionalServices();
    if(discountChecker())
        price -= 10;

    enterTiming();
    
    for(i=0; i<numTicket; i++)
    {
        for(j=0; j<numSeats ; j++)
        {
            if(seats[j].book(start, end, price, i+1, bookNum))
            {
                discountCounter++;
                totalAmount += price;
                sCounter++;

                ticketInfo in(current.date, start, end, price*(end-start), j+1, bookNum+1);
                in.writeInfoToFile(username);

                feedbackFile(j+1);
                break;
            }
        }
    }

    cout << "\nTotal Amount Paid: " << totalAmount << endl;

    if(sCounter == 0)
    {
        cout << "\nNo seats are availabe on the specified time slot!" << endl;
        system("PAUSE");
        return;
    }
    if(sCounter < numTicket)
    {
        cout << "\nSorry! Some seat(s) are not free on the specified time slot." << endl;
        saveAllSeatInfo();
        system("PAUSE");
        return;
    }
    else
    {
        saveAllSeatInfo();
        system("PAUSE");
    }
}

void recurringTicket::bookSpecificSeat()
{
    string layout;
    int selection, price, bookNum;
    
    system("cls");
    cout << "\nFollowing is the layout of the cafe:\n\n" << endl;
    
    ifstream infile("seatLayoutAscii.txt", ios::binary);
    getline(infile, layout, 'i');
    infile.close();

    cout << layout << endl << "\n\nEnter a number corresponding to the seats in the layout to select a particular seat: ";
    cin >> selection;

    if(selection > 25 || selection < 1)
    {
        cout << "\nInput invalid!" << endl;
        system("PAUSE");
        bookSpecificSeat();
        return;
    }

    price = additionalServices();
    if(discountChecker())
    {    price -= 10;}

    enterTiming();

    
    if(seats[selection-1].book(start, end, price, bookNum))
    {
        Time current = getCurrentTime();
        discountCounter++;

        ticketInfo in(current.date, start, end, price*(end-start), selection, bookNum+1);
        in.writeInfoToFile(username);
        
        feedbackFile(selection);
        saveAllSeatInfo();
    }
}

void recurringTicket::cancelTicket() // will need exception handling
{
    Time check;
    int cancel = 0;
    string u_name;
    Date currentDate;
    ticketInfo in;

    system("cls");
    cout << "\nKindly refer to your ticket and note down the Seat No., Booking No. and Start Time of the booking you wish to cancel. These will be required for cancellation of your ticket." << endl;
    system("PAUSE");

    enterSeatInfo();

    system("cls");
    cout << "\nEnter the day on which the booking was supposed to start [DD/MM/YYYY]: "; //NEEDS EXCEPTION HANDLING
    cin >> check.date;
    cout << "\nEnter the time at which the booking was supposed to start [HH:MM]: ";
    cin >> check;
    // cout << check << endl;
    system("cls");

    ifstream infile("CustomerHistory.dat", ios::binary);

    while(!infile.eof())
    {
        getline(infile, u_name, '\0');
        infile.read(reinterpret_cast<char*> (&in), sizeof(in));

        if(u_name == username && in.seatFile == seatNo && in.bookingFile == bookingNo && in.startFile == check)
        {
            cancel = 1;
            break;
        }
        
        if(infile.eof())
            break;
    }

    infile.close();

    if(cancel == 1)
    {    
        seats[seatNo-1].cancelBooking(bookingNo-1);
        discountCounter--;
        Time current = getCurrentTime();

        ticketInfo in(current.date, start, end, -1, seatNo, bookingNo);
        in.writeInfoToFile(username);

        saveAllSeatInfo();
    }
    else
        cout << "\nNo such ticket has been booked by you!" << endl;

    system("PAUSE");
}

void recurringTicket::checkBookingHistory()
{
    string u_name;
    int seatNumber, bookingNumber, p;
    Time startingTime, endingTime;
    Date currentDate;

    system("cls");
    cout << "\nFollowing is the history of all tickets booked:\n" << endl;
    cout << "Date of Booking     Seat No.            Booking No.         Start Time          End Time            Amount Paid\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- " << endl;
    
    ifstream infile("CustomerHistory.dat", ios::binary);
    ticketInfo in;

    while(!infile.eof())
    {
        getline(infile, u_name, '\0');

        if(infile.eof())
            break;

        if(u_name == username)    
        {
            infile.read(reinterpret_cast<char*> (&in), sizeof(in));

            if(in.priceFile > -1)
                cout << in.currentFile << "          " << "SN#" << left << setw(3) << in.seatFile << "              " << left << setw(2) << in.bookingFile << "                  " << in.startFile << "   " << in.endFile << "   " << left << setw(2) << in.priceFile << endl;
            if(in.priceFile == -1)
                cout << in.currentFile << "          " << "SN#" << left << setw(3) << in.seatFile << "              " << left << setw(2) << in.bookingFile << "                  " << in.startFile << "   " << in.endFile << "   *CANCELLATION TICKET*" << endl;
        }
        else
        {
            infile.seekg(sizeof(in), ios::cur);
        }
        
    }

    infile.close();
    cout<<right;
    system("PAUSE");
}

int recurringTicket::additionalServices()
{
    int in;

    system("cls");
    cout << "\nAdditional premium servies:\n\n1. VPN (+20/Hr)\n2. Gaming (+50/Hr)\n3. Skip\n\nEnter a number: ";
    cin >> in;

    switch(in)
    {
        case 1:
            return pricePerHour + 20;
            break;
        case 2:
            return pricePerHour + 50;
            break;
        case 3:
            return pricePerHour;
        default:
            cout << "\nInput invalid! Try again." << endl;
            system("PAUSE");
            pricePerHour = additionalServices();
            return pricePerHour;
            break;
    }
}

bool recurringTicket::discountChecker()
{
    if(discountCounter >= 5)
    {
        discountCounter = 0;
        return true;
    }
    else
        return false;
}

void recurringTicket::feedbackFile(int seatNumber)
{
    ofstream outfile("FeedbackList.dat", ios::app);

    outfile.write(username.c_str(), username.length()+1);
    outfile.write(reinterpret_cast<char*> (&seatNumber), sizeof(seatNumber));

    outfile.close();
}