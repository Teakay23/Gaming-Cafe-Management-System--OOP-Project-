#include "TicketManagement.h"

void TicketManagement::checkDayBookings()
{
    Time st, en;
    Date input, current;
    int sN, bN, amnt, totalAmount=0;

    system("cls");
    cout << "\nEnter the date you want the ticket records of in format [DD/MM/YYYY]: ";
    cin >> input;

    system("cls");
    cout << left << setw(20) << "Seat No." << left << setw(20) << "Booking No." << left << setw(20) << "Start Time" << left << setw(20) << "End Time" << "Amount Paid" << endl;
    cout << "- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -\n" << endl;
    
    ifstream infile("BinaryBookings.bin");

    while(!infile.eof())
    {
        infile.read((char *) (&current), sizeof(current));

        if(current == input)
        {
            if(infile.eof())
                break;

            infile.read((char*) (&sN), sizeof(sN));
            infile.read((char*) (&bN), sizeof(bN));
            infile.read((char*) (&st), sizeof(st));
            infile.read((char*) (&en), sizeof(en));
            infile.read((char*) (&amnt), sizeof(amnt));

            cout << "SN#" << left << setw(3) << sN << "              " << left << setw(2) << bN << "                  " << st << "   " << en << "   " << left << setw(5) << amnt;

            if(amnt < 0)
                cout << " (CANCELLATION TICKET)" << endl;
            else
                cout << endl;
            
            totalAmount += amnt;
        }
        else
        {
            if(infile.eof())
                break;

            infile.seekg(sizeof(sN)+sizeof(bN)+sizeof(st)+sizeof(en)+sizeof(amnt), ios::cur);
        }
    }

    cout << "\nTotal amount paid for the above tickets: " << totalAmount << endl;
    cout<<right;
    system("PAUSE");
}

void TicketManagement::checkMonthBookings()
{
    Time st, en;
    Date input, current;
    int sN, bN, amnt, mn, yr, totalAmount=0;

    system("cls");
    cout << "\nEnter the month number: ";
    cin >> mn;
    cout << "\nEnter the year: ";
    cin >> yr;

    input.setDate(1,mn, yr);

    system("cls");
    cout << "\nDate of Booking     Seat No.            Booking No.         Start Time          End Time            Amount Paid" << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- \n" << endl;
    
    ifstream infile("BinaryBookings.bin");

    while(!infile.eof())
    {
        infile.read((char *) (&current), sizeof(current));

        if(current.compareMonth(input))
        {
            if(infile.eof())
                break;

            infile.read((char*) (&sN), sizeof(sN));
            infile.read((char*) (&bN), sizeof(bN));
            infile.read((char*) (&st), sizeof(st));
            infile.read((char*) (&en), sizeof(en));
            infile.read((char*) (&amnt), sizeof(amnt));

            cout << current << "          " << "SN#" << left << setw(3) << sN << "              " << left << setw(2) << bN << "                  " << st << "   " << en << "   " << left << setw(5) << amnt;

            if(amnt < 0)
                cout << " (CANCELLATION TICKET)" << endl;
            else
                cout << endl;

            totalAmount += amnt;
        }
        else
        {
            if(infile.eof())
                break;

            infile.seekg(sizeof(sN)+sizeof(bN)+sizeof(st)+sizeof(en)+sizeof(amnt), ios::cur);
        }
    }

    cout << "\nTotal amount paid for the above tickets: " << totalAmount << endl;
    cout<<right;
    system("PAUSE");    
}

void TicketManagement::checkAllBookings()
{
    string s1;
    ifstream infile("SeatBookings.txt");

    system("cls");
    cout << "\nFollowing is the history of all tickets booked in our cafe:\n" << endl;

    while(!infile.eof())
    {
        getline(infile, s1, '\n');
        cout << s1 << endl;
    }
    system("PAUSE");
}

void TicketManagement::cancelTicket() // this will need exception handling
{
    int seatNo, bookingNo;

    system("cls");
    cout << "\nEnter Seat number of ticket you wish to cancel: " << endl;
    cin >> seatNo;

    cout << "\nEnter Booking number of ticket you wish to cancel: " << endl;
    cin >> bookingNo;
    system("cls");

    seats[seatNo-1].cancelBooking(bookingNo-1);
    saveAllSeatInfo();
    system("PAUSE");
}

void TicketManagement::withdrawAllCash()
{
    Time current = getCurrentTime();
    int totalAmount=0;

    for(int i=0; i<numSeats; i++)
    {
        totalAmount += seats[i].withdrawCash();
    }

    ofstream outfile("MoneyWithdrawn.bin", ios::app | ios::binary);
    outfile.write(reinterpret_cast<char*> (&current), sizeof(current));
    outfile.write(reinterpret_cast<char*> (&totalAmount), sizeof(totalAmount));
    outfile.close();

    system("cls");
    cout << "\nAll cash has been collected and an entry has been added in the records." << endl;
    system("PAUSE");
}

void TicketManagement::checkWithdrawHistory()
{
    Time timeOfWithdarwal;
    int amnt;

    system("cls");
    cout << "\nFollowing is the withdrawal history:\n\n";
    cout << "Time of withdrawal      Amount" << endl;
    cout << "------------------------------\n" << endl;

    ifstream infile("MoneyWithdrawn.bin");

    while(!infile.eof())
    {
        if(infile.eof())
            break;

        infile.read((char*) (&timeOfWithdarwal), sizeof(timeOfWithdarwal));
        infile.read((char*) (&amnt), sizeof(amnt));

        if(infile.eof())
            break;

        cout << timeOfWithdarwal << "       " << amnt << endl;
    }

    infile.close();
    system("PAUSE");
}