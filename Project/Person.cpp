#include"Manager.h"
#include"Person.h"
int intlength(int a)
{   
    int count=0;
    again:
    a=a/10;
    count++;
    if(a!=0)
    goto again;
    return count;
}
string Person::return_name()
{
    return name;
}
void Person::remove_all_personal_data(string username,string password,int b)
{   
    ofstream temp_deletion("temp.dat");
    temp_deletion.seekp(0);
    ifstream extract2(participants[b-1], ios::out);
    extract2.seekg(0);
    string temp_pass_name, temp_pass;
    ifstream extract(file_name[b-1], ios::out);
    extract.seekg(0);
    do{
        getline(extract2, temp_pass_name, '\0');
        getline(extract2, temp_pass, '\0');
        getline(extract, this->name, '\0');
        extract>>gender;
        extract>>age;
        getline(extract, this->city, '\0');
        if(!extract.good())
        break;
        
        if(temp_pass_name!=username ||  temp_pass != password)
        {
            temp_deletion.write(this->name.c_str(), this->name.length()+1);
            temp_deletion<<gender;
            temp_deletion<<age;
            temp_deletion.write(this->city.c_str(), this->city.length()+1);
        }
    }while(extract.good());
    extract.close();
    extract2.close();
    temp_deletion.close();
    remove((file_name[b-1]).c_str());
    rename("temp.dat",(file_name[b-1]).c_str());

}

string Person::return_name(string username, string password, int b)
{
    ifstream extract2(participants[b-1], ios::out);
    extract2.seekg(0);
    string temp_pass_name, temp_pass;
    ifstream extract(file_name[b-1], ios::out);
    extract.seekg(0);
    do{
        getline(extract2, temp_pass_name, '\0');
        getline(extract2, temp_pass, '\0');
        getline(extract, this->name, '\0');
        extract>>gender;
        extract>>age;
        getline(extract, this->city, '\0');
        if(!extract.good())
        break;
        
        if(temp_pass_name==username &&  temp_pass == password)
        {
            return name;
        }
    }while(extract.good());
    return "NULL";
}
string Person::return_name(string username, int b)
{
    ifstream extract2(participants[b-1], ios::out);
    extract2.seekg(0);
    string temp_pass_name, temp_pass;
    ifstream extract(file_name[b-1], ios::out);
    extract.seekg(0);
    do{
        getline(extract2, temp_pass_name, '\0');
        getline(extract2, temp_pass, '\0');
        getline(extract, this->name, '\0');
        extract>>gender;
        extract>>age;
        getline(extract, this->city, '\0');
        if(!extract.good())
        break;
        
        if(temp_pass_name==username)
        {
            return name;
        }
    }while(extract.good());
    return "NULL";
}
void Person::get_details(int a)
{
    cout<<a;
    clear;
    nam:
    cout<<"Enter your name (Length between 1-32):";
    getline(cin,name);
    if(name.length()<1 || name.length()>32)
    goto nam;
    gend:
    cout<<"Enter your gender (M/F):";
    cin>>gender;
    if(gender=='M' || gender=='m' || gender=='f' || gender=='F')
    {}
    else 
    goto gend;
    age:
    cout<<"Enter age:";
    cin>>age;
    if(age<0 || age>105)
    goto age;
    cin.ignore();
    city:
    cout<<"Enter your city of birth:";
    getline(cin,city);
    if(city.length()<1 || city.length()>45)
    goto city;
    cin.ignore();
    string temp_name[1];
    temp_name[0]=name;
    cin_name=name;
    char temp_gender[1];
    temp_gender[0]=gender;
    int temp_age[1];
    temp_age[0]=age;
    string temp_city[1];
    temp_city[0]=city;
    Append_Info(temp_name,temp_gender,temp_age,temp_city,1,a);

}
void Person::Print_Info()
{
    clear;
     V.person_details_display();

cout<<"\t\t            ____/   Personal         452\\ /   Details         453\\____ "<<endl;
cout<<"\t\t          /| ---------------------------  |  ------------------------  |\\"<<endl;
cout<<"\t\t         ||| Name:----------------------  |  "<<name<<setw(29-name.length())<<setfill('-')<<"   |||"<<endl;
cout<<"\t\t         ||| ---------------------------  |  ------------------------  |||"<<endl;
cout<<"\t\t         ||| ---------------------------  |  ------------------------  |||"<<endl;
cout<<"\t\t    -----||| Gender:--------------------  |  "<<gender<<setw(28)<<setfill('-') <<"  |||"<<endl;
cout<<"\t\t    |    ||| ---------------------------  |  ------------------------  |||"<<endl;
cout<<"\t\t    |    ||| ---------------------------  |  ------------------------  |||"<<endl;
cout<<"\t\t    |    ||| Age:-----------------------  |  "<<age<<setw(29-intlength(age))<<setfill('-')<<"   |||"<<endl;
cout<<"\t\t    |    ||| ---------------------------  |  ------------------------  |||"<<endl;
cout<<"\t\t    |    ||| ---------------------------  |  ------------------------  |||"<<endl;
cout<<"\t\t    |    ||| City of Birth:-------------  |  "<<city<<setw(29-city.length())<<setfill('-')<<"  |||"<<endl;
cout<<"\t\t    |    ||| ---------------------------  |  ------------------------  |||"<<endl;
cout<<"\t\t    |    ||| ---------------------------  |  ------------------------  |||"<<endl;
cout<<"\t\t    |    ||| ---------------------------  |  ------------------------  |||"<<endl;
cout<<"\t\t    |    ||| ---------------------------  |  ------------------------  |||"<<endl;
cout<<"\t\t    |    ||| ---------------------------  |  ------------------------  |||"<<endl;
cout<<"\t\t    |     L/______________/--------------\\_//-------------\\______________\\J"<<endl;

    
cout<<"\t\t    |\t   ___________________________________________________"<<endl;
cout<<"\t\t    |\t   |         <<<<<<PERSONAL DETAILS>>>>>>>>          |"<<endl;
cout<<"\t\t    |\t   |_________________________________________________|"<<endl;
cout<<"\t\t    |\t   | Name:"<<name<<setw(44-name.length())<<setfill(' ')<<"|"<<endl;
cout<<"\t\t    '--->  | Gender:"<<gender<<setw(41)<<setfill(' ')<<'|'<<endl;
cout<<"\t\t\t   | Age:"<<age<<setw(45-intlength(age))<<setfill(' ')<<"|"<<endl;
cout<<"\t\t\t   | City:"<<city<<setw(44-city.length())<<setfill(' ')<<"|"<<endl;
cout<<"\t\t\t   |_________________________________________________|"<<endl;
    pause;

}
void Person::Get_Info(string username, string password, int b)
{
   
    ifstream extract2(participants[b-1], ios::out);
    extract2.seekg(0);
    string temp_pass_name, temp_pass;
    ifstream extract(file_name[b-1], ios::out);
    extract.seekg(0);
    do{
        getline(extract2, temp_pass_name, '\0');
        getline(extract2, temp_pass, '\0');
        getline(extract, this->name, '\0');
        extract>>gender;
        extract>>age;
        getline(extract, this->city, '\0');
        if(!extract.good())
        break;
        
        if(temp_pass_name==username &&  temp_pass == password)
        {
            Print_Info();
            break;
        }
    }while(extract.good());

}
void Person::Append_Info(string *a, char *b, int *c, string *d, int beg, int e)
{

    ofstream insert(file_name[e-1], ios::app);
    string temp;
    for(int i=0; i<beg;i++)
    {
        temp=a[i];
        insert.write(temp.c_str(), temp.length()+1);
        insert<<b[i];
        insert<<c[i];
        temp=d[i];
        insert.write(temp.c_str(), temp.length()+1);
    }
}
void Person::Insert_Info(string *a, char *b, int *c, string *d, int beg, int e)
{
    ofstream insert(file_name[e-1]);
    string temp;
    for(int i=0; i<beg;i++)
    {
        temp=a[i];
        insert.write(temp.c_str(), temp.length()+1);
        insert<<b[i];
        insert<<c[i];
        temp=d[i];
        insert.write(temp.c_str(), temp.length()+1);
    }

}