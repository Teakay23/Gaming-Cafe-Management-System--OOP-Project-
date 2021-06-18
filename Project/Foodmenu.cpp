#include"Foodmenu.h"
void food::Enter_Data()
{
	foodrepeat:
	cout<<"Enter the Quantity of food you would like to exist on the menu(1-14)"<<endl;
	cin>>store;
	menu = new string[store];
	price = new double[store];
	if(store<1 || store>14)
	goto foodrepeat;
	for (int i=0;i<store;i++)
	{
		fooditemlimit:
		cout<<"Enter Food Item Number#"<<i+1<<" :";
		cin.ignore();
		getline(cin,menu[i]);
		if(menu[i].length()>16)
		goto fooditemlimit;
		pricelimit:
		cout<<"Enter the Price of "<<menu[i]<<" :";
		cin>>price[i];
		if(price[i]>9999)
		goto pricelimit;
		
	}

}
void food::Extract_from_file()
{
	ifstream infile("food.dat", ios::out);
	infile.read((char *)&store, sizeof(store));
	menu = new string[store];
	price = new double[store];
	for(int i=0;i<store;i++)
	{
		getline(infile, menu[i], '\0');
		infile>>price[i];
	}

}
void food::Insert_In_file()
{
	ofstream outfile("food.dat", ios::in);
	outfile.write(reinterpret_cast<char *> (&store), sizeof(store));
	for(int i=0; i<store;i++)
	{
		outfile.write(menu[i].c_str(), menu[i].length()+1);
		outfile<<price[i];
	}

}
food::food(string* a, int b, double* c):store(b)
{
	menu = a;
	price = c;
}

food::food()
{
	string a[5] = {"Biryani", "Pizza", "Burger", "French Fries", "Cold Drink"};
	double c[5] = {75, 170, 90, 50, 35};
	menu = a;
	price = c;
	store=5;
}

void food::showmenu()
{
	cout << "\t\t\t\t\t\t\t|" << "Sr." << left <<setfill(' ')<< setw(40) << " Menu" << left <<setfill(' ')<< setw(4) << " Price |" << endl;
	cout << "\t\t\t\t\t\t\t|--------------------------------------------------|" << endl << endl;
	for(int i=0 ; i< store ; i++)
	{
		cout << "\t\t\t\t\t\t\t|" << left <<setfill(' ')<< setw(2) << i+1 << ". " << left <<setfill(' ')<< setw(40) << menu[i] << left <<setfill(' ')<< setw(5) << price[i] << " |" << endl;
	}
	cout<<right;
}

void food::customshow(long int p)
{
	int c=0;
	cout << "\t\t\t\t\t\t\t|" << "Sr." << left <<setfill(' ')<< setw(40) << " Menu" << left<<setfill(' ') << setw(4) << " Price |" << endl;
	cout << "\t\t\t\t\t\t\t|--------------------------------------------------|" << endl << endl;
	for(int i=0 ; i< store ; i++)
	{
	if(price[i] <= p)
	cout << "\t\t\t\t\t\t\t|" << left <<setfill(' ')<< setw(2) << ++c << ". " << left << setw(40) << menu[i] << left <<setfill(' ')<< setw(5) << price[i] << " |" << endl;	
	}
	cout<<right; 
}

void food::showorder(int many)
{
	cout << "Your Order are as follows : " << endl;
	cout << "\t\t\t\t\t\t\t|" << left<<setfill(' ') << setw(40) <<  "Order" << left<<setfill(' ') << setw(4) << " Price |" << endl;
	cout << "\t\t\t\t\t\t\t|--------------------------------------------------|" << endl << endl;
	for(int i=0 ; i < many ; i++)
	{
		cout << "\t\t\t\t\t\t\t|" << left <<setfill(' ')<< setw(40) << menu[order[i]-1] << left <<setfill(' ')<< setw(5) << price[order[i]-1] << " |" << endl;
		reciept += price[order[i]-1]; 
	}
}

void food::showreceipt()
{
	cout << "Total Price : " << reciept << endl;
}

void food::orderName()
{
	int many;
	cout << "Enter how much things you want to buy ?" << endl;
	cin >> many;
	int ord[many];
	order = ord;
	cout << "Enter the number of Menu Items " << endl;
	for(int i=0 ; i < many ; i++)
	{
		again:
		cout << "Item # " << i+1 << " : " << endl;
		cin >> ord[i];
		if(ord[i] > store)
		{
			cout << "The menu number is not in the menu list. You've been redirected to input the item number again." << endl;
			system("PAUSE");
			goto again;
		}
		else
		{
			cout << "Match found" << endl;
		}
	}
	showorder(many);
	showreceipt();
	cout << "Your order has been stored and has been sent to chef." << endl;
}

istream& operator >> (istream& is, food& f)
{
	f.Enter_Data();
	return is;
}

ostream& operator << (ostream& os, food& f)
{
	f.showmenu();
	return os;
}
