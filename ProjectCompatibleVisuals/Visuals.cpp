#include"Visuals.h"

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if(size == 0)
	{
		size = 20;	// default cursor size
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}


void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; 
CursorPosition.Y = y; 
SetConsoleCursorPosition(console,CursorPosition); 
}

void gotoXY(int x, int y, string text) 
{ 

CursorPosition.X = x; 
CursorPosition.Y = y; 
SetConsoleCursorPosition(console,CursorPosition);
cout << text;
}

string Shadow[5] = { "","\xB0","\xB1","\xB2"," " };
string  Style[5][12] = { 
{""," "," "," "," "," "," "," "," "," "," "," " },
{"","\xDA","\xC4","\xBF","\xB3","\xD9","\xC0","\xC3","\xB4","\xC2","\xB3","\xC1"},
{"","\xC9","\xCD","\xBB","\xBA","\xBC","\xC8","\xCC","\xB9","\xCB","\xBA","\xCA"},
{"","\xD5","\xCD","\xB8","\xB3","\xBE","\xD4","\xC6","\xB9","\xD1","\xB3","\xCF"},
{"","\xD6","\xC4","\xB7","\xBA","\xBD","\xD3","\xC7","\xC6","\xD2","\xBA","\xD0"}
};


void Box(int style, int across, int down, int amount, int rows, int color, int shadow, int shadow_color)
{
int x,y, go;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color );
for (x=rows; x>0; x--)
	{
	  for (y=amount; y>0 ;y--)
	  { gotoXY((across+y)-1,(down+x)-1);
	     {
	       if (y==1 && x==1)
	       {
		  cout << Style[style][1];
		  for (go=amount-2; go>0 ;go--)
			{ 
			  cout << Style[style][2];
			 }
		  cout << Style[style][3];
			}
	  else if ( (y>=1 && y<=amount-1) && x!=1 )
	        {
		  gotoXY((across+y),(down+x)-1);
		  cout << Style[style][4];
		   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),shadow_color);
		   cout << Shadow[shadow];
		   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color );
		  y--;
		for (go=amount-2; go>0 ;go--)
		  { gotoXY((across+y),(down+x)-1);
		     cout << " ";
		    y--;
		  }
		  gotoXY(across+y,(down+x)-1);
		  cout << Style[style][4];
		}
	  else if (y==amount && x==rows)
	      {
		  y--;
		  gotoXY(across+y,(down+x)-1);
		  cout << Style[style][5];
		 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),shadow_color);
			cout << Shadow[shadow];
			gotoXY(across+y,(down+x));
			cout <<  Shadow[shadow] << Shadow[shadow];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color );
		  y--;
		  for (go=amount-2; go>0 ; go--)
		  {
		    gotoXY(across+y,(down+x)-1);
		    cout << Style[style][2];
		   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),shadow_color);
		   gotoXY(across+y,(down+x));
		   cout << Shadow[shadow];
		   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color );
		   y--;
		  }
		  gotoXY(across+y,(down+x)-1);
		  cout << Style[style][6];
	       }
	    }
	  }
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color );
}

void WaitKey()
{
while (_kbhit()) _getch(); // Empty the input buffer
_getch(); // Wait for a key
while (_kbhit()) _getch(); // Empty the input buffer (some keys sends two messages)
}


void Post_Account_Open_Visuals::manager_initial_display()
{
  FILE *filePointer;
  char ch;
  filePointer = fopen("Manager.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch);
        }
    }

    fclose(filePointer);
    cout<<endl;
}
void Visuals::person_details_display()
{
  FILE *filePointer;
  char ch;
  filePointer = fopen("Person.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch);
        }
    }

    fclose(filePointer);
    cout<<endl;
}
void Post_Account_Open_Visuals::receptionist_manager()
{
  FILE *filePointer;
  char ch;
  filePointer = fopen("Manager_Options_Display.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch);
        }
    }

    fclose(filePointer);
    cout<<endl;
}
void Visuals::food_visual()
{
  FILE *filePointer;
  char ch;
  filePointer = fopen("FoodMenuVisual.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch);
        }
    }

    fclose(filePointer);
    cout<<endl;
}
void Visuals::food_after_visual()
{
  ifstream extract2("FoodMenuVisualAfter.txt", ios::out);
  extract2.seekg(0);
  string temp;
    int j=0;
    do{

        getline(extract2, temp, '\n');
        gotoXY(0,j,temp);
        j++;
        if(!extract2.good())
        break;
        
    }while(extract2.good());
}
void Post_Account_Open_Visuals::technical_initial_display()
{
FILE *filePointer;
  char ch;
  filePointer = fopen("TechInitialVisual.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch);
        }
    }

    fclose(filePointer);
    cout<<endl;
}
void Post_Account_Open_Visuals::regular_initial_display()
{
    FILE *filePointer;
  char ch;
  filePointer = fopen("Regular_Initial_display.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch);
        }
    }

    fclose(filePointer);
    cout<<endl;
}
void Visuals::technical_feedback()
{
    
}

void Post_Account_Open_Visuals::Accountant_initial_display()
{
   
    FILE *filePointer;
  char ch;
  filePointer = fopen("Accountant_Initial_Display.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch);
        }
    }

    fclose(filePointer);
    cout<<endl;
}
void Post_Account_Open_Visuals::Customer_ticket_display()
{
    FILE *filePointer;
  char ch;
  filePointer = fopen("Customer_Ticket_Display.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch);
        }
    }

    fclose(filePointer);
    cout<<endl;
}
void Visuals::Complex_ID_border()
{
    FILE *filePointer;
  char ch;
  filePointer = fopen("complex_ID_border.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch);
        }
    }

    fclose(filePointer);
    cout<<endl;
}
void Pre_Account_Open_Visuals::login_display()
{
//   ifstream extract2("LOGINDISPLAY.txt", ios::out);
//     extract2.seekg(0);
//     string temp;
//     int j=0;
//     for (double i=102;i>0;i-=0.75)
//     {
       
//         j=0;
//         extract2.seekg(0);
//     do{

//         getline(extract2, temp, '\n');
//         gotoXY(i-5,j,"                                                                                                                                                     ");
//         gotoXY(i,j,temp);
//         j++;
//         if(!extract2.good())
//         break;
        
//     }while(extract2.good());
   

//     }

//     extract2.close();
//     extract2.open("SYSTEM.txt", ios::out);
//     extract2.seekg(0);
//     j=0;
//     for (double i=0;i<90;i+=0.75)
//     {
    
//         j=20;
//         extract2.seekg(0);
//     do{
        
//         getline(extract2, temp, '\n');
//         gotoXY(i-5,j,"                                                                                                                                                    ");
//         gotoXY(i,j,temp);
//         j++;
//         if(!extract2.good())
//         break;
        
//     }while(extract2.good());
   

//     }
   
//     extract2.close();
  FILE *filePointer;
  char ch;
  filePointer = fopen("LOGINDISPLAY.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch);
        }
    }

    fclose(filePointer);
    cout<<endl;
}
void Pre_Account_Open_Visuals::entry_visual()
{
    int width = 57;
	int height = 30; 
	
	int color[] = {19,22,24,23,31,23,24,22};
	string text = "Welcome to Cafe Jasmine Dragon";
	int x,y;
	Box(1,0,0,57,30,120,0,0);  // Gray background box
	for (x = 3;x<21;x++)
	{
		Box(2,5,5,47,x,192,1,128);  // Blue box
	}
	for (x = 3;x<33;x++)
	{
		Box(3,13,9,x,5,23,2,64);   // Red box for text
	}
	

	for (y = 0;y<7;y++)
   {
	   for (x=0; x<=7;x++)
	   {
		   SetConsoleTextAttribute(console, color[x]);
		   gotoXY(14,11, text );
	
	   }
	   Sleep(80);
	}
	for (x=0; x<=4;x++)	   
	{
		SetConsoleTextAttribute(console, color[x]);
		gotoXY(14,11, text );
	
	}
	setcursor(0,0);
	
	for (x = 3;x<35;x++)
	{
		Box(3,12,18,x,3,23,2,64);  // 2nd red box for 'Press any key... '
	
	}
					
	for (x=0; x<=4;x++)	   
	{
		SetConsoleTextAttribute(console, color[x]);
		gotoXY(13,19, "Press Any Key" );
		
	}
	WaitKey();
	SetConsoleTextAttribute(console, 15);
}
void Post_Account_Open_Visuals:: OneTimeTicketDisplay()
{
    FILE *filePointer;
  char ch;
  filePointer = fopen("OneTimeTicketVisual.txt", "r");
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        while ((ch = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch);
        }
    }

    fclose(filePointer);
    cout<<endl;
}

void Pre_Account_Open_Visuals::after_login_display()
{
    system("CLS");
    char a=219;
	// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),143);
	// // for(int i=0;i<128;i++)
	// // cout<<a;

	// for(int i=0;i<25;i++)
	// {
	// 	for(int j=0;j<50;j++)
	// 	{
	// 		gotoXY(j+100,i+30);
	// 		cout<<' ';
	// 	}
	// }
	
	// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),143);
    // ifstream extract2("Smoking.txt", ios::out);
    // extract2.seekg(0);
    // string temp;
    // int j=30;
	// do
	// {
	// 	getline(extract2, temp, '\n');
    //     gotoXY(100,j,temp);
    //     j++;
    //     if(!extract2.good())
    //     break;
	// } while (extract2.good());
    ifstream extract2;
    string temp;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
	extract2.close();
	extract2.open("cowboy.txt");
	extract2.seekg(0);
	int j=30;
	do
	{
		getline(extract2, temp, '\n');
        gotoXY(20,j,(temp));
        j++;
        if(!extract2.good())
        break;
	} while (extract2.good());
	extract2.close();
	string b[4]={"NS1.txt","NS2.txt","NS3.txt","NS4.txt"};
	for(int l=0;l<2;l++)
	{
	for(int i=0;i<4;i++)
	{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),57+i);
	extract2.open(b[i]);
	j=45;
	do
	{
		getline(extract2, temp, '\n');
        gotoXY(20,j,temp);
        j++;
        if(!extract2.good())
        break;
	} while (extract2.good());
	usleep(1);
	extract2.close();

	
	}
	}


     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
}
int Post_Account_Open_Visuals::plane_welcome()
{
    char a=219;
    int choice;
	ifstream extract2;
    string temp;
    int j=0,s=0;
    while (1)
    {
    for(int i=0;i<238;i+=2)
    {
        Sleep(60);
		j=0+s;
		if(i%3==0)
		{
			extract2.open("WelcomingPlane2.txt");
	
		}
		else
		{
			extract2.open("WelcomingPlane.txt");
			
		}
		
		extract2.seekg(0);
	do
	{
		getline(extract2, temp, '\n');
        gotoXY(i-1,j,"                                  ");
        gotoXY(i,j,temp);
        
        j++;
        if(!extract2.good())
        break;
        if(kbhit()) cin>>choice;
        if(choice==1 || choice==2 || choice==3 || choice ==4|| choice ==5 || choice==6 || choice==7 || choice==8 || choice==9 || choice==10 || choice==11)
        goto endofplane;
	} while(extract2.good());
    
	extract2.close();
    }
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
    for(int i=0;i<200;i++)
	{
		for(int j=8;j<10;j++)
		{
			gotoXY(i,j);
			cout<<' ';
		}
	}
    
    s++;
    if(s==2)
    {
       for(int i=0;i<200;i++)
	{
		for(int j=0;j<10;j++)
		{
			gotoXY(i,j);
			cout<<' ';
		}
	}
        s=0;
    }

    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
    }
    endofplane:
	extract2.close();
    return choice;
}


void Pre_Account_Open_Visuals::printdog(int startX, int startY)
{
    ifstream extract("Pet.txt");
    string temp;
    do
    {
       getline(extract,temp,'\n');
       gotoXY(startX,startY,temp);
       startY++;
       if(!extract.good())
       return;

    } while (extract.good());
    
}
void Pre_Account_Open_Visuals::displaygraph()
{   
    system("CLS");
    ifstream file("ID.dat");
    int b,c,d,e,f;
    file.read((char *)(&b),sizeof(b));
    b--;
    file.read((char *)(&c),sizeof(c));
    c--;
    file.read((char *)(&d),sizeof(d));
    d--;
    file.read((char *)(&e),sizeof(e));
    e--;
    file.read((char *)(&f),sizeof(f));
    f--;
    file.close();
    int tempb=b,tempc=c,tempd=d,tempe=e,tempf=f;   

    char a=219;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    // cout<<"\xDA \xC4 \xBF \xB3 \xD9 \xC0 \xC3 \xB4 \xC2 \xB3 \xC1";
    for(int i=39;i>1;i--)
    {
        gotoXY(10,i);
        cout<<"\xB3";
    }
    gotoXY(10,39);
    cout<<"\xC0";
    for(int i=11;i<100;i++)
    {
        gotoXY(i,39);
        cout<<"\xC4";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    if(b>27)
    {
        b=27;
    }
    for(int i=13;i<26;i++)
    {
        for(double j=38;j>(38-b);j--)
        {
            gotoXY(i,j);
            cout<<a;
        }
    }
    printdog(13,38-b-10);
    gotoXY(24,38-b-11);
    cout<<tempb;
    gotoXY(14, 40, "Accountant");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    if(c>27)
    {
        c=27;
    }
    for(int i=31;i<44;i++)
    {
        for(double j=38;j>(38-c);j--)
        {
            gotoXY(i,j);
            cout<<a;
        }
    }
    printdog(31,38-c-10);
    gotoXY(42,38-c-11);
    cout<<tempc;
    gotoXY(33, 40, "Customer");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    if(d>27)
    {
        d=27;
    }
    for(int i=49;i<62;i++)
    {
        for(double j=38;j>(38-d);j--)
        {
            gotoXY(i,j);
            cout<<a;
        }
    }
    printdog(49,38-d-10);
    gotoXY(60,38-d-11);
    cout<<tempd;
    gotoXY(51, 40, "Manager");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    if(e>27)
    {
        e=27;
    }
    for(int i=67;i<80;i++)
    {
        for(double j=38;j>(38-e);j--)
        {
            gotoXY(i,j);
            cout<<a;
        }
    }
    printdog(67,38-e-10);
    gotoXY(78,38-e-11);
    cout<<tempe;
    gotoXY(66, 40, "Technical Staff");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    if(f>27)
    {
        f=27;
    }
    for(int i=85;i<98;i++)
    {
        for(double j=38;j>(38-f);j--)
        {
            gotoXY(i,j);
            cout<<a;
        }
    }
    printdog(85,38-f-10);
    gotoXY(96,38-f-11);
    cout<<tempf;
    gotoXY(86, 40, "Regular Staff");
    _getch();
}
void Pre_Account_Open_Visuals::dragon_display()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),94);
    system("CLS");
    ifstream extract2("dragon150.txt", ios::out);
    extract2.seekg(0);
    string temp;
    int j=0;
    do
    {
        getline(extract2, temp, '\n');
        gotoXY(30,j,temp);
        j++;
        if(!extract2.good())
        break;
    } while (extract2.good());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),88);
    gotoXY(128,14,"\xDA");
    for(int i=1;i<40;i++)
    {
        gotoXY(128+i,14,"\xC4");
    }
    for(int i=1;i<28;i++)
    {
        gotoXY(128,14+i,"\xB3");
    }    
    for(int i=1;i<40;i++)
    {
        gotoXY(128+i,41,"\xC4");
    }
    gotoXY(128,41,"\xC0");
    gotoXY(128,16,"\xC3");
    for(int i=1;i<40;i++)
    {
        gotoXY(128+i,16,"\xC4");
    }
    gotoXY(128,18,"\xC3");
    for(int i=1;i<40;i++)
    {
        gotoXY(128+i,18,"\xC4");
    }
    gotoXY(128,20,"\xC3");
    for(int i=1;i<40;i++)
    {
        gotoXY(128+i,20,"\xC4");
    }   
    gotoXY(128,23,"\xC3");
     for(int i=1;i<40;i++)
    {
        gotoXY(128+i,23,"\xC4");
    } 
    gotoXY(128,25,"\xC3");
    for(int i=1;i<40;i++)
    {
        gotoXY(128+i,25,"\xC4");
    } 
    gotoXY(128,28,"\xC3");
    for(int i=1;i<40;i++)
    {
        gotoXY(128+i,28,"\xC4");
    }
    gotoXY(128,30,"\xC3");
    for(int i=1;i<40;i++)
    {
        gotoXY(128+i,30,"\xC4");
    }
    gotoXY(128,33,"\xC3");
    for(int i=1;i<40;i++)
    {
        gotoXY(128+i,33,"\xC4");
    }
    gotoXY(128,35,"\xC3");
    for(int i=1;i<40;i++)
    {
        gotoXY(128+i,35,"\xC4");
    }
    gotoXY(128,38,"\xC3");
    for(int i=1;i<40;i++)
    {
        gotoXY(128+i,38,"\xC4");
    }
    gotoXY(128,40,"\xC3");
    for(int i=1;i<40;i++)
    {
        gotoXY(128+i,40,"\xC4");
    }



    for(int i=1;i<28;i++)
    {
        gotoXY(168,14+i,"\xB3");
    }
    gotoXY(168,41,"\xD9");
    gotoXY(168,14,"\xBF");
    gotoXY(168,16,"\xB4");
    gotoXY(168,18,"\xB4");
    gotoXY(168,20,"\xB4");
    gotoXY(168,23,"\xB4");
    gotoXY(168,25,"\xB4");
    gotoXY(168,28,"\xB4");
    gotoXY(168,30,"\xB4");
    gotoXY(168,33,"\xB4");
    gotoXY(168,35,"\xB4");
    gotoXY(168,38,"\xB4");
    gotoXY(168,40,"\xB4");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),95);
    gotoXY(131,15,"          SELECT AN OPTION");
    gotoXY(130,19,"1. Make New Account.");
    gotoXY(130,24,"2. Access Pre-existing Account.");
    gotoXY(130,29,"3. Book A Ticket Without An Account.");
    gotoXY(130,34,"4. User-Base Infographic.");
    gotoXY(130,39,"5. Exit"); 
    gotoXY(0,0," ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),63);
}