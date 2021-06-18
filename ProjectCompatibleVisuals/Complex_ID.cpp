#include"Complex_ID.h"
int ID::check_password(string b, int a)
{
    int count=0;
     for(int i=1,j=0,k=0,l=0,m=0;i<accountant_gate;i++)
    {
        if(all_employee_names[i][j][k][l][m]==b && random[i][j][k][l][m]==a)
        {
        return 1;
        }
    }
        for(int i=0,j=1,k=0,l=0,m=0;j<customer_gate;j++)
    {
       if(all_employee_names[i][j][k][l][m]==b && random[i][j][k][l][m]==a)
        {
        return 2;
        }
        

    }
    for(int i=0,j=0,k=1,l=0,m=0;k<manager_gate;k++)
    {
        if(all_employee_names[i][j][k][l][m]==b && random[i][j][k][l][m]==a)
        {
        return 3;
        }

    }
    for(int i=0,j=0,k=0,l=1,m=0;l<tech_gate;l++)
    {
        if(all_employee_names[i][j][k][l][m]==b && random[i][j][k][l][m]==a)
        {
        return 4;
        }

    }
     for(int i=0,j=0,k=0,l=0,m=1;m<regular_gate;m++)
    {
        if(all_employee_names[i][j][k][l][m]==b && random[i][j][k][l][m]==a)
        {
        return 5;
        }
    }

if(count==0)
return 0;
}
void ID::operator =(string a)
{
    string b[1]=a;
    PUT_ID_IN(b,1,IsType);
}
int ID::return_password(string a)
{
int count=0;
     for(int i=1,j=0,k=0,l=0,m=0;i<accountant_gate;i++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
        return random[i][j][k][l][m];
        }
    }
        for(int i=0,j=1,k=0,l=0,m=0;j<customer_gate;j++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
                 return random[i][j][k][l][m];
        }
        

    }
    for(int i=0,j=0,k=1,l=0,m=0;k<manager_gate;k++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
             return random[i][j][k][l][m];
        }

    }
    for(int i=0,j=0,k=0,l=1,m=0;l<tech_gate;l++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
         return random[i][j][k][l][m];
        }

    }
     for(int i=0,j=0,k=0,l=0,m=1;m<regular_gate;m++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
            return random[i][j][k][l][m];
        }
    }

if(count==0)
return 0;
}

void ID::EXTRACT_FROM_FILE()
{
if(IsType==0){IsType=1;}
int acc=0,cust=0,man=0,tech=0,reg=0;

ifstream file("ID.dat", ios::out);
file.seekg(0);
    file.read((char*)(&acc), sizeof(acc));
    accountant_gate=acc;
if(acc==0){acc=1;}
    file.read((char*)(&cust), sizeof(cust));
    customer_gate=cust;
if(cust==0){cust=1;}
    file.read((char*)(&man), sizeof(man));
    manager_gate=man;
if(man==0){man=1;}
    file.read((char*)(&tech), sizeof(tech));
    tech_gate=tech;
if(tech==0){tech=1;}
    file.read((char*)(&reg), sizeof(reg));
    regular_gate=reg;
if(reg==0){reg=1;}
    file.close();
    string temp;
    int y;
string *****x= new string****[acc];
    
    for(int i=0;i<acc;i++)
        x[i]=new string***[cust];
    
    for(int i=0;i<acc;i++)
        for(int j=0;j<cust;j++)
            x[i][j]=new string**[man];

    for(int i=0;i<acc;i++)
        for(int j=0;j<cust;j++)
            for(int k=0;k<man;k++)
            x[i][j][k]=new string*[tech];

    for(int i=0;i<acc;i++)
        for(int j=0;j<cust;j++)
            for(int k=0;k<man;k++)
                for(int l=0;l<tech;l++)
                    x[i][j][k][l]=new string[reg];
int *****num= new int****[acc];
    
    for(int i=0;i<acc;i++)
        num[i]=new int***[cust];
    
    for(int i=0;i<acc;i++)
        for(int j=0;j<cust;j++)
            num[i][j]=new int**[man];

    for(int i=0;i<acc;i++)
        for(int j=0;j<cust;j++)
            for(int k=0;k<man;k++)
            num[i][j][k]=new int*[tech];

    for(int i=0;i<acc;i++)
        for(int j=0;j<cust;j++)
            for(int k=0;k<man;k++)
                for(int l=0;l<tech;l++)
                    num[i][j][k][l]=new int[reg];


random=num;
all_employee_names=x;
ifstream file1("Accountant.dat");
file1.seekg(0);
for(int i=1,j=0,k=0,l=0,m=0; i<accountant_gate;i++)
{
    getline(file1, temp, '\0');
    all_employee_names[i][j][k][l][m]=temp;
    file1>>random[i][j][k][l][m];
}
file1.close();
ifstream file3("Customer.dat");
file3.seekg(0);
for(int i=0,j=1,k=0,l=0,m=0; j<customer_gate;j++)
{
    getline(file3, temp, '\0');
    all_employee_names[i][j][k][l][m]=temp;
    file3>>random[i][j][k][l][m];
}
file3.close();
ifstream file4("Manager.dat");
for(int i=0,j=0,k=1,l=0,m=0; k<manager_gate;k++)
{
    getline(file4, temp, '\0');
    all_employee_names[i][j][k][l][m]=temp;
    file4>>random[i][j][k][l][m];
}
file4.close();
ifstream file5("Tech.dat");
for(int i=0,j=0,k=0,l=1,m=0; l<tech_gate;l++)
{
    getline(file5, temp, '\0');
    all_employee_names[i][j][k][l][m]=temp;
    file5>>random[i][j][k][l][m];
}
file5.close();
ifstream file6("Regular.dat");
for(int i=0,j=0,k=0,l=0,m=1; m<regular_gate;m++)
{
    getline(file6, temp, '\0');
    all_employee_names[i][j][k][l][m]=temp;
    file6>>random[i][j][k][l][m];
}
file6.close();
}
void ID::APPEND_TO_FILE()
{
string temp;
int x;
ofstream file2("Accountant.dat", ios::app);
for(int i=1,j=0,k=0,l=0,m=0; i<accountant_gate;i++)
{
    temp=all_employee_names[i][j][k][l][m];
    file2.write(temp.c_str(), temp.length()+1);
    file2<<random[i][j][k][l][m];
}
file2.close();
ofstream file3("Customer.dat", ios::app);
for(int i=0,j=1,k=0,l=0,m=0; j<customer_gate;j++)
{
    temp=all_employee_names[i][j][k][l][m];
    file3.write(temp.c_str(), temp.length()+1);
    file3<<random[i][j][k][l][m];
}
file3.close();
ofstream file4("Manager.dat", ios::app);
for(int i=0,j=0,k=1,l=0,m=0; k<manager_gate;k++)
{
    temp=all_employee_names[i][j][k][l][m];
    file4.write(temp.c_str(), temp.length()+1);
    file4<<random[i][j][k][l][m];
}
file4.close();
ofstream file5("Tech.dat", ios::app);
for(int i=0,j=0,k=0,l=1,m=0; l<tech_gate;l++)
{
    temp=all_employee_names[i][j][k][l][m];
    file5.write(temp.c_str(), temp.length()+1);
    file5<<random[i][j][k][l][m];
}
file5.close();
ofstream file6("Regular.dat", ios::app);
for(int i=0,j=0,k=0,l=0,m=1; m<regular_gate;m++)
{
    temp=all_employee_names[i][j][k][l][m];
    file6.write(temp.c_str(), temp.length()+1);
    file6<<random[i][j][k][l][m];
}
file6.close();
int acc=0,cust=0,man=0,tech=0,reg=0;
ifstream file("ID.dat", ios::out);
file.seekg(0);
file.read((char*)(&acc), sizeof(acc));
file.read((char*)(&cust), sizeof(cust));
file.read((char*)(&man), sizeof(man));
file.read((char*)(&tech), sizeof(tech));
file.read((char*)(&reg), sizeof(reg));
int a=accountant_gate,c=customer_gate,m=manager_gate,t=tech_gate,r=regular_gate;
if(acc>0)
    a+=acc-1;
if(cust>0)
    c+=cust-1;
if(man>0)
    m+=man-1;
if(tech>0)
    t+=tech-1;
if(reg>0)
    r+=reg-1;
file.close();
ofstream Appender("ID.dat");
Appender.write(reinterpret_cast<char *>(&a), sizeof(a));
Appender.write(reinterpret_cast<char *>(&c), sizeof(c));
Appender.write(reinterpret_cast<char *>(&m), sizeof(m));
Appender.write(reinterpret_cast<char *>(&t), sizeof(t));
Appender.write(reinterpret_cast<char *>(&r), sizeof(r));
Appender.close();
}
void ID::INSERT_IN_FILE()
{

ofstream file("ID.dat");
file.write(reinterpret_cast<char *>(&accountant_gate), sizeof(accountant_gate));
file.write(reinterpret_cast<char *>(&customer_gate), sizeof(customer_gate));
file.write(reinterpret_cast<char *>(&manager_gate), sizeof(manager_gate));
file.write(reinterpret_cast<char *>(&tech_gate), sizeof(tech_gate));
file.write(reinterpret_cast<char *>(&regular_gate), sizeof(regular_gate));
file.close();
string temp;
int x;
ofstream file2("Accountant.dat");
for(int i=1,j=0,k=0,l=0,m=0; i<accountant_gate;i++)
{
    temp=all_employee_names[i][j][k][l][m];
    file2.write(temp.c_str(), temp.length()+1);
    file2<<random[i][j][k][l][m];
}
file2.close();
ofstream file3("Customer.dat");
for(int i=0,j=1,k=0,l=0,m=0; j<customer_gate;j++)
{
    temp=all_employee_names[i][j][k][l][m];
    file3.write(temp.c_str(), temp.length()+1);
    file3<<random[i][j][k][l][m];
}
file3.close();
ofstream file4("Manager.dat");
for(int i=0,j=0,k=1,l=0,m=0; k<manager_gate;k++)
{
    temp=all_employee_names[i][j][k][l][m];
    file4.write(temp.c_str(), temp.length()+1);
    file4<<random[i][j][k][l][m];
}
file4.close();
ofstream file5("Tech.dat");
for(int i=0,j=0,k=0,l=1,m=0; l<tech_gate;l++)
{
    temp=all_employee_names[i][j][k][l][m];
    file5.write(temp.c_str(), temp.length()+1);
    file5<<random[i][j][k][l][m];
}
file5.close();
ofstream file6("Regular.dat");
for(int i=0,j=0,k=0,l=0,m=1; m<regular_gate;m++)
{
    temp=all_employee_names[i][j][k][l][m];
    file6.write(temp.c_str(), temp.length()+1);
    file6<<random[i][j][k][l][m];
}
file6.close();
}

void ID::operator=(int a)
{
    IsType=a;
}
istream& operator>>(istream& a, ID& b)
{
    b.staff_decision_split();
}
 ostream& operator<<(ostream& a, ID& b)
 {
     b.ID_printer();
     return a;
 }
  ostream& operator,(ostream& a, ID& b)
 {
     a<<b;
     return a;
 }
void ID::Delete_ID(string a)
{
    int count=0;
     for(int i=1,j=0,k=0,l=0,m=0;i<accountant_gate;i++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Accountant to be deleted:"<<all_employee_names[i][j][k][l][m]<<endl;
            

			for(int x=i; x<(accountant_gate-1); x++)
			{
				all_employee_names[x][j][k][l][m]=all_employee_names[x+1][j][k][l][m];
                random[x][j][k][l][m]=random[x+1][j][k][l][m];
			}
			count++;
            accountant_gate--;
			continue;

        }
    }
       for(int i=0,j=1,k=0,l=0,m=0;j<customer_gate;j++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Customer to be deleted:"<<all_employee_names[i][j][k][l][m]<<endl;

			for(int x=j; x<(customer_gate-1); x++)
			{
				all_employee_names[i][x][k][l][m]=all_employee_names[i][x+1][k][l][m];
                random[i][x][k][l][m]=random[i][x+1][k][l][m];
			}
			count++;
            customer_gate--;
			continue;

        }
    }
    for(int i=0,j=0,k=1,l=0,m=0;k<manager_gate;k++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Manager to be deleted:"<<all_employee_names[i][j][k][l][m]<<endl;

			for(int x=k; x<(manager_gate-1); x++)
			{
				all_employee_names[i][j][x][l][m]=all_employee_names[i][j][x+1][l][m];
                random[i][j][x][l][m]=random[i][j][x+1][l][m];

			}
			count++;
            manager_gate--;
			continue;

        }
    }
    for(int i=0,j=0,k=0,l=1,m=0;l<tech_gate;l++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Technical Department Employee to be deleted:"<<all_employee_names[i][j][k][l][m]<<endl;

			for(int x=l; x<(tech_gate-1); x++)
			{
				all_employee_names[i][j][k][x][m]=all_employee_names[i][j][k][x+1][m];
                random[i][j][k][x][m]=random[i][j][k][x+1][m];

			}
			count++;
			tech_gate--;
            continue;

        }
    }
       for(int i=0,j=0,k=0,l=0,m=1;m<regular_gate;m++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Technical Department Employee to be deleted:"<<all_employee_names[i][j][k][l][m]<<endl;

			for(int x=m; x<(regular_gate-1); x++)
			{
				all_employee_names[i][j][k][l][x]=all_employee_names[i][j][k][l][x+1];
                random[i][j][k][l][x]=random[i][j][k][l][x+1];

			}
			count++;
            regular_gate--;
			continue;
            

        }
    }
    if(count==0)
    cout<<"NO IDs RELATE TO YOUR INPUT!!."<<endl;
    pause;
}
void ID::Delete_ID(string a, int b)
{
    int count=0;
     for(int i=1,j=0,k=0,l=0,m=0;i<accountant_gate;i++)
    {
        if(all_employee_names[i][j][k][l][m]==a && random[i][j][k][l][m]==b)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"ID of Accountant "<<all_employee_names[i][j][k][l][m]<<" to be DELETED is:SRS-"<<random[i][j][k][l][m]<<endl;
			for(int x=i; x<(accountant_gate-1); x++)
			{
				all_employee_names[x][j][k][l][m]=all_employee_names[x+1][j][k][l][m];
                random[x][j][k][l][m]=random[x+1][j][k][l][m];
			}
			count++;
            accountant_gate--;
			continue;

        }
    }
       for(int i=0,j=1,k=0,l=0,m=0;j<customer_gate;j++)
    {
        if(all_employee_names[i][j][k][l][m]==a && random[i][j][k][l][m]==b)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"ID of Customer "<<all_employee_names[i][j][k][l][m]<<" to be DELETED is:LES-"<<random[i][j][k][l][m]<<endl;
			for(int x=j; x<(customer_gate-1); x++)
			{
				all_employee_names[i][x][k][l][m]=all_employee_names[i][x+1][k][l][m];
                random[i][x][k][l][m]=random[i][x+1][k][l][m];
			}
			count++;
            customer_gate--;
			continue;

        }
    }
    for(int i=0,j=0,k=1,l=0,m=0;k<manager_gate;k++)
    {
        if(all_employee_names[i][j][k][l][m]==a && random[i][j][k][l][m]==b)
        {
            cout<<"ID FOUND!!"<<endl;
             cout<<"ID of Manager "<<all_employee_names[i][j][k][l][m]<<" to be DELETED is:SOR-"<<random[i][j][k][l][m]<<endl;

			for(int x=k; x<(manager_gate-1); x++)
			{
				all_employee_names[i][j][x][l][m]=all_employee_names[i][j][x+1][l][m];
                random[i][j][x][l][m]=random[i][j][x+1][l][m];

			}
			count++;
            manager_gate--;
			continue;

        }
    }
    for(int i=0,j=0,k=0,l=1,m=0;l<tech_gate;l++)
    {
        if(all_employee_names[i][j][k][l][m]==a && random[i][j][k][l][m]==b)
        {
            cout<<"ID FOUND!!"<<endl;
        cout<<"ID of Technical Department Employee "<<all_employee_names[i][j][k][l][m]<<" to be DELETED is:LPQ-"<<random[i][j][k][l][m]<<endl;


			for(int x=l; x<(tech_gate-1); x++)
			{
				all_employee_names[i][j][k][x][m]=all_employee_names[i][j][k][x+1][m];
                random[i][j][k][x][m]=random[i][j][k][x+1][m];

			}
			count++;
			tech_gate--;
            continue;

        }
    }
       for(int i=0,j=0,k=0,l=0,m=1;m<regular_gate;m++)
    {
        if(all_employee_names[i][j][k][l][m]==a && random[i][j][k][l][m]==b)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"ID of Regular Staff Employee "<<all_employee_names[i][j][k][l][m]<<" to be DELETED is:NNC-"<<random[i][j][k][l][m]<<endl;

			for(int x=m; x<(regular_gate-1); x++)
			{
				all_employee_names[i][j][k][l][x]=all_employee_names[i][j][k][l][x+1];
                random[i][j][k][l][x]=random[i][j][k][l][x+1];

			}
			count++;
            regular_gate--;
			continue;
            

        }
    }
    if(count==0)
    cout<<"NO IDs RELATE TO YOUR INPUT!!."<<endl;
    pause;
}
 void ID::Delete_ID(int a)
 {  
     int count=0;
     for(int i=1,j=0,k=0,l=0,m=0;i<accountant_gate;i++)
    {
        if(random[i][j][k][l][m]==a)
        {
            cout<<"NAME FOUND!!"<<endl;
            cout<<"ID of Accountant "<<all_employee_names[i][j][k][l][m]<<" to be DELETED is:SRS-"<<random[i][j][k][l][m]<<endl;
            

			for(int x=i; x<(accountant_gate-1); x++)
			{
				all_employee_names[x][j][k][l][m]=all_employee_names[x+1][j][k][l][m];
                random[x][j][k][l][m]=random[x+1][j][k][l][m];
			}
			count++;
            accountant_gate--;
			continue;

        }
    }
       for(int i=0,j=1,k=0,l=0,m=0;j<customer_gate;j++)
    {
        if(random[i][j][k][l][m]==a)
        {
            cout<<"NAME FOUND!!"<<endl;
           cout<<"ID of Customer "<<all_employee_names[i][j][k][l][m]<<" to be DELETED is:LES-"<<random[i][j][k][l][m]<<endl;

			for(int x=j; x<(customer_gate-1); x++)
			{
				all_employee_names[i][x][k][l][m]=all_employee_names[i][x+1][k][l][m];
                random[i][x][k][l][m]=random[i][x+1][k][l][m];
			}
			count++;
            customer_gate--;
			continue;

        }
    }
    for(int i=0,j=0,k=1,l=0,m=0;k<manager_gate;k++)
    {
        if(random[i][j][k][l][m]==a)
        {
           cout<<"NAME FOUND!!"<<endl;
            cout<<"ID of Manager "<<all_employee_names[i][j][k][l][m]<<" to be DELETED is:SOR-"<<random[i][j][k][l][m]<<endl;

			for(int x=k; x<(manager_gate-1); x++)
			{
				all_employee_names[i][j][x][l][m]=all_employee_names[i][j][x+1][l][m];
                random[i][j][x][l][m]=random[i][j][x+1][l][m];

			}
			count++;
            manager_gate--;
			continue;

        }
    }
    for(int i=0,j=0,k=0,l=1,m=0;l<tech_gate;l++)
    {
        if(random[i][j][k][l][m]==a)
        {
           cout<<"NAME FOUND!!"<<endl;
           cout<<"ID of Technical Department Employee "<<all_employee_names[i][j][k][l][m]<<" to be DELETED is:LPQ-"<<random[i][j][k][l][m]<<endl;
			for(int x=l; x<(tech_gate-1); x++)
			{
				all_employee_names[i][j][k][x][m]=all_employee_names[i][j][k][x+1][m];
                random[i][j][k][x][m]=random[i][j][k][x+1][m];

			}
			count++;
			tech_gate--;
            continue;

        }
    }
       for(int i=0,j=0,k=0,l=0,m=1;m<regular_gate;m++)
    {
        if(random[i][j][k][l][m]==a)
        {
            cout<<"NAME FOUND!!"<<endl;
           cout<<"ID of Regular Staff Employee "<<all_employee_names[i][j][k][l][m]<<" to be DELETED is:NNC-"<<random[i][j][k][l][m]<<endl;

			for(int x=m; x<(regular_gate-1); x++)
			{
				all_employee_names[i][j][k][l][x]=all_employee_names[i][j][k][l][x+1];
                random[i][j][k][l][x]=random[i][j][k][l][x+1];

			}
			count++;
            regular_gate--;
			continue;
        }
    }
    if(count==0)
    cout<<"NO IDs RELATE TO YOUR INPUT!!."<<endl;
    pause;
 }
 void ID::Search_ID(string a)
 { 
     int count=0;
     for(int i=1,j=0,k=0,l=0,m=0;i<accountant_gate;i++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
            cout<<"NAME FOUND!!"<<endl;
            cout<<"ID of Accountant "<<all_employee_names[i][j][k][l][m]<<" is:SRS-"<<random[i][j][k][l][m]<<endl;
            pause;
            count++;
        }
    }
        for(int i=0,j=1,k=0,l=0,m=0;j<customer_gate;j++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
           cout<<"NAME FOUND!!"<<endl;
           cout<<"ID of Customer "<<all_employee_names[i][j][k][l][m]<<" is:LES-"<<random[i][j][k][l][m]<<endl;
            pause;
            count++;
        }
        

    }
    for(int i=0,j=0,k=1,l=0,m=0;k<manager_gate;k++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
            cout<<"NAME FOUND!!"<<endl;
            cout<<"ID of Manager "<<all_employee_names[i][j][k][l][m]<<" is:SOR-"<<random[i][j][k][l][m]<<endl;
            pause;
            
        }

    }
    for(int i=0,j=0,k=0,l=1,m=0;l<tech_gate;l++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
            cout<<"NAME FOUND!!"<<endl;
           cout<<"ID of Technical Department Employee "<<all_employee_names[i][j][k][l][m]<<" is:LPQ-"<<random[i][j][k][l][m]<<endl;
            pause;
            count++;
            
        }

    }
     for(int i=0,j=0,k=0,l=0,m=1;m<regular_gate;m++)
    {
        if(all_employee_names[i][j][k][l][m]==a)
        {
            cout<<"NAME FOUND!!"<<endl;
            cout<<"ID of Regular Staff Employee "<<all_employee_names[i][j][k][l][m]<<" is:NNC-"<<random[i][j][k][l][m]<<endl;
            pause;
            count++;
        }
    }

    if(count==0)
    cout<<"NAME NOT PRESENT IN ID REGISTRY!!"<<endl;
 }
void ID::Search_ID(int a)
{ 
    int count=0;
    for(int i=1,j=0,k=0,l=0,m=0;i<accountant_gate;i++)
    {
        if(random[i][j][k][l][m]==a)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Accountant:"<<all_employee_names[i][j][k][l][m]<<endl;
            pause;
            count++;
        }
    }
        for(int i=0,j=1,k=0,l=0,m=0;j<customer_gate;j++)
    {
        if(random[i][j][k][l][m]==a)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Customer:"<<all_employee_names[i][j][k][l][m]<<endl;
            pause;
            count++;
        }

    }
    for(int i=0,j=0,k=1,l=0,m=0;k<manager_gate;k++)
    {
        if(random[i][j][k][l][m]==search_ID)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Manager:"<<all_employee_names[i][j][k][l][m]<<endl;
            pause;
            count++;
        }

    }
    for(int i=0,j=0,k=0,l=1,m=0;l<tech_gate;l++)
    {
        if(random[i][j][k][l][m]==search_ID)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Technical Staff Worker:"<<all_employee_names[i][j][k][l][m]<<endl;
            pause;
            count++;
        }

    }
    for(int i=0,j=0,k=0,l=0,m=1;m<regular_gate;m++)
    {
        if(random[i][j][k][l][m]==a)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Accountant:"<<all_employee_names[i][j][k][l][m]<<endl;
            pause;
            count++;
        }
    }
if(count==0)
cout<<"ID NOT FOUND IN REGISTRY!!"<<endl;
}
void ID::Search_ID()
{
repeat_ID_check:
clear;
cout<<"\t\t\t\t\t\t\t\t<<<Staff Members List>>>"<<endl;
cout<<"\t\t\t\t\t\t\t   Would you like to search ID for:\n\t\t\t\t\t\t\t\t1.Accountant.\n\t\t\t\t\t\t\t\t2.Customer.\n\t\t\t\t\t\t\t\t3.Manager.\n\t\t\t\t\t\t\t\t4.Tech Staff.\n\t\t\t\t\t\t\t\t5.Regular Staff."<<endl;
cin>>IsType;
if(IsType<1 && IsType>5)
goto repeat_ID_check;
if(IsType==1)
{
cout<<setw(7)<<"\n\t\t\t\t\t\t\t   Enter ID:SRS-_______\b\b\b\b\b\b\b";
cin>>search_ID;

    for(int i=1,j=0,k=0,l=0,m=0;i<accountant_gate;i++)
    {
        if(random[i][j][k][l][m]==search_ID)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Accountant:"<<all_employee_names[i][j][k][l][m]<<endl;
            pause;
        }

    }
}
else if(IsType==2)
{
cout<<setw(7)<<"\n\t\t\t\t\t\t\t   Enter ID:LES-_______\b\b\b\b\b\b\b";
cin>>search_ID;

    for(int i=0,j=1,k=0,l=0,m=0;j<customer_gate;j++)
    {
        if(random[i][j][k][l][m]==search_ID)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Customer:"<<all_employee_names[i][j][k][l][m]<<endl;
            pause;
        }

    }
}
else if(IsType==3)
{
cout<<setw(7)<<"\n\t\t\t\t\t\t\t   Enter ID:SOR-_______\b\b\b\b\b\b\b";
cin>>search_ID;

    for(int i=0,j=0,k=1,l=0,m=0;k<manager_gate;k++)
    {
        if(random[i][j][k][l][m]==search_ID)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Manager:"<<all_employee_names[i][j][k][l][m]<<endl;
            pause;
        }

    }

}
else if(IsType==4)
{
cout<<setw(7)<<"\n\t\t\t\t\t\t\t   Enter ID:LPQ-_______\b\b\b\b\b\b\b";
cin>>search_ID;

    for(int i=0,j=0,k=0,l=1,m=0;l<tech_gate;l++)
    {
        if(random[i][j][k][l][m]==search_ID)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Technical Staff Worker:"<<all_employee_names[i][j][k][l][m]<<endl;
            pause;
        }

    }

}
else if(IsType==5)
{
cout<<setw(7)<<"\n\t\t\t\t\t\t\t   Enter ID:NNC-_______\b\b\b\b\b\b\b";
cin>>search_ID;

    for(int i=0,j=0,k=1,l=0,m=1;m<regular_gate;m++)
    {
        if(random[i][j][k][l][m]==search_ID)
        {
            cout<<"ID FOUND!!"<<endl;
            cout<<"Name of Regular Staff Worker:"<<all_employee_names[i][j][k][l][m]<<endl;
            pause;
        }

    }

}
IsType=7;
}
void ID::Regular_Staff_ID()
{
if (regular_gate==0)
{   
    no_of_regular_staff+=1;
    all_employee_names_str_initializer();
    randomizer_int_initializer();
    regular_gate=no_of_regular_staff;
        for(int i=0,j=0,k=0,l=0,m=1;m<no_of_regular_staff;m++)
        {
            cout<<"Enter Regular Staff Employee Name#"<<m<<":\n";
            if(m==1)
            ig;
            srand(time(0)+m);
            getline(cin, all_employee_names[i][j][k][l][m]);
            random[i][j][k][l][m]=rand() % (regular_gate+1999999);
        }
}
else 
    {  
    randomizer_int_initializer();
    all_employee_names_str_initializer();
        for(int i=0,j=0,k=0,l=0,m=regular_gate;m<regular_gate+no_of_regular_staff;m++)
        {
            cout<<"Enter Regular Staff Employee Name#"<<m-regular_gate+1<<":\n";
            if(m==regular_gate)
            ig;
            srand(time(0)+m);
            getline(cin, all_employee_names[i][j][k][l][m]);
            random[i][j][k][l][m]=rand() % (regular_gate+1999999);
        }
    regular_gate+=no_of_regular_staff;

    }



}
void ID::Tech_Staff_ID()
{

if (tech_gate==0 )
{   
    no_of_tech_staff+=1;
    all_employee_names_str_initializer();
    randomizer_int_initializer();
    tech_gate=no_of_tech_staff;
        for(int i=0,j=0,k=0,l=1,m=0;l<no_of_tech_staff;l++)
        {
            cout<<"Enter Tech Staff Employee Name#"<<l<<":\n";
            if(l==1)
            ig;
            srand(time(0)+l);
             getline(cin, all_employee_names[i][j][k][l][m]);
             random[i][j][k][l][m]=rand() % (tech_gate+1999999);
        }
}
else 
    {  
    randomizer_int_initializer();
    all_employee_names_str_initializer();
        for(int i=0,j=0,k=0,m=0,l=tech_gate;l<tech_gate+no_of_tech_staff;l++)
        {
            cout<<"Enter Tech Staff Employee Name#"<<l-tech_gate+1<<":\n";
            if(l==tech_gate)
            ig;
            srand(time(0)+l);
            getline(cin, all_employee_names[i][j][k][l][m]);
            random[i][j][k][l][m]=rand() % (tech_gate+1999999);
        }
    tech_gate+=no_of_tech_staff;

}


}
void ID::Manager_ID()
{
    if (manager_gate==0)
    {   
    no_of_managers+=1;
    all_employee_names_str_initializer();
    randomizer_int_initializer();
    manager_gate=no_of_managers;
        for(int i=0,j=0,k=1,l=0,m=0;k<no_of_managers;k++)
        {
            cout<<"Enter Manager Name#"<<k<<":\n";
            if(k==1)
            ig;
            srand(time(0)+k);
            getline(cin, all_employee_names[i][j][k][l][m]);
            random[i][j][k][l][m]=rand() % (manager_gate+1999999);
        }
    }
else 
    {  
    randomizer_int_initializer();
    all_employee_names_str_initializer();
        for(int i=0,j=0,l=0,m=0,k=manager_gate;k<manager_gate+no_of_managers;k++)
        {
            cout<<"Enter Manager Name#"<<k-manager_gate+1<<":\n";
            if(k==manager_gate)
            ig;
            srand(time(0)+k);
            getline(cin, all_employee_names[i][j][k][l][m]);
            random[i][j][k][l][m]=rand() % (manager_gate+1999999);

        }
    manager_gate+=no_of_managers;

    }

}
void ID::Customer_ID()
{
    if (customer_gate==0)
    {   
        no_of_customers+=1;
        all_employee_names_str_initializer();
        randomizer_int_initializer();
        customer_gate=no_of_customers;
            for(int i=0,j=1,k=0,l=0,m=0;j<no_of_customers;j++)
            {
                cout<<"Enter Customer Name#"<<j<<":\n";
                if(j==1)
                ig;
                srand(time(0)+j);
                getline(cin, all_employee_names[i][j][k][l][m]);
                random[i][j][k][l][m]=rand() % (accountant_gate+1999999);
            }
    }
else 
    {  
    randomizer_int_initializer();
    all_employee_names_str_initializer();
        for(int i=0,k=0,l=0,m=0,j=customer_gate;j<customer_gate+no_of_customers;j++)
        {
            cout<<"Enter Customer Name#"<<j-customer_gate+1<<":\n";
            if(j==customer_gate)
            ig;
            srand(time(0)+j);
            getline(cin, all_employee_names[i][j][k][l][m]);
            random[i][j][k][l][m]=rand() % (customer_gate+1999999);

    }
    customer_gate+=no_of_customers;

}

}

void ID::Accountant_ID()
{
    if (accountant_gate==0)
    {   
    no_of_accountants+=1;
    all_employee_names_str_initializer();
    randomizer_int_initializer();
    accountant_gate=no_of_accountants;
        for(int i=1,j=0,k=0,l=0,m=0;i<no_of_accountants;i++)
        {
            cout<<"Enter Accountant Name#"<<i<<":\n";
            if(i==1)
            ig;
            srand(time(0)+i);
            getline(cin, all_employee_names[i][j][k][l][m]);
            random[i][j][k][l][m]=rand() % (accountant_gate+1999999);
        }
    }
else 
    {  
    randomizer_int_initializer();
    all_employee_names_str_initializer();
        for(int k=0,j=0,l=0,m=0,i=accountant_gate;i<accountant_gate+no_of_accountants;i++)
        {
            cout<<"Enter Accountant Name#"<<i-accountant_gate+1<<":\n";
            if(i==accountant_gate)
            ig;
            srand(time(0)+i);
            getline(cin, all_employee_names[i][j][k][l][m]);
            random[i][j][k][l][m]=rand() % (accountant_gate+1999999);
        }
    accountant_gate+=no_of_accountants;

}


}
void ID::PUT_ID_IN(string *a, int y, int x)
{
IsType=x;
    if(IsType==1)
    {        
    no_of_accountants=y;
    if (accountant_gate==0)
    {   
        no_of_accountants+=1;
        all_employee_names_str_initializer();
        randomizer_int_initializer();
        accountant_gate=no_of_accountants;
        for(int i=1,j=0,k=0,l=0,m=0;i<no_of_accountants;i++)
        { 
            srand(time(0)+i+13);
            all_employee_names[i][j][k][l][m]=a[i-1];
            random[i][j][k][l][m]=rand() % (no_of_accountants+1999999);
        }
    }
    else 
    {  
        randomizer_int_initializer();
        all_employee_names_str_initializer();
        for(int k=0,j=0,l=0,m=0,i=accountant_gate;i<accountant_gate+no_of_accountants;i++)
        {
             srand(time(0)+i+13);
             all_employee_names[i][j][k][l][m]=a[i-accountant_gate];
             random[i][j][k][l][m]=rand() % (no_of_accountants+1999999);
        }
    accountant_gate+=no_of_accountants;
    }
    }
/////////////////////////////////////////////////////////////////////////////
else if(IsType==2)
{
    no_of_customers=y;
    if (customer_gate==0)
    {  
        no_of_customers+=1;
        all_employee_names_str_initializer();
        randomizer_int_initializer();
        customer_gate=no_of_customers;
            for(int i=0,j=1,k=0,l=0,m=0;j<no_of_customers;j++)
            { 
                srand(time(0)+j+2);
                all_employee_names[i][j][k][l][m]=a[j-1];     
                random[i][j][k][l][m]=rand() % (no_of_customers+1999999);
            }
    }
else 
    {  
        randomizer_int_initializer();
        all_employee_names_str_initializer();
        for(int i=0,k=0,l=0,m=0,j=customer_gate;j<customer_gate+no_of_customers;j++)
        {       
            srand(time(0)+j+2);
            all_employee_names[i][j][k][l][m]=a[j-customer_gate];
            random[i][j][k][l][m]=rand() % (no_of_customers+1999999);
        }
    customer_gate+=no_of_customers;

    }   
}
//////////////////////////////////////////////////////////////
else if(IsType==3)
{
    no_of_managers=y;
    if (manager_gate==0)
    { 
        no_of_managers+=1;
        all_employee_names_str_initializer();
        randomizer_int_initializer();
        manager_gate=no_of_managers;
            for(int i=0,j=0,k=1,l=0,m=0;k<no_of_managers;k++)
            { 
                srand(time(0)+k+6);
                all_employee_names[i][j][k][l][m]=a[k-1];
                random[i][j][k][l][m]=rand() % (no_of_managers+1999999);
            }
    }
else 
    {  
        randomizer_int_initializer();
        all_employee_names_str_initializer();
        for(int i=0,j=0,l=0,m=0,k=manager_gate;k<manager_gate+no_of_managers;k++)
        { 
            srand(time(0)+k+6);
            all_employee_names[i][j][k][l][m]=a[k-manager_gate];
            random[i][j][k][l][m]=rand() % (no_of_managers+1999999);
        }
    manager_gate+=no_of_managers;
    }   
}
else if(IsType==4)
{
    no_of_tech_staff=y;
    if (tech_gate==0)
    {   
        no_of_tech_staff+=1;
        all_employee_names_str_initializer();
        randomizer_int_initializer();
        tech_gate=no_of_tech_staff;
        for(int i=0,j=0,k=0,l=1,m=0;l<no_of_tech_staff;l++)
        { 
            srand(time(0)+l+19);
            all_employee_names[i][j][k][l][m]=a[l-1];
            random[i][j][k][l][m]=rand() % (no_of_tech_staff+1999999);
        }
    }
else 
    {   
        randomizer_int_initializer();
        all_employee_names_str_initializer();
        for(int i=0,j=0,k=0,m=0,l=tech_gate;l<tech_gate+no_of_tech_staff;l++)
        {
            srand(time(0)+l+19);
            all_employee_names[i][j][k][l][m]=a[l-tech_gate];
            random[i][j][k][l][m]=rand() % (no_of_tech_staff+1999999);
        }
        tech_gate+=no_of_tech_staff;
    }
}
else if(IsType==5)
{
    no_of_regular_staff=y;
    if (regular_gate==0)
    {   
        no_of_regular_staff+=1;
        all_employee_names_str_initializer();
        randomizer_int_initializer();
        regular_gate=no_of_regular_staff;
        for(int i=0,j=0,k=0,l=0,m=1;m<no_of_regular_staff;m++)
        { 
            srand(time(0)+m+27);
            all_employee_names[i][j][k][l][m]=a[m-1];
            random[i][j][k][l][m]=rand() % (no_of_regular_staff+1999999);
        }
    }
else 
    {  
        randomizer_int_initializer();
        all_employee_names_str_initializer();
        for(int i=0,j=0,k=0,l=0,m=regular_gate;m<regular_gate+no_of_regular_staff;m++)
        {
            srand(time(0)+m+27);
            all_employee_names[i][j][k][l][m]=a[m-regular_gate];
            random[i][j][k][l][m]=rand() % (no_of_regular_staff+1999999);
        }
        regular_gate+=no_of_regular_staff;
    }
}
}

ID::ID(string *a, int y, int x)
{
PUT_ID_IN(a,y,x);
}
void ID::Accountant_print()
{
cout<<setw(50)<<setfill(' ')<<"Accountant Names:"<<setw(53)<<setfill(' ')<<"ID Number:"<<endl;
    for(int i=1,j=0,k=0,l=0,m=0;i<accountant_gate;i++)
    cout<<setw(50)<<setfill(' ')<<all_employee_names[i][j][k][l][m]<<setw(50)<<setfill(' ')<<"SRS-"<<random[i][j][k][l][m]<<endl;
}
void ID::Customer_print()
{
    cout<<setw(50)<<setfill(' ')<<"Customer Names:"<<setw(53)<<setfill(' ')<<"ID Number:"<<endl;
    for(int i=0,j=1,k=0,l=0,m=0;j<customer_gate;j++)
    cout<<setw(50)<<setfill(' ')<<all_employee_names[i][j][k][l][m]<<setw(50)<<setfill(' ')<<"LES-"<<random[i][j][k][l][m]<<endl;
}
void ID::Manager_print()
{
    cout<<setw(50)<<setfill(' ')<<"Manager Names:"<<setw(53)<<setfill(' ')<<"ID Number:"<<endl;
    for(int i=0,j=0,k=1,l=0,m=0;k<manager_gate;k++)
    cout<<setw(50)<<setfill(' ')<<all_employee_names[i][j][k][l][m]<<setw(50)<<setfill(' ')<<"SOR-"<<random[i][j][k][l][m]<<endl;
}
void ID::Tech_Staff_print()
{
cout<<setw(50)<<setfill(' ')<<"Technical Department Staff Names:"<<setw(53)<<setfill(' ')<<"ID Number:"<<endl;
    for(int i=0,j=0,k=0,l=1,m=0;l<tech_gate;l++)
    cout<<setw(50)<<setfill(' ')<<all_employee_names[i][j][k][l][m]<<setw(50)<<setfill(' ')<<"LPQ-"<<random[i][j][k][l][m]<<endl;
}
void ID::Regular_Staff_print()
{
cout<<setw(50)<<setfill(' ')<<"Regular Staff Names:"<<setw(53)<<setfill(' ')<<"ID Number:"<<endl;
    for(int i=0,j=0,k=0,l=0,m=1;m<regular_gate;m++)
    cout<<setw(50)<<setfill(' ')<<all_employee_names[i][j][k][l][m]<<setw(50)<<setfill(' ')<<"NNC-"<<random[i][j][k][l][m]<<endl;
}

void ID::ID_printer()
{
if(IsType==1)
{
    Accountant_print();
}
else if(IsType==2)
{
    Customer_print();
}
else if(IsType==3)
{
     Manager_print();
}
else if(IsType==4)
{
     Tech_Staff_print();
}
else if(IsType==5)
{
    Regular_Staff_print();
}

}



void ID::selector()
{
if(IsType==1)
{
    clear;
    cout<<"Enter Number of Accountants who's ID you would like to generate:"<<endl;
    cin>>no_of_accountants;
    Accountant_ID();
}

else if(IsType==2)
{   
    clear;
    cout<<"Enter Number of Customers who's ID you would like to generate:"<<endl;
    cin>>no_of_customers;   
    Customer_ID();
}
else if(IsType==3)
{
    clear;
    cout<<"Enter Number of Managers who's ID you would like to generate:"<<endl;
    cin>>no_of_managers;
    Manager_ID();
}
else if(IsType==4)
{
    clear;
    cout<<"Enter Number of Technical Department Employees who's ID you would like to generate:"<<endl;
    cin>>no_of_tech_staff;
    Tech_Staff_ID();
}
else if(IsType==5)
{
    clear;
    cout<<"Enter Number of Regular Staff Employees who's ID you would like to generate:"<<endl;
    cin>>no_of_regular_staff;
    Regular_Staff_ID();
}


}

void ID::staff_decision_split()
{
    repeat_ID_check:
    clear;
    cout<<"\t\t\t\t\t\t\t\t<<<Staff Members List>>>"<<endl;
    cout<<"\t\t\t\t\t\t\t   Would you like to generate ID for:\n\t\t\t\t\t\t\t\t1.Accountant.\n\t\t\t\t\t\t\t\t2.Customer.\n\t\t\t\t\t\t\t\t3.Manager.\n\t\t\t\t\t\t\t\t4.Tech Staff.\n\t\t\t\t\t\t\t\t5.Regular Staff.\n\t\t\t\t\t\t\t\t6.All staff."<<endl;
    cin>>IsType;
    if(IsType<1 && IsType>6)
    goto repeat_ID_check;

    selector();

}

ID::~ID()
{
    delete [] all_employee_names, random;
}

ID::ID()
{
    IsType=1;
    random=new int****[1];
    all_employee_names=new string****[1];
    no_of_accountants=1;no_of_customers=1;no_of_managers=1;no_of_tech_staff=1;no_of_regular_staff=1;
}
void ID::all_employee_names_str_initializer()
{
    if (accountant_gate==0 && customer_gate==0 && manager_gate==0 && tech_gate==0 && regular_gate==0)
    {
        string *****x= new string****[no_of_accountants];
    
    for(int i=0;i<no_of_accountants;i++)
        x[i]=new string***[no_of_customers];
    
    for(int i=0;i<no_of_accountants;i++)
        for(int j=0;j<no_of_customers;j++)
            x[i][j]=new string**[no_of_managers];

    for(int i=0;i<no_of_accountants;i++)
        for(int j=0;j<no_of_customers;j++)
            for(int k=0;k<no_of_managers;k++)
            x[i][j][k]=new string*[no_of_tech_staff];

    for(int i=0;i<no_of_accountants;i++)
        for(int j=0;j<no_of_customers;j++)
            for(int k=0;k<no_of_managers;k++)
                for(int l=0;l<no_of_tech_staff;l++)
                    x[i][j][k][l]=new string[no_of_regular_staff];
    
     all_employee_names=x;
    }
    else
    { 
    string *****x= new string****[no_of_accountants+accountant_gate];
    for(int i=0;i<no_of_accountants+accountant_gate;i++)
        x[i]=new string***[no_of_customers+customer_gate];
    
    for(int i=0;i<no_of_accountants+accountant_gate;i++)
        for(int j=0;j<no_of_customers+customer_gate;j++)
            x[i][j]=new string**[no_of_managers+manager_gate];

    for(int i=0;i<no_of_accountants+accountant_gate;i++)
        for(int j=0;j<no_of_customers+customer_gate;j++)
            for(int k=0;k<no_of_managers+manager_gate;k++)
            x[i][j][k]=new string*[no_of_tech_staff+tech_gate];

    for(int i=0;i<no_of_accountants+accountant_gate;i++)
        for(int j=0;j<no_of_customers+customer_gate;j++)
            for(int k=0;k<no_of_managers+manager_gate;k++)
                for(int l=0;l<no_of_tech_staff+tech_gate;l++)
                    x[i][j][k][l]=new string[no_of_regular_staff+regular_gate];


for(int i=1,j=0,k=0,l=0,m=0;i<accountant_gate;i++)
{
    x[i][j][k][l][m]=all_employee_names[i][j][k][l][m];
}


for(int i=0,j=1,k=0,l=0,m=0;j<customer_gate;j++)
{
    x[i][j][k][l][m]=all_employee_names[i][j][k][l][m];
}


for(int i=0,j=0,k=1,l=0,m=0;k<manager_gate;k++)
{
    x[i][j][k][l][m]=all_employee_names[i][j][k][l][m];
}

for(int i=0,j=0,k=0,l=1,m=0;l<tech_gate;l++)
{
    x[i][j][k][l][m]=all_employee_names[i][j][k][l][m];
}


for(int i=0,j=0,k=0,l=0,m=1;m<regular_gate;m++)
{
    x[i][j][k][l][m]=all_employee_names[i][j][k][l][m];
}

all_employee_names=x;
}
    


}
void ID::randomizer_int_initializer()
{
    if (accountant_gate==0 && customer_gate==0 && manager_gate==0 && tech_gate==0 && regular_gate==0)
    {
    int *****x= new int****[no_of_accountants];
    for(int i=0;i<no_of_accountants;i++)
        x[i]=new int***[no_of_customers];

    for(int i=0;i<no_of_accountants;i++)
        for(int j=0;j<no_of_customers;j++)
            x[i][j]=new int**[no_of_managers];

    for(int i=0;i<no_of_accountants;i++)
        for(int j=0;j<no_of_customers;j++)
            for(int k=0;k<no_of_managers;k++)
            x[i][j][k]=new int*[no_of_tech_staff];

    for(int i=0;i<no_of_accountants;i++)
        for(int j=0;j<no_of_customers;j++)
            for(int k=0;k<no_of_managers;k++)
                for(int l=0;l<no_of_tech_staff;l++)
                    x[i][j][k][l]=new int[no_of_regular_staff];
                   
                   
random=x;
    }
else{
    int *****x= new int****[no_of_accountants+accountant_gate];
    
    for(int i=0;i<no_of_accountants+accountant_gate;i++)
        {x[i]=new int***[no_of_customers+customer_gate];}
    
    for(int i=0;i<no_of_accountants+accountant_gate;i++)
        for(int j=0;j<no_of_customers+customer_gate;j++)
            {x[i][j]=new int**[no_of_managers+manager_gate];}

    for(int i=0;i<no_of_accountants+accountant_gate;i++)
        for(int j=0;j<no_of_customers+customer_gate;j++)
            for(int k=0;k<no_of_managers+manager_gate;k++)
            {x[i][j][k]=new int*[no_of_tech_staff+tech_gate];}

    for(int i=0;i<no_of_accountants+accountant_gate;i++)
        for(int j=0;j<no_of_customers+customer_gate;j++)
            for(int k=0;k<no_of_managers+manager_gate;k++)
                for(int l=0;l<no_of_tech_staff+tech_gate;l++)
                   { x[i][j][k][l]=new int[no_of_regular_staff+regular_gate];}



for(int i=1,j=0,k=0,l=0,m=0;i<accountant_gate;i++)
{
    x[i][j][k][l][m]=random[i][j][k][l][m];
}


for(int i=0,j=1,k=0,l=0,m=0;j<customer_gate;j++)
{
    x[i][j][k][l][m]=random[i][j][k][l][m];
}


for(int i=0,j=0,k=1,l=0,m=0;k<manager_gate;k++)
{
    x[i][j][k][l][m]=random[i][j][k][l][m];
}


for(int i=0,j=0,k=0,l=1,m=0;l<tech_gate;l++)
{
    x[i][j][k][l][m]=random[i][j][k][l][m];
}


for(int i=0,j=0,k=0,l=0,m=1;m<regular_gate;m++)
{
    x[i][j][k][l][m]=random[i][j][k][l][m];
}

random=x;
}

}

