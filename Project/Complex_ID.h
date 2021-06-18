#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include<assert.h>
#include<cstdlib>
#include<fstream>
#include <stdio.h> 
#include <stdlib.h> 
#define clear system("cls");
#define ig cin.ignore()
#define nxt cout<<endl
#define pause system("PAUSE")

using namespace std;


class ID
{
    friend ostream& operator<<(ostream&, ID&);
    friend ostream& operator,(ostream&, ID&);
    friend istream& operator>>(istream&, ID&);
    friend istream& operator,(istream&, ID&);

    int IsType=1;
    long int search_ID;
    int *****random;    
    int accountant_gate=0,customer_gate=0,manager_gate=0,tech_gate=0,regular_gate=0;
    int no_of_accountants=1,no_of_customers=1,no_of_managers=1,no_of_tech_staff=1,no_of_regular_staff=1;
    string *****all_employee_names;
    public:
    int  check_password(string b, int a);
    int  return_password(string);
    void operator =(string);
    void operator =(int);
    void randomizer_int_initializer();
    void all_employee_names_str_initializer();
    void ID_Generator();
    void staff_decision_split();
    void selector();
    void Accountant_ID();
    void Customer_ID();
    void Manager_ID();
    void Tech_Staff_ID();
    void Regular_Staff_ID();
    void All_ID();
    void PUT_ID_IN(string *, int, int);
    void ID_printer();
    void Accountant_print();
    void Customer_print();
    void Manager_print();
    void Tech_Staff_print();
    void Regular_Staff_print();
    void Search_ID();
    void Delete_ID(string);
    void Delete_ID(int);
    void Search_ID(string);
    void Delete_ID(string,int);
    void Search_ID(int);
    ID();
    ID(string *,string *,string *,string *,string *);
    ID(string *, int, int);
    ~ID();
    void INSERT_IN_FILE();
    void EXTRACT_FROM_FILE();
    void APPEND_TO_FILE();
};




// int main()
// {

// /*PARAMETER INITIALIZER LIST TAKES THE ARGUEMENT (STRING ARRAY, AMOUNT OF ELEMENTS IN STRING ARRAY, AND TYPE OF EMPLOYEE(1-5))*/

// /*
// Types of IDs:
// 1.Accountant
// 2.Customer
// 3.Manager
// 4.Technical Department Staff
// 5.Regular Staff

// */
// //FOR EXAMPLE:
// string a[2]={"Chell", "Dob"};
// ID ob2(a,2,1); 
// string b[2]={"Anna", "Bob"};
// ob2.PUT_ID_IN(b,2,2);
// ob2.PUT_ID_IN(b,2,3);
// ob2.PUT_ID_IN(b,2,4);
// ob2.PUT_ID_IN(b,2,5);

// ob2.EXTRACT_FROM_FILE();

// ob2=1;
// cout<<ob2;
// ob2=2;
// cout<<ob2;
// ob2=3;
// cout<<ob2;
// ob2=4;
// cout<<ob2;
// ob2=5;
// cout<<ob2;
// cout<<ob2.check_password("Anna",17969);
// pause;

// // cout<<ob2;
// // cout<<"\n\t\t\t--------------------IDs REMAIN THE SAME REGARDLESS OF HOW MANY TIMES YOU OUTPUT.-------------"<<endl;
// // cout<<ob2;
// // cout<<"\n\t\t\t--------------------IDs REMAIN THE SAME REGARDLESS OF HOW MANY TIMES YOU OUTPUT.-------------\n"<<endl;
// // cout<<ob2;

// // /*APPENDING ID METHOD */

// // cout<<"\n\t\t\t\t\t--------------------IDs AFTER BEING APPENDED-------------\n"<<endl;
// // string b[2]={"Vlerka Sopt", "Jhika Moctol"};
// // ob2.PUT_ID_IN(b,2,1);
// // ob2.INSERT_IN_FILE();

// // ID ob3;
// // ob3.EXTRACT_FROM_FILE();
// // cout<<ob3;














// // cout<<ob2;
// // pause;
// // /*ADDING ID BUT IN ANOTHER SECTOR WILL CAUSE THE PRINT VARIABLE TO BE REFERRING TO THE MOST RECENT APPEND, REMEMBER TO RESET IT !*/
// // clear;
// // ID ob3(a,6,5);
// // cout<<ob3;
// // cout<<"\n\t\t\t--------------------NO LONGER PRINTING ORIGINAL ID WHAT THE HELL!!!-------------\n";
// // ob3.PUT_ID_IN(b,2,3);
// // cout<<ob3;
// // cout<<"\n\t\t\t--------------------MAKE OBJECT=Type of ID (check program code) to print same data again-------------\n";
// // ob3=5;
// // cout<<ob3;
// // pause;



// // /*SEARCHING AND DELETING IDs*/
// // ob2.Delete_ID(41);
// // ob2.Delete_ID("Helta Bockny");
// // cout<<ob2;
// // ob2.Search_ID("Jhika Moctol");
// // ob2.Search_ID(18467);
// // pause;


// // /*MANUALLY INPUTTING DATA*/
// // ID ob1;
// // cin>>ob1;
// // cout<<ob1;
// // pause;




// }