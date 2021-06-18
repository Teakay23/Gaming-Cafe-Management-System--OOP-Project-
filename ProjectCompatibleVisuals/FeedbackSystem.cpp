#include"FeedbackSystem.h"
FeedbackSystem::FeedbackSystem(/* args */)
{}

ostream& operator<< (ostream& os, FeedbackSystem& TS)
{
    TS.viewFeedback();
    return os;
}

/*istream& operator>> (istream& is, FeedbackSystem& TS)
{
    TS.getFeedback();
    return is;
}*/

void FeedbackSystem::getFeedback(string name,string password)
{
    Time var = getCurrentTime();
    Person Person;
    string appliances[6] = {"Motherboard", "Cafe Fans", "Computer Screen", "Slow Internet", "Mouses and Keyboards", "Other"};
    float price[6] = {150, 100, 120, 15, 80, 0};        //To get the estimated amount, no price set for option 6
    this->name = name;
    cout << "Name: " << Person.return_name(name, password, 2) << endl;
    //cin.ignore();
    /*ag:
    cout << "Your name will not be used in any actions, it will be just used for feedback identification. Should be between 1-32 character.\nEnter your name : " << endl;
    getline(cin, name);
    if(name.length() > 32)
    {
        cout << "Name length exceeds the restriction. Please re enter the name.";
        goto ag;
    }*/

    //This is where all the checking is happening.
    again:
    cout << "Enter seat number : ";
    cin >> seat;
    if(seat < 1 || seat > 25)
    {
        cout << "This seat isn't registered. You've been redirected to enter the registered seat number again." << endl;
        system("PAUSE");
        goto again;
    }

    // Program will check if the user is inputting seats he registered and not of someone else.
    string cname;
    int cseat, c = 0, s=0;
    // ifstream confirm("FeedbackList.dat");
    // do
    // {
    //     getline(confirm, cname, '\0');
    //     confirm.read((char*) &cseat, sizeof(cseat));

    //     if(!confirm.good())
    //     break;

    //     if(cname == this->name && cseat == seat)    //if the information matched with the records, break and continue
    //     {
    //         c = 1;
    //     }
    // } while (confirm.good());
    ifstream confirm("CustomerHistory.dat", ios::binary);
    ticketInfo in;
    while(!confirm.eof())
    {
        getline(confirm, cname, '\0');

        if(confirm.eof())
            break;

        if(cname == this->name)
        {
            confirm.read(reinterpret_cast<char*> (&in), sizeof(in));
            if(seat == in.seatFile)
            {
                s = 1;
                if(var >= in.startFile && var <= in.endFile+2)
                {
                    c = 1;
                }
            }
        }
        else
        {
            confirm.seekg(sizeof(in), ios::cur);
        }
        
    }

    

    if(s == 0)  //If it does not match, it will asked to re-enter seat again and again....
    {
        cout << "The seat number you entered is not registered with your name.\nPlease enter one of the registered history.\n";
        system("PAUSE");
        goto again;
    }
    
    if(c != 0)
    {
        issue:
        cout << "If you have issues with any of these appliances, press the coresponding number :" << endl;
        for (int i = 0; i < 6 ; i++)
        {
        cout << i+1 << ". " << appliances[i] << endl;
        }
        int x;
        cin >> x;
        if(x < 1 || x > 6)
        {
            cout << "Number not registered to any action. Enter again.";
            goto issue;
        }
        Problem = appliances[x-1];
        amount = price[x-1];

        cin.ignore();
        cout << "Enter Feedback : " << endl;
        getline(cin, feedback);
        //Feedback(name, seat, feedback, appliances, price, x);
        Feedback();
    }
    else
    {
        cout << "Sorry! Your time to use this feature has been end or may not be started. Register a seat at current time to avail this feature\n";
        system("PAUSE");
    }
    
}

void FeedbackSystem::Feedback()//string name, int seat, string feedback, string *appliances, float *price, int x)
{
    ofstream input("Technical Feedback.dat", ios::app);
    /*input.write((char*) &*this, sizeof(*this));
    input.close();*/
    input.write(name.c_str(), name.length()+1);
    input << seat;
    input.write(Problem.c_str(), Problem.length()+1);
    input << amount;
    input.write(feedback.c_str(), feedback.length()+1);
    input.close();
}

float FeedbackSystem::viewFeedback()
{
    int c=1;
    float Tprice;
    ifstream output("Technical Feedback.dat", ios::out);
    cout << endl << "\t\t\t\t\t\t\t\t\tFeedback View" << endl;   
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    /*output.read((char*) &*this, sizeof(*this))*/
    do{
        getline(output, name, '\0');
        output >> seat;
        getline(output, Problem, '\0');
        output >> amount;
        Tprice += amount;
        getline(output, feedback, '\0');
        if(!output.good())
        break;
        /*cout << "Name : " << name << endl;
        cout << "Seat # " << seat << endl;
        cout << "Specified product : " << Problem << endl << "Estimated amount : " << amount << endl;
        cout << "Feedback :" << endl << feedback << endl;*/
        cout << left << setw(3)<<setfill(' ') << c << ". "  << "Name : " << left << setw(32) <<setfill(' ')<< name /*<< setw(25) << setfill(' ')*/ << "Seat : " << left << setw(25)<<setfill(' ') << seat /*<< setw(25) << setfill(' ')*/ << "Appliance : " << left << setw(46)<<setfill(' ') << Problem << "Price : " << amount << endl;
        //cout << c << ". "  << "Name : " << name << "        " << "Seat : " << seat << "        " << "Appliance : " << Problem << "         " << "Price : " << amount << endl;
        cout << "Feedback : " << endl << feedback << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        c++;
    }
    while(output.good());
    output.close();
    cout << "Enter 1 if you want Filtered feedback OR any other number if you want to skip. ";
    int ch;
    cin >> ch;
    if(ch == 1)
    {
        FilteredFeedback();
    }
    return Tprice;
    cout<<right;
}

void FeedbackSystem::FilteredFeedback()
{
    int choice, c=1;
    cout << "Enter the number of criteria you want to filter the feedback.\n1.Seat\t\t2.Appliance." << endl;
    cin >> choice;
    if(choice == 1)
    {
        int s;
        cc:
        cout << "Enter seat number (1-25) : ";
        cin >> s;
        if(seat < 1 || seat >25)
        {
            cout << "Seat not registered, Please re-enter";
            goto cc;
        }
        ifstream output("Technical Feedback.dat", ios::out);
        cout << endl << "\t\t\t\t\t\t\t\t\tFeedback View" << endl << "\t\t\t\t\t\t\t\t\t\tFiltered with seats" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;              
        do{
            getline(output, name, '\0');
            output >> seat;
            getline(output, Problem, '\0');
            output >> amount;
            getline(output, feedback, '\0');
            if(!output.good())
            break;

            if(seat == s)
            {
                cout << left << setw(3) << c << ". "  << "Name : " << left << setw(32) << name /*<< setw(25) << setfill(' ')*/ << "Seat : " << left << setw(25) << seat /*<< setw(25) << setfill(' ')*/ << "Appliance : " << left << setw(46) << Problem << "Price : " << amount << endl;
                cout << "Feedback : " << endl << feedback << endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                c++;
            }
        }
        while(output.good());
        output.close();
        cout<<right;
    }
    else if(choice == 2)
    {
        int app;
        string specify[6] = {"Motherboard", "Cafe Fans", "Computer Screen", "Slow Internet", "Mouses and Keyboards", "Other"};
        aa:
        cout << "Enter the corresponding number to select an appliance : " << endl;
        for(int i=0 ; i < 6 ; i++)
        {
            cout << i+1 << ". " << specify[i] << endl;
        }
        cin >> app;
        if(app < 1 || app > 6)
        {
            cout << "No appliances registered at this number, Please re-enter.";
            goto aa;
        }
        app=app-1;
        ifstream output("Technical Feedback.dat", ios::out);
        cout << endl << "\t\t\t\t\t\t\t\t\tFeedback View" << endl << "\t\t\t\t\t\t\t\t\t\tFiltered With Appliances" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;    
        do{
            getline(output, name, '\0');
            output >> seat;
            getline(output, Problem, '\0');
            output >> amount;
            getline(output, feedback, '\0');
            if(!output.good())
            break;

            if(Problem == specify[app])
            {
                cout << left << setw(3) << c << ". "  << "Name : " << left << setw(32) << name /*<< setw(25) << setfill(' ')*/ << "Seat : " << left << setw(25) << seat /*<< setw(25) << setfill(' ')*/ << "Appliance : " << left << setw(46) << Problem << "Price : " << amount << endl;
                cout << "Feedback : " << endl << feedback << endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                c++;
            }
        }
        while(output.good());
        output.close();
        cout<<right;
    }
}

FeedbackSystem::~FeedbackSystem()
{}

// int main()
// {
//     FeedbackSystem t;
//     t.getFeedback("Tiger");
//     //t.getFeedback("Superman");
//     cout << t;
// }