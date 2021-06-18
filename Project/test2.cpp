#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
#include "Time.h"
#include <ctime>
#include <stdlib.h>
#include "TicketingSystem.h"
#include "oneTimeTicket.h"
#include "recurringTicket.h"
#include "TicketManagement.h"

int main()
{
    recurringTicket RT;
    RT.readAllSeatInfo();
    // first customer logged in
    RT.inputUsername("Unas Ahmed");
    RT.bookSpecificSeat();
    RT.checkBookingHistory();
    RT.bookTicket();
    RT.cancelTicket();
    RT.checkBookingHistory();
    // second customer logged in
    RT.inputUsername("SaudBody69");
    cout << "saudbody logged in" << endl; system("PAUSE");
    RT.checkBookingHistory();
    RT.bookTicket();
    RT.cancelTicket();
    RT.checkBookingHistory();
    // first customer logged in again cuz saud doesn't believe that i'm the greatest human/genius of all time but i'll show him
    RT.inputUsername("Unas Ahmed");
    RT.checkBookingHistory();
    RT.bookTicket();
    RT.cancelTicket();
    RT.checkBookingHistory();
    //when exiting the program
    RT.saveAllSeatInfo();

    return 0;
}

// struct test
// {
//     int a=10;
//     char b='B';
//     Time t;
// };

// struct test2
// {
//     test T[10];
// };

// void mynamejeff(ofstream& outfile, int num)
// {
//     test c[10];
//     if(num==1)
//     {
//         for(int i=0; i<10; i+=2)
//         {
//             c[i].t.setTimeAndDate(22,21,17,5,2020);
//             c[i+1].t.setTimeAndDate(21,20,16,4,2019);
//         }
//     }
//     else
//     {
//         for(int i=0; i<10; i+=2)
//         {
//             c[i].t.setTimeAndDate(1,2,22,6,2021);
//             c[i+1].t.setTimeAndDate(2,3,7,6,2022);
//         }
//     }
    
//     outfile.write(reinterpret_cast<char*> (&c), sizeof(c));
// }

// void mynamejeff2(ifstream& infile)
// {
//     test c[10];
//     infile.read(reinterpret_cast<char*> (&c), sizeof(c));

//     for(int i=0; i<10; i++)
//     {
//         cout << c[i].a << endl << c[i].b << endl << c[i].t << endl;
//     }
//     cout << endl;
// }

// int main()
// {
//     ofstream outfile("TestingOutfile.dat", ios::binary);
//     mynamejeff(outfile, 1);
//     mynamejeff(outfile, 2);
//     outfile.close();

//     ifstream infile("TestingOutfile.dat", ios::binary);
//     mynamejeff2(infile);
//     // mynamejeff2(infile);
//     outfile.close();
// }

//     int cancel=0;
//     {
//     string u_name, username = "Umer Ahmed";
//     int seatComp, bookComp, p, seatNo = 23, bookingNo = 1;
//     Time timeComp, endComp, check(0,49,17,5,2020);
//     Date currentDate;

//     ifstream infile("CustomerHistory.dat");
//     int i=1;
//     while(!infile.eof())
//     {
//         getline(infile, u_name, '\0');
//         cout << infile.tellg() << endl;
//         infile.read((char*) &currentDate, sizeof(currentDate));
//         cout << infile.tellg() << endl;
//         infile.read((char*) &seatComp, sizeof(seatComp));
//         cout << infile.tellg() << endl;
//         infile.read((char*) &bookComp, sizeof(bookComp));
//         cout << infile.tellg() << endl;
//         infile.read((char*) &timeComp, sizeof(timeComp));
//         cout << infile.tellg() << endl;
//         cout << i << u_name << endl << seatComp << endl << bookComp << endl << timeComp << endl;

//         if(u_name == username && seatComp == seatNo && bookComp == bookingNo && timeComp == check)
//         {
//             cancel = 12;
//             break;
//         }
//         else
//         {
//             cout << "entered elsebruh" << endl;
//             infile.read((char*) &endComp, sizeof(endComp));
//             cout << infile.tellg() << endl;
//             infile.read((char*) &p, sizeof(p));
//             cout << infile.tellg() << endl;
//             if(infile.eof())
//             {
//                 cout << "breaking from else" << endl;
//                 break;
//             } 
//         }
        
//     }

//     infile.close();
//     }

//     cout << "\nCancel = " << 12 << endl;

//     {
//         string u_name, username = "Umer Ahmed";
//     int seatNumber, bookingNumber, p;
//     Time startingTime, endingTime;
//     Date currentDate;

//     system("cls");
//     cout << "\nFollowing is the history of all tickets booked:\n" << cancel << "\n" << endl;
//     cout << "Date of Booking     Seat No.            Booking No.         Start Time          End Time            Amount Paid\n-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- " << endl;
    
//     ifstream infile("CustomerHistory.dat");

//     while(!infile.eof())
//     {
//         getline(infile, u_name, '\0');

//         if(infile.eof())
//             break;

//         if(u_name == username)    
//         {
//             infile.read((char*) &currentDate, sizeof(currentDate));
//             infile.read((char*) &seatNumber, sizeof(seatNumber));
//             infile.read((char*) &bookingNumber, sizeof(bookingNumber));
//             infile.read((char*) &startingTime, sizeof(startingTime));
//             infile.read((char*) &endingTime, sizeof(endingTime));
//             infile.read((char*) &p, sizeof(p));

//             if(p > -1)
//                 cout << currentDate << "          " << "SN#" << left << setw(3) << seatNumber << "              " << left << setw(2) << bookingNumber << "                  " << startingTime << "   " << endingTime << "   " << left << setw(2) << p << "  "<< u_name << endl;
//             if(p == -1)
//                 cout << currentDate << "          " << "SN#" << left << setw(3) << seatNumber << "              " << left << setw(2) << bookingNumber << "                  " << startingTime << "   " << endingTime << "   *Cancellation Ticket*" << endl;
//         }
//     }

//     infile.close();
//     }
// }