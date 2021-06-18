#include<iostream>
#include<iomanip>
#include<fstream>
#pragma once
using namespace std;

class food
{
	string* menu;
	double* price;
	int store;
	double reciept;
	int* num, quantity;
	int* order;
	public:
		food(string* a, int b, double* c);
		food();
		friend ostream& operator << (ostream& os, food& f);
		friend istream& operator >> (istream& is, food& f);
		void showmenu();
		void customshow(long int p);
		void orderName();
		void showorder(int);
		void showreceipt();
		void Insert_In_file();
		void Extract_from_file();
		void Enter_Data();
};
