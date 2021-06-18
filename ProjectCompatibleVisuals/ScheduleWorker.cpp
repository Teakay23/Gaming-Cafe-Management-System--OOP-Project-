#include"ScheduleWorker.h"
int day_of_week(int y, int m, int d)
{
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  y -= m < 3;
  return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
string day(int y,int m,int d)
{
    if(day_of_week(y,m,d)==0)
    return "(Sun)";
    if(day_of_week(y,m,d)==1)
    return "(Mon)";
    if(day_of_week(y,m,d)==2)
    return "(Tue)";
    if(day_of_week(y,m,d)==3)
    return "(Wed)";
    if(day_of_week(y,m,d)==4)
    return "(Thu)";
    if(day_of_week(y,m,d)==5)
    return "(Fri)";
    if(day_of_week(y,m,d)==6)
    return "(Sat)";
}
int strlength(string x)
{int count=0;
for(int i=0;x[i]!='\0';i++)
{count++;}
return count;
}
void Schedule::EXTRACT_SCHEDULE_FILE(int a)
{
    ifstream extract(task_save_file[a-1], ios::out);
    extract.seekg(0);
    extract.read((char *)&no_of_workers, sizeof(no_of_workers));
    int***ptr2=new int**[31];
    for(int a=0;a<31;a++)
    {
        ptr2[a]=new int*[no_of_workers];
    }
    for(int b=0;b<31;b++)
    {
        for(int c=0;c<no_of_workers;c++)
            ptr2[b][c]=new int[12];
    }

    random_number=ptr2;
    for(int d=0;d<31;d++)
    {  
        for(int e=0;e<no_of_workers;e++)
        {
            for(int f=0;f<12;f++)
            {   
                extract.read((char *)&random_number[d][e][f], sizeof(random_number[d][e][f]));
            }
        }
    }
    extract.close();
    ifstream extract1(task_file[a-1], ios::out);
    extract1.seekg(0);
    extract1.read((char *)&no_of_tasks,sizeof(no_of_tasks));
    string *p=new string[no_of_tasks];
    string temp;
    for(int z=0;z<no_of_tasks;z++)
    {
        getline(extract1, temp, '\0');
        p[z]=temp;
    }
    tasks=p;
    extract1.close();
    ifstream extract2(worker_file[a-1], ios::out);
    extract2.seekg(0);
    string *ptr=new string[no_of_workers];
    for(int y=0; y<no_of_workers;y++)
    { 
        getline(extract2, temp, '\0');
        ptr[y]=temp;
    }
    workers=ptr;
    extract2.close();
}
void Schedule::INPUT_SCHEDULE_FILE(int a)
{
    ofstream insert(task_save_file[a-1], ios::in);
    insert.write(reinterpret_cast<char *>(&no_of_workers),sizeof(no_of_workers));
    for(int d=0;d<31;d++)
    {
        for(int e=0;e<no_of_workers;e++)
        {
            for(int f=0;f<12;f++)
            {
                insert.write(reinterpret_cast<char *>(&random_number[d][e][f]), sizeof(random_number[d][e][f]));
            }
        }
    }
    insert.close();
    ofstream insert1(task_file[a-1], ios::in);
    insert1.write(reinterpret_cast<char *>(&no_of_tasks),sizeof(no_of_tasks));
    string temp;
    for(int z=0;z<no_of_tasks;z++)
    {   
        temp=tasks[z];
        insert1.write(temp.c_str(), temp.length()+1);
    }
    insert1.close();
    ofstream insert2(worker_file[a-1], ios::in);
    for(int y=0; y<no_of_workers;y++)
    {    
        temp=workers[y];
        insert2.write(temp.c_str(), temp.length()+1);
    }
    insert2.close();
}
void Schedule::GetParticipaints(string* a,int b)
{
    workers=a;
    no_of_workers=b;
    task_arrange();
}
Schedule::Schedule(string *a,int b):workers(a),no_of_workers(b)
{
    task_arrange();
}
void Schedule::randomize()
{
    int***ptr2=new int**[31];
    for(int a=0;a<31;a++)
    {
        ptr2[a]=new int*[no_of_workers];    
    }
    for(int b=0;b<31;b++)
    {
        for(int c=0;c<no_of_workers;c++)
            ptr2[b][c]=new int[12];
    }
    for(int d=0;d<31;d++)
    { 
        for(int e=0;e<no_of_workers;e++)
        {
            for(int f=0;f<12;f++)
            {
                ptr2[d][e][f]=rand() % no_of_tasks+1;
            }
        }
    }
    random_number=ptr2;
}
void Schedule::GetParticipaints(string* a,string* b,int x,int y)
{
    workers=a;
    tasks=b;
    no_of_workers=x;
    no_of_tasks=y;
    randomize();
}
Schedule::Schedule(string *a, string *b, int x, int y):workers(a), tasks(b),no_of_workers(x),no_of_tasks(y)
{
    randomize();
}
void Schedule::operator=(int a)
{
    mon=a-1;
}
istream& operator,(istream& a, Schedule& b)
{
    b.worker_count();
    b.task_arrange();
    return a;
}
istream& operator>>(istream& a, Schedule& b)
{
    b.worker_count();
    b.task_arrange();
    return a;
}
ostream& operator,(ostream& a, Schedule& b)
{
    b.print_schedule(b.mon);
    return a;
}
ostream& operator<<(ostream& a, Schedule& b)
{
    b.print_schedule(b.mon);
    return a;
}
Schedule::~Schedule()
{
    delete [] tasks, month, workers,random_number;
}
void Schedule::print_schedule(int m)
{  
    cout<<"\t\t\t\t\t\t\t\t<<<TASKS ALLOTED>>>"<<endl;
    mon=m;
    cout<<"\t\t\t";
    for(int i=0,counter=1;i<no_of_tasks;i++)
    {
        cout<<i+1<<"."<<setfill('.')<<setw(50)<<tasks[i]<<".  ";
        if(counter==2)
        {
            cout<<"\n"; counter=0;cout<<"\t\t\t";}
            counter++;
        }
    nxt;
    for(int j=0;j<9;j++)
    {
        if(j==0)
        cout<<"               ";
        cout<<"  "<<month[mon]<<"0"<<j+1<<" ";  
    }
    for(int j=9;j<16;j++)
    {
        cout<<"  "<<month[mon]<<j+1<<" ";
    }
    nxt;
    cout<<setfill(' ')<<setw(22);
    for(int j=0;j<16;j++)
    cout<<day(2020,mon+1,j+1)<<setfill(' ')<<setw((strlen(month[mon])+4)/2)<<" "<<setfill(' ')<<setw((strlen(month[mon])+4)/2);
    
   
    for(int j=0;j<no_of_workers;j++)
    {
        string smegma=workers[j];
        cout<<" ";
        nxt;
        cout<<workers[j]<<setfill(' ')<<setw(20-strlength(smegma));
        for(int z=0;z<16;z++)
        {
            if(day(2020,mon+1,z+1)=="(Sun)")
            random_number[z][j][mon]=0;
            cout<<random_number[z][j][mon]<<setfill('_')<<setw((strlen(month[mon])+5)/2)<<"|"<<setfill('_')<<setw((strlen(month[mon])+5)/2);
        }
    }
    cout<<setfill('_')<<setw((strlen(month[mon])+6)/2)<<".";
    /////////////////////////////////////////////////////////////////////////////////////////////
    int days;
    if(mon==0 || mon==2 || mon ==4 || mon==6 || mon ==7 || mon==9 || mon==11)
    {
        days=31;
    }
    else if( mon==3 || mon==5 || mon==8 || mon==10)
    {   
        days=30;
    }
    if(mon==1)
    {
        days=28;
    }
    nxt;
    nxt;
     for(int j=16;j<days;j++)
    {
        if(j==16)
        cout<<"               ";
        cout<<"  "<<month[mon]<<j+1<<" ";
    }

    nxt;
    cout<<setfill(' ')<<setw(22);
    for(int j=16;j<days;j++)
    cout<<day(2020,mon+1,j+1)<<setfill(' ')<<setw((strlen(month[mon])+4)/2)<<" "<<setfill(' ')<<setw((strlen(month[mon])+4)/2);
    for(int j=0;j<no_of_workers;j++)
    {
        string smegma=workers[j];
        cout<<" ";
        nxt;
        cout<<workers[j]<<setfill(' ')<<setw(20-strlength(smegma));
        for(int z=16;z<days;z++)
         {
            if(day(2020,mon+1,z+1)=="(Sun)")
            random_number[z][j][mon]=0;
            cout<<random_number[z][j][mon]<<setfill('_')<<setw((strlen(month[mon])+6)/2)<<"|"<<setfill('_')<<setw((strlen(month[mon])+6)/2);
         }   
    }
    cout<<setfill('_')<<setw((strlen(month[mon])+6)/2)<<".";
    nxt;

}
void Schedule::task_arrange()
{
    loopit:
    cout<<"Number of tasks you would like to enlist to the staff(Can only add tasks up to 9):"<<endl;
    cin>>no_of_tasks;
    if(no_of_tasks>9)
    goto loopit;

    string *p=new string[no_of_tasks];
    for(int z=0;z<no_of_tasks;z++)
    {

        cout<<"Enter Task#"<<z+1<<":";
        if(z==0)
        ig;
        getline(cin,p[z]);
        
    }
    tasks=p;
    randomize();

}
void Schedule::worker_count()
{
    cout<<"Enter the amount of workers for whom you want to design a schedule:";
    cin>>no_of_workers;
     
    string *i=new string[no_of_workers];
    for(int j=0;j<no_of_workers;j++)
    {
        cout<<"Enter Worker Name#0"<<j+1<<":";
        if(j==0)
        ig;

        getline(cin,i[j]);
    }
    workers=i;
}
    Schedule::Schedule()
{
  
}
