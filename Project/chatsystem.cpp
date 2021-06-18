#include"chatsystem.h"
void ChatSystem::getinfo(string name)
{
    system("cls");
    Time var = getCurrentTime();
    string check;
    int check_s, match_s = 0;
    int match = 0;
    if(s_seat == 0 || name != this->name || func_value == 1)
    {
        enter:
        cout << "Name : " << name << endl;
        cout << "Please enter your seat number : ";
        cin >> check_s;
        // blocker[0] = 0;
        for(int i=0 ; i<16 ; i++)
        {
            blocker[i] = 0;
        }
        func_value = 0;
        // if(name != this->name)
        // {
        //     clearfiles(check_s);
        // }
    }

    ifstream infile("CustomerHistory.dat", ios::binary);
    ticketInfo in;
    while(!infile.eof())
    {
        getline(infile, check, '\0');
        
        if(infile.eof())
            break;

        if(check == name)
        {
            infile.read(reinterpret_cast<char*> (&in), sizeof(in));
            if(check_s == in.seatFile)
            {
                match_s = 1;
                if(var >= in.startFile && var <= in.endFile)
                {
                    match = 1;
                    this->name = name;
                    s_seat = check_s;
                    clearfiles_support();
                }
            }
        }
        else
        {
            infile.seekg(sizeof(in), ios::cur);
        }
    }
    infile.close();

    if(match_s == 0)
    {
        cout << "This seat is not registered by your name, please enter a seat registered by your name.";
        system("PAUSE");
        system("cls");
        goto enter;
    }
    if(match_s == 1 && match == 0)
    {
        checkvalidity(name, check_s);
        system("PAUSE");
        system("cls");
    }
    else if(match == 1)
    {
        actions();
    }
    system("PAUSE");
}

void ChatSystem::checkvalidity(string name, int check_s)        //this function was doing its work solely until a problem occurs now, its just used to print.
{
    string check;
    Time var = getCurrentTime();
    ifstream infile("CustomerHistory.dat", ios::binary);
    ticketInfo in;
    cout << "SORRY ! Your time to use this feature has been ended or maybe not started. Register yourself at current time to use this feature.\n";
    cout << "The timings (may contain more than 1) to use this feature are as follows : \n\n";
    while(!infile.eof())
    {
        getline(infile, check, '\0');
        
        if(infile.eof())
            break;

        if(check == name)
        {
            infile.read(reinterpret_cast<char*> (&in), sizeof(in));
            if(check_s == in.seatFile)
            {
                if(var < in.startFile || var > in.endFile)
                {
                    cout << "Time : " << in.startFile << "  -  " << in.endFile << endl << endl;
                }
            }
        }
        else
        {
            infile.seekg(sizeof(in), ios::cur);
        }
    }
    // clearfiles(check_s);
    infile.close();
}

void ChatSystem::clearfiles_support()
{
    int temp_s, from, flag_up = 0;
    string temp_name, temp_mes;
    string seats[25] = {"Seat1.dat", "Seat2.dat", "Seat3.dat", "Seat4.dat", "Seat5.dat", "Seat6.dat", "Seat7.dat", "Seat8.dat", "Seat9.dat", "Seat10.dat", "Seat11.dat", "Seat12.dat", "Seat13.dat", "Seat14.dat", "Seat15.dat", "Seat16.dat", "Seat17.dat", "Seat18.dat", "Seat19.dat", "Seat20.dat", "Seat21.dat", "Seat22.dat", "Seat23.dat", "Seat24.dat", "Seat25.dat"};
    ifstream cr;
    cr.open(seats[s_seat-1], ios::in);
    if(cr.is_open())
    {
        while(!cr.eof())
        {
            cr >> temp_s;
            getline(cr, temp_name, '\0');
            cr >> from;
            getline(cr, temp_mes, '\0');
            if(cr.eof())
                break;

            if(temp_s == 1 && temp_name != name)
            {
                // clearfiles(s_seat);
                flag_up = 1;
            }
        }
        cr.close();
    }
    
    if(flag_up == 1)
        clearfiles(s_seat);
}

void ChatSystem::clearfiles(int check_s)
{
    string seats[25] = {"Seat1.dat", "Seat2.dat", "Seat3.dat", "Seat4.dat", "Seat5.dat", "Seat6.dat", "Seat7.dat", "Seat8.dat", "Seat9.dat", "Seat10.dat", "Seat11.dat", "Seat12.dat", "Seat13.dat", "Seat14.dat", "Seat15.dat", "Seat16.dat", "Seat17.dat", "Seat18.dat", "Seat19.dat", "Seat20.dat", "Seat21.dat", "Seat22.dat", "Seat23.dat", "Seat24.dat", "Seat25.dat"};
    ofstream clr;
    clr.open(seats[check_s-1], ios::out | ios::trunc);
    clr.close();
    actions();
}

void ChatSystem::actions()
{
    system("cls");
    //Time var= getCurrentTime();         //will have to still work with those
    //cout << var;
    cout << "\t\t\t\t\t\t\tWELCOME TO MESSAGE CENTER" << endl << endl;
    choose_again:
    cout << "1.Send Message.\n2.View Messages.\n3.Blocker.\n4.Change seat(only for same user names).\n5.Delete all recieved messages(TIP:Use if your inbox is filled with so much messages.)\n6.Exit.\n";
    int choose;
    cin >> choose;

    if(choose == 1)
    {
        system("cls");
        sendmessage();
    }
    else if(choose == 2)
    {
        recievemessage();
        actions();
    }
    else if(choose == 3)
    {
        block();
        actions();
    }
    else if(choose == 4)
    {
        func_value = 1;
        getinfo(name);
    }
    else if(choose == 5)
    {
        clearfiles(s_seat);
    }
    else if(choose == 6)
    {
        return;
    }
    else
    {
        cout << "No action registered to this number.TRY a registered number" << endl;
        system("PAUSE");
        goto choose_again;
    }
    
}

void ChatSystem::sendmessage()
{
    Time var = getCurrentTime();
    int choice, seatcheck, con, match_receiver = 0;
    string c;
    method:
    cout << "Please select a way.\n1.By seat.\n2.Back to action center." << endl;
    cin >> choice;

    if(choice == 2)
    {
        actions();
    }
    if(choice == 1)
    {
        enter_seat:
        cout << "Enter seat number(1-25) : ";
        cin >> seatcheck;
        if(seatcheck < 1 || seatcheck > 25)
        {
            cout << "Seat numbers are invalid.TRY a valid seat";
            system("PAUSE");
            goto enter_seat;
        }
        ifstream infile("CustomerHistory.dat", ios::binary);
        ticketInfo in;
        while(!infile.eof())
        {
            getline(infile, c, '\0');
            infile.read(reinterpret_cast<char*> (&in), sizeof(in));
            if(infile.eof())
                break;
            
            if(seatcheck == in.seatFile)
            {
                if(var >= in.startFile && var <= in.endFile)
                {
                    match_receiver = 1;
                    cout << "The username in this seat is : " << c << endl << "Press 1 to confirm or any other number to show different options." << endl;
                    cin >> con;

                    if(con == 1)
                    {
                        r_seat = seatcheck;
                        cout << "Enter message to seat # " << r_seat << " : " << endl;
                        cin.ignore();
                        getline(cin, message);
                        writingprocedure();                         //function for the prcedure to send message.
                        actions();
                    }
                    else
                    {
                        regis:
                        cout << "Press 1 to re enter seat number or 2 to use another method.";
                        int a;
                        cin >> a;
                        if(a == 1)
                        {
                            goto enter_seat;
                        }
                        else if(a == 2)
                        {
                            goto method;
                        }
                        else
                        {
                        cout << "Number not registered to any action. Try entering a registered number.";
                        system("PAUSE");
                        goto regis;
                        }
                    }    
                }
            }
        }
    }
    if(match_receiver == 0)
    {
        cout << "There are currently no seats available in the seats at that time." << endl;
        system("PAUSE");
        actions();
    }
}

void ChatSystem::writingprocedure()     //This function is writing messages and also in a way to make a history of chats
{
    ofstream out;
    int sender=1;       // A flag to recognize who is the sender and reciever.
    string seats[25] = {"Seat1.dat", "Seat2.dat", "Seat3.dat", "Seat4.dat", "Seat5.dat", "Seat6.dat", "Seat7.dat", "Seat8.dat", "Seat9.dat", "Seat10.dat", "Seat11.dat", "Seat12.dat", "Seat13.dat", "Seat14.dat", "Seat15.dat", "Seat16.dat", "Seat17.dat", "Seat18.dat", "Seat19.dat", "Seat20.dat", "Seat21.dat", "Seat22.dat", "Seat23.dat", "Seat24.dat", "Seat25.dat"};
    out.open(seats[s_seat-1], ios::app);
    out << sender;
    out.write(name.c_str(), name.length()+1);
    out << r_seat;
    out.write(message.c_str(), message.length()+1);
    out.close();

    sender = 0;
    out.open(seats[r_seat-1], ios::app);
    out << sender;
    out.write(name.c_str(), name.length()+1);
    out << s_seat;
    out.write(message.c_str(), message.length()+1);
    out.close();
    cout << "Message sent." << endl;
}

void ChatSystem::recievemessage()
{
    system("cls");
    int sender, from, checkblock=0;
    string tempname, tempmessage;
    ifstream infile;
    string seats[25] = {"Seat1.dat", "Seat2.dat", "Seat3.dat", "Seat4.dat", "Seat5.dat", "Seat6.dat", "Seat7.dat", "Seat8.dat", "Seat9.dat", "Seat10.dat", "Seat11.dat", "Seat12.dat", "Seat13.dat", "Seat14.dat", "Seat15.dat", "Seat16.dat", "Seat17.dat", "Seat18.dat", "Seat19.dat", "Seat20.dat", "Seat21.dat", "Seat22.dat", "Seat23.dat", "Seat24.dat", "Seat25.dat"};
    cout << "\t\t\t\t\t\t\t\t\tMessage Box\n";
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

    infile.open(seats[s_seat-1]);
    infile.seekg(0);
    while(!infile.eof())
    {
        infile >> sender;
        getline(infile, tempname, '\0');
        infile >> from;
        getline(infile, tempmessage, '\0');
        if(infile.eof())
            break;

        if(sender == 1)
        {
            cout << "To Seat : " << from << endl;
            cout << "Message : " << endl << tempmessage << endl << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        }
        if (sender == 0)
        {
            for(int i=1 ; i<16 ; i++)
            {
                if(blocker[0] == s_seat && from == blocker[i])
                {    
                    checkblock =1;
                }
            }
            if(checkblock == 0)
            {
                cout << "From Seat : " << left << setw(70) << from  << "\t\t\tSender Name : " << tempname << endl;
                cout << "Message : " << endl << tempmessage << endl << endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
            }
        }
    }
    infile.close();
    system("PAUSE");
    cout << right;
}

void ChatSystem::block()
{
    int input, choose, already = 0;
    if(c == 0)
    {
        for(int i=0 ; i<16 ; i++)
        {
            if(i == 0)
            {
                blocker[i] = s_seat;
            }
            else
            {
                blocker[i] = 0;
                c=1;   
            }
        }
    }
    system("cls");
    cout << "Select a corresponding action.\n1.Block a seat.\n2.Unblock a seat.\n";
    cin >> choose;
    system("cls");
    switch (choose)
    {
    case 1:
        input_again:
        cout << "\nNOTE: YOU CAN NOT BLOCK THE SEAT THAT YOU ARE OCCUPYING AND USING TO TAKE ACTIONS (TIP: be a friend of yourself).\nINFO: You can not block more than 15 seats.\n\nEnter the seat number you want to block. You will not recieve any messages from them until you unblock them." << endl;        cin >> input;
        if(input < 1 || input > 25)
        {
            cout << "Unregistered seat. TRY again.";
            system("PAUSE");
            goto input_again;
        }
        if(input == s_seat)
        {
            cout << "You entered your seat. Please enter another seats." << endl;
            system("PAUSE");
            goto input_again;
        }
        for(int i=1 ; i<16 ; i++)
        {
            if(blocker[i] == input)
            {
                cout << "The number is already in a blocked seat\n";
                already = 1;
            }
        }
        if(count <=15)
        {
            if(already != 1)
            {
                for(int i=count-1 ; i<count ; i++)
                {
                    blocker[i] = input;
                }
                count++;
                cout << "Number blocked\n";
            }
        }
        else
        {
            cout << "Block limit reached, unblock a seat then try again." << endl;
        }
        system("PAUSE");
        break;
    
    case 2:
        cout << "Here are your blocked seat numbers: \n";
        for(int i=1 ; i<16 ; i++)
        {
            if(blocker[i] != 0)
            cout << blocker[i] << "  ";
        }
        cout << endl << "NOTE: The seat will be blocked until you logged out from the chat system. \nINFO: If you enter a number that is not in the block list, just press any number then continue and the program will continue normally.\n\nEnter the number from one of those to unblock." << endl;
        cin >> input;
        for(int i=1 ; i<16 ; i++)
        {
            if(blocker[i] == input)
            {
                for(int j=i ; j<16  ; j++)
                {
                    if(j!=15)
                        blocker[j] = blocker[j+1];
                    if(j==15)
                        blocker[j]=0;
                }
                count--;
                cout << "Number unblocked" << endl;
            }
        }
        system("PAUSE");
        break;
    
    default:
        break;
    }
}

// int main()
// {
//     ChatSystem cs;
//     //cs.getinfo("SaudBody69");
//     cs.getinfo("AliMomina");
// }