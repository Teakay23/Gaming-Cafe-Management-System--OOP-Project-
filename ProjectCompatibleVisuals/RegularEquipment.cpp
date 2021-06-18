#include"RegularEquipment.h"
template<class U>
int RegularEquipment<U>::intlength(int a)
{ 
    int count=0;
    again:
    a=a/10;
    count++;
    if(a!=0)
    goto again;
    return count;
}
template<class U>
int RegularEquipment<U>::itemnamelength(U name)
{
    return name.length();
}    
template<class U>
void RegularEquipment<U>::get_data()
{
    Impartial_Tech<U>::inventory=new int[12];
    cout<<"Enter The Quantity For Each Kitchen Supplies:";
    Blenders:
    cout<<"\nBlenders:x__\b\b"; cin>>Impartial_Tech<U>::inventory[0];
    if(Impartial_Tech<U>::inventory[0]<0 || Impartial_Tech<U>::inventory[0]>10)
    goto Blenders;
    Microwaves:
    cout<<"\nMicrowaves:x__\b\b"; cin>>Impartial_Tech<U>::inventory[1];
    if(Impartial_Tech<U>::inventory[1]<0 || Impartial_Tech<U>::inventory[1]>10)
    goto Microwaves;
    Mincers:
    cout<<"\nElectronic Mincers:x__\b\b"; cin>>Impartial_Tech<U>::inventory[2];
    if(Impartial_Tech<U>::inventory[2]<0 || Impartial_Tech<U>::inventory[2]>10)
    goto Mincers;
    Fridge:
    cout<<"\nFridge Support:x__\b\b"; cin>>Impartial_Tech<U>::inventory[3];
    if(Impartial_Tech<U>::inventory[3]<0 || Impartial_Tech<U>::inventory[3]>10)
    goto Fridge;
    clear;
    cout<<"\nEnter the Quantity of each Customer-Tailored Cubicle Tech Support:";
    Dispenser:
    cout<<"\nDispensers:x__\b\b"; cin>>Impartial_Tech<U>::inventory[4];
    if(Impartial_Tech<U>::inventory[4]<0 || Impartial_Tech<U>::inventory[4]>40)
    goto Dispenser;
    Personalized_Web_Cameras:
    cout<<"\nPersonalized Web Cameras:x__\b\b"; cin>>Impartial_Tech<U>::inventory[5];
    if(Impartial_Tech<U>::inventory[5]<0 || Impartial_Tech<U>::inventory[5]>40)
    goto Personalized_Web_Cameras;
    AirCon:
    cout<<"\nAir Conditioning:x__\b\b"; cin>>Impartial_Tech<U>::inventory[6];
    if(Impartial_Tech<U>::inventory[6]<0 || Impartial_Tech<U>::inventory[6]>40)
    goto AirCon;
    Clocks:
    cout<<"\nClocks:x__\b\b"; cin>>Impartial_Tech<U>::inventory[7];
    if(Impartial_Tech<U>::inventory[7]<0 || Impartial_Tech<U>::inventory[7]>40)
    goto Clocks;
    Telephones:
    cout<<"\nKitsch Telephones:x__\b\b"; cin>>Impartial_Tech<U>::inventory[8];
    if(Impartial_Tech<U>::inventory[8]<0 || Impartial_Tech<U>::inventory[8]>40)
    goto Telephones;
    Personal_Stereo:
    cout<<"\nPersonal Stereos:x__\b\b"; cin>>Impartial_Tech<U>::inventory[9];
    if(Impartial_Tech<U>::inventory[9]<0 || Impartial_Tech<U>::inventory[9]>40)
    goto Personal_Stereo;
    
    clear;
    cout<<"\nEnter the Quantity of each Security-Tailored Cubicle Tech Support:";
    Security_Camera:
    cout<<"\nSecurity Cameras:x__\b\b"; cin>>Impartial_Tech<U>::inventory[10];
    if(Impartial_Tech<U>::inventory[10]<0 || Impartial_Tech<U>::inventory[10]>50)
    goto Security_Camera;
    Monitors:
    cout<<"\nMonitors:x__\b\b"; cin>>Impartial_Tech<U>::inventory[11];
    if(Impartial_Tech<U>::inventory[11]<0 || Impartial_Tech<U>::inventory[11]>10)
    goto Monitors;
    clear;

    ofstream outfile("RegularEquipment.dat");
    for(int i=0;i<12;i++)
    {
        outfile.write(reinterpret_cast<char *>(&Impartial_Tech<U>::inventory[i]), sizeof(Impartial_Tech<U>::inventory[i]));
        Impartial_Tech<U>::items+=Impartial_Tech<U>::inventory[i];
    }
    
}
template<class U>
void RegularEquipment<U>::displayer()
{
    extract_file();
nxt;
cout<<"                       _.===========================._"<<endl;  
cout<<"                     .'`  .-  - __- - - -- --__--- -.  `'.                    ___"<<endl;  
cout<<"                 __ / ,'`     _|--|_________|--|_     `'. \\           _______|___|______"<<endl;  
cout<<"               /'--| ;    _.'\\ |  '         '  | /'._    ; |       __|__________________|"<<endl;  
cout<<"              //   | |_.-' .-'.'      ___      '.'-. '-._| |       \\  ]________________[ `---. "<<endl;  
cout<<"             (\\)   \\'` _.-` /     .-'`_ `'-.     \\ `-._ `'/         `.                   ___  L"<<endl;  
cout<<"             (\\)    `-'    |    .' .-'" "'-. '.       | `-`             |                  |   L |"<<endl;  
cout<<"            (\\)            |   / .'(3)(2)(1)'. \\   |                 |                  |   | |  "<<endl;  
cout<<"            (\\)            |  / / (4) .-.     \\ \\  |                 |                  |   F F  "<<endl;  
cout<<"            (\\)            |  | |(5) (   )'==,J |  |                 |                  |  / /   "<<endl;  
cout<<"           (\\)             |  \\ \\ (6) '-' (0) / /  |                 J                  F.' /"<<endl;  
cout<<"          (\\)              |   \\ '.(7)(8)(9).' /   |                  L                J  .'"<<endl;  
cout<<"          (\\)           ___|    '. '-.._..-' .'    |                  J                F.'      "<<endl;                   
cout<<"          (\\)          /.--|      '-._____.-'      |                   L              J'                          ___________________________________________________"<<endl;                                            
cout<<"           (\\)        (\\)  |\\_  _  __   _   __  __/|                   J              F                           |   <<<<<<<<<<<<<<<INVENTORY  LIST>>>>>>>>>>>>>   |"<<endl;                              
cout<<"          (\\)        (\\)   |                       |                    L            J                            |_________________________________________________|"<<endl;                         
cout<<"         (\\)_._._.__(\\)    |                       |                    |____________|                            |               KITCHEN TECH SUPPLIES             |"<<endl;  
cout<<"          (\\\\\\\\\\\\\\\\\\)      '.___________________.'                      F            J                            |_________________________________________________|"<<endl;         
cout<<"           '-'-'-'--'                                                  J              L                           |-Blenders:"<<setfill(' ')<<setw(35)<<"x"<<Impartial_Tech<U>::inventory[0]<<setfill(' ')<<setw(5-intlength(Impartial_Tech<U>::inventory[0]))<<"|"<<endl;  
cout<<"                                                                       |______________|                           |-Microwaves:"<<setfill(' ')<<setw(33)<<"x"<<Impartial_Tech<U>::inventory[1]<<setfill(' ')<<setw(5-intlength(Impartial_Tech<U>::inventory[1]))<<"|"<<endl;  
cout<<"              __________                                                                                          |-Electronic Mincers:"<<setfill(' ')<<setw(25)<<"x"<<Impartial_Tech<U>::inventory[2]<<setfill(' ')<<setw(5-intlength(Impartial_Tech<U>::inventory[2]))<<"|"<<endl;  
cout<<"             /_________/`-_                                                                                       |-Fridge Support:"<<setfill(' ')<<setw(29)<<"x"<<Impartial_Tech<U>::inventory[3]<<setfill(' ')<<setw(5-intlength(Impartial_Tech<U>::inventory[3]))<<"|"<<endl;
cout<<"          _-'          `-_ /|                                                     __ _                            |_________________________________________________|"<<endl;
cout<<"         {                } |                                                   .: .' '.                          |    Customer-Tailored Cubicle Tech Support       |"<<endl;
cout<<"         |  ____________  | |                                                  /: /     \\_                        |_________________________________________________|"<<endl;
cout<<"         | |    \\/||    | | |            ___                                  ;: ;  ,-'/`:\\                       |-Dispensers:"<<setfill(' ')<<setw(33)<<"x"<<Impartial_Tech<U>::inventory[4]<<setfill(' ')<<setw(5-intlength(Impartial_Tech<U>::inventory[4]))<<"|"<<endl;  
cout<<"         | |    /\\||    | | |           / _ \\                                 |: | |  |() :|                      |-Personalized Web Cameras:"<<setfill(' ')<<setw(19)<<"x"<<Impartial_Tech<U>::inventory[5]<<setfill(' ')<<setw(5-intlength(Impartial_Tech<U>::inventory[5]))<<"|"<<endl;  
cout<<"         | |            | | |          | / \\ |                                ;: ;  '-.\\_:/                       |-Air Conditioning:"<<setfill(' ')<<setw(27)<<"x"<<Impartial_Tech<U>::inventory[6]<<setfill(' ')<<setw(5-intlength(Impartial_Tech<U>::inventory[6]))<<"|"<<endl;  
cout<<"         | ||\\/      |||| | |          | \\_/ |                                 \\: \\     /`                        |-Clocks:"<<setfill(' ')<<setw(37)<<"x"<<Impartial_Tech<U>::inventory[7]<<setfill(' ')<<setw(5-intlength(Impartial_Tech<U>::inventory[7]))<<"|"<<endl;  
cout<<"         | ||/\\ ,*.  |||| | |           \\___/ ___                               ':_'._.'                          |-Kitsche Telephones:"<<setfill(' ')<<setw(25)<<"x"<<Impartial_Tech<U>::inventory[8]<<setfill(' ')<<setw(5-intlength(Impartial_Tech<U>::inventory[8]))<<"|"<<endl;  
cout<<"         | |  ,'   `.   | | |           _|_|_/[_]\\__==_                            ||                             |-Personal Stereo:"<<setfill(' ')<<setw(28)<<"x"<<Impartial_Tech<U>::inventory[9]<<setfill(' ')<<setw(5-intlength(Impartial_Tech<U>::inventory[9]))<<"|"<<endl;  
cout<<"         | |    \\ /| `. | | |          [---------------]                          /__\\                            |_________________________________________________|"<<endl;
cout<<"         | |_____V_|____| | |          | O   /---\\     |               .---.     {====}                           |     Security-Tailored Cubicle Tech Support      |"<<endl; 
cout<<"         | |    : /     | | |          |    |     |    |             .'   _,'-,__|::  |                           |_________________________________________________|"<<endl;
cout<<"         | |    :/:     | | |          |     \\___/     |            /    ((O)=;--.::  |                           |-Security Cameras:"<<setfill(' ')<<setw(27)<<"x"<<Impartial_Tech<U>::inventory[10]<<setfill(' ')<<setw(5-intlength(Impartial_Tech<U>::inventory[10]))<<"|"<<endl;    
cout<<"         | |    / :     | | |          [---------------]           ;      `|: |  |::  |                           |-Security Monitors:"<<setfill(' ')<<setw(26)<<"x"<<Impartial_Tech<U>::inventory[11]<<setfill(' ')<<setw(5-intlength(Impartial_Tech<U>::inventory[11]))<<"|"<<endl; 
cout<<"         | |   /: @     | | |                [___]                 |       |: |  |::  |                           |_________________________________________________|"<<endl;
cout<<"         | |  / :       | | |                 | |\\\\                |       |: |  |::  |                           | OVERALL NUMBER OF EQUIPMENT:"<<Impartial_Tech<U>::items<<setfill(' ')<<setw(21-intlength(Impartial_Tech<U>::items))<<"|"<<endl;
cout<<"         | |( ) :       | | |                 | | \\\\               |       |: |  |::  |                           |_________________________________________________|"<<endl;
cout<<"         | |    :       | | |                 [ ]  \\\\_             |       |: |  |::  | "<<endl;
cout<<"         | |    :       | | |                /|_|\\\\  ( \\\\          |       |: |  |::  |    "<<endl;                    
cout<<"         | |    :       | | |               //| |\\\\  \\\\ \\\\         |      /:'__\\ |::  |   "<<endl;                      
cout<<"         | |    :       | | |              // | | \\\\  \\\\ \\\\        |     [______]|::  |         "<<endl;                 
cout<<"         | |    :       | | |             //  |_|  \\\\  \\\\_\\\\       |      `----` |::  |__     "<<endl;                      
cout<<"         | |    @       | | |            //   | |   \\\\             |         _.--|::  |  ''--._      "<<endl;                 
cout<<"         | |____________| | |           //\\   | |   /\\\\            ;       .'  __{====}__      '.     "<<endl;                   
cout<<"         |________________|/           //  \\  | |  /  \\\\            \\    .'_.-'._ `""` _.'-._    '.      "<<endl;                   
cout<<"                                      //    \\ | | /    \\\\            '--'/`      `''''`      `\\    '.__    "<<endl;                      
cout<<"                                     //      \\|_|/      \\\\               '._                _.'               "<<endl;            
cout<<"                                    //        [_]        \\\\                 `""--......--""` "<<endl;
cout<<"                                   //          H          \\\\ "<<endl;
cout<<"                                  //           H           \\\\ "<<endl;
cout<<"                                 //            H            \\\\ "<<endl;
cout<<"                                //             H             \\\\ "<<endl;
cout<<"                               //              H              \\\\ "<<endl;
cout<<"                              //                               \\\\ "<<endl;
cout<<"                             //                                 \\\\ "<<endl;
}
template<class U>
void RegularEquipment<U>::extract_file()
{
     Impartial_Tech<U>::inventory=new int[12];
     ifstream infile("RegularEquipment.dat");
     infile.seekg(0);
     for(int i=0;i<12;i++)
     {
         infile.read((char *)&Impartial_Tech<U>::inventory[i],sizeof(Impartial_Tech<U>::inventory));
         Impartial_Tech<U>::items+=Impartial_Tech<U>::inventory[i];
     }
}
template<class U>
void RegularEquipment<U>::modelsetter(int *a)
{
    Impartial_Tech<U>::inventory=new int[12];
    ofstream outfile("RegularEquipment.dat");
    for(int i=0;i<12;i++)
    {
        Impartial_Tech<U>::inventory[i]=a[i];
        outfile.write(reinterpret_cast<char *>(&Impartial_Tech<U>::inventory[i]), sizeof(Impartial_Tech<U>::inventory[i]));
        Impartial_Tech<U>::items+=Impartial_Tech<U>::inventory[i];
    }
  
}

