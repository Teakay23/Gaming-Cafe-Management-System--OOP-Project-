#include"Password.h"
void Password::delete_ID(string a,string b, int c)
{
     string filestring[5]={"Accountant.dat", "Customer.dat", "Manager.dat", "Tech.dat", "Regular.dat"};
  
    c-=1;
    ID ID;
    ID.EXTRACT_FROM_FILE();
//////////////////////ID REMOVAL////////////////////////////////
    // clear;
    // int reg=0,random;
    // ifstream file("ID.dat", ios::out);
    // file.seekg(0);
    // int temp=file.tellg();
    // file.seekg(temp+(sizeof(int))*c);
    // file.read((char*)(&reg), sizeof(reg));
    // file.close();
    // cout<<reg;
    // pause;
    // ofstream file2("ID.dat", ios::in);
    // file2.seekp(0);
    // temp=file2.tellp();
    // file2.seekp(temp+(sizeof(int))*c);
    // reg--;
    // file2.write(reinterpret_cast<char *>(&reg), sizeof(reg));
    // file2.close();

    string namae;
    int ban;

    ifstream extract2(participants[c], ios::out);
    extract2.seekg(0);
    string temp_pass_name, temp_pass;
    ifstream extract(filestring[c], ios::out);
    extract.seekg(0);
    do{
        getline(extract2, temp_pass_name, '\0');
        getline(extract2, temp_pass, '\0');
        getline(extract, namae, '\0');
        extract>>ban;
        if(temp_pass_name==a && temp_pass == b)
        {
            clear;
            ID.Delete_ID(namae,ban);
            ID.INSERT_IN_FILE();
            return;
        }
    }while(extract2.good());
    extract.close();
    extract2.close();
}
void Password::delete_password(string a,string b, int c)
{
    c--;
    ofstream temp_deletion("temp.dat");
    temp_deletion.seekp(0);
    ifstream pass(participants[c]);
    pass.seekg(0);
    do{
        getline(pass, name, '\0');
        getline(pass, password, '\0');
        if(!pass.good())
        break;
        if(a!=name || b!=password)
        {
            temp_deletion.write(name.c_str(), name.length()+1);
            temp_deletion.write(password.c_str(),password.length()+1);
        }

    }while(pass.good());
    temp_deletion.close();
    pass.close();
    remove(participants[c].c_str());
    rename("temp.dat",participants[c].c_str());
    
}
void Password::Get_Password_From_User(int b)
{
    cin.ignore();
    string tempname,temppass;
    password_name_check:
    cout<<"Enter Your Username(Needs To Be Unique):";
    getline(cin,name);
    for(int i=0;i<5;i++)
    {
    ifstream extract(participants[i], ios::out);
    extract.seekg(0);
    do{
        getline(extract, tempname, '\0');
        getline(extract, temppass, '\0');
        if(tempname==name)
        {
            cout<<"Username Already Present In Directory!"<<endl;
            goto password_name_check;
        }
    }while(extract.good());
    }
    cout<<"Enter Password:";
    getline(cin,password);


    string temp_name[1]=name;
    string temp_password[1]=password;
    Append_Info(temp_name,temp_password,1,b);

}
bool Password::check_password(string a, string b, int c)
{
    c-=1;
    ifstream extract(participants[c]);
    extract.seekg(0);
    do{
        getline(extract, name, '\0');
        getline(extract, password, '\0');
        if(a==name && b==password)
        {
            return true;
        }
    

    }while(extract.good());
return false;
}
void Password::Insert_Info(string* a, string * b,int length, int c)
{
    c-=1;
    ofstream insert(participants[c]);
    string temp;
    for(int i=0; i<length;i++)
    {
        temp=a[i];
        insert.write(temp.c_str(), temp.length()+1);
        temp=b[i];
        insert.write(temp.c_str(), temp.length()+1);
    }
}
void Password::Append_Info(string *a, string *b, int length,int c)
{
    c-=1;
    ofstream insert(participants[c], ios::app);
    string temp;
    for(int i=0; i<length;i++)
    {
        temp=a[i];
        insert.write(temp.c_str(), temp.length()+1);
        temp=b[i];
        insert.write(temp.c_str(), temp.length()+1);
    }
}
