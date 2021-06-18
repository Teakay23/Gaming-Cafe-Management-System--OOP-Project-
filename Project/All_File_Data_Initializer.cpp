#include"Password.h"
// #include"ScheduleWorker.h"
#include"Visuals.h"
#include"Complex_ID.h"
#include"Person.h"
// #include "Foodmenu.h"
int main()
{
string Account[5]={"Sappa", "Calsie", "Normus", "Henry Cavern", "Sherepie Cocktail"};
string Customer[5]={"Henry", "Bob", "Debbie", "Mocktel", "Shivonni"};
string Manager[3]={"Adrian", "Corner", "Sappa"};
string Tech[2]={"Sorper", "Mejjie"};
string Regular[6]={"Sora", "Dianna", "Dillan", "Morper", "Hejkin", "Sheksin"};
string Default_Tasks[5]={"None Assigned", "None Assigned", "None Assigned", "None Assigned", "STILL NOT ASSIGNED!"};
string Passwords[6]={"12345", "Elephant Boy", "Mockpie997", "Shelbie", "doorman998","Caller990"};
char genders[6]={'F','M','M','F','F','M'};
int ages[6]={54,23,54,21,54,76};
string country[6]={"France", "Spain", "Arkansas", "USA", "China", "India"};
string a[10] = {"Cookies", "Apple Pie", "Pudding", "Cake", "Muffins", "Hot Corns", "Baked Potatoe", "Pepperoni", "Ice Cream", "Salad" };		
double c[10] = {75, 250, 150, 1000, 1500, 200, 400, 780, 200, 150};	

// food f;
// f.Extract_from_file();
// cout<<f;

ID ID;
ID.PUT_ID_IN(Account,5,1);
ID.PUT_ID_IN(Customer,5,2);
ID.PUT_ID_IN(Manager,3,3);
ID.PUT_ID_IN(Tech,2,4);
ID.PUT_ID_IN(Regular,6,5);
// ID.EXTRACT_FROM_FILE();
ID=1;
cout<<ID;
ID=2;
cout<<ID;
ID=3;
cout<<ID;
ID=4;
cout<<ID;
ID=5;
cout<<ID;
ID.INSERT_IN_FILE();

// Schedule Workers;
// Workers.GetParticipaints(Account,Default_Tasks,5,5);
// Workers.INPUT_SCHEDULE_FILE(1);
// Workers.GetParticipaints(Customer,Default_Tasks,5,5);
// Workers.INPUT_SCHEDULE_FILE(2);
// Workers.GetParticipaints(Manager,Default_Tasks,3,5);
// Workers.INPUT_SCHEDULE_FILE(3);
// Workers.GetParticipaints(Tech,Default_Tasks,2,5);
// Workers.INPUT_SCHEDULE_FILE(4);
// Workers.GetParticipaints(Regular,Default_Tasks,6,5);
// Workers.INPUT_SCHEDULE_FILE(5);
// Workers.EXTRACT_SCHEDULE_FILE(1);
// Workers=2;
// cout<<Workers;

Password People;
People.Insert_Info(Account, Passwords, 5, 1);
People.Insert_Info(Customer, Passwords, 5, 2);
People.Insert_Info(Manager, Passwords, 3, 3);
People.Insert_Info(Tech, Passwords, 2, 4);
People.Insert_Info(Regular, Passwords, 6, 5);

Person Person;
Person.Insert_Info(Account, genders, ages, country, 5,1);
Person.Insert_Info(Customer, genders, ages, country, 5,2);
Person.Insert_Info(Manager, genders, ages, country, 3,3);
Person.Insert_Info(Tech, genders, ages, country, 5,4);
Person.Insert_Info(Regular, genders, ages, country, 6,5);



}