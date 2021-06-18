#include"Impartial_Tech.h"

template<class U>
void Impartial_Tech<U>::extract_file()
{
    inventory=new int[10];
    U *ptr=new U[10];   
    ifstream infile("Computers.dat");
    infile.read((char *)&no_of_models,sizeof(no_of_models));
    for(int i=0;i<10;i++)
    {
        getline(infile, ptr[i],'\0');
        infile.read((char *)&inventory[i], sizeof(inventory[i]));
        items+=inventory[i];
    }
    type=reinterpret_cast<U*> (ptr);
     infile.read((char *)&price,sizeof(price));
}
template<class U>
void Impartial_Tech<U>::input_file()
{
    
}

template<class U>
void Impartial_Tech<U>::get_data()
{
    Amount_Equipment:
    cout<<"Enter The Amount Of Type Of Equipment(1-10 LIMIT):"<<endl;
    cin>>no_of_models;
    if(no_of_models<1 || no_of_models>10)
    goto Amount_Equipment;
    inventory=new int[10];
    U *ptr=new U[10];
    cin.ignore();
    for(int i=0;i<10;i++)
    {
        if(i<no_of_models)
        {
            cout<<"Enter The Brand Name For The Equipment You're Using:"<<endl;
            getline(cin,ptr[i]);
            cout<<"Quantity In Inventory For "<<ptr[i]<<" :"<<endl;
            cin>>inventory[i];
            cin.ignore();
        }
        else
        {
            ptr[i]="NONE ALLOTED";
            inventory[i]=0;
        }
        items+=inventory[i];
     
    }

    price=price*items;
    type=reinterpret_cast<U*> (ptr);
    ofstream outfile("Computers.dat");
    outfile.write(reinterpret_cast<char *>(&no_of_models),sizeof(no_of_models));
    for(int i=0;i<10;i++)
    {
        outfile.write(ptr[i].c_str(), ptr[i].length()+1);
        
        outfile.write( reinterpret_cast<char *>(&inventory[i]),  sizeof(inventory[i]));
    }
    outfile.write(reinterpret_cast<char *>(&price),sizeof(price));

}
template<class U>
void Impartial_Tech<U>::modelsetter(U *a, int *b,int n)
{
    no_of_models=n;   
    inventory=new int[10];
    U *ptr=new U[10];
    for(int i=0;i<10;i++)
    {
        if(i<n)
        {
            ptr[i]=a[i];
            inventory[i]=b[i];
             
        }
        else
        {
            ptr[i]="NONE ALLOTED";
            inventory[i]=0;
        }
    items+=inventory[i];
}
    price=price*items;
    
    type=reinterpret_cast<U*> (ptr);
    string temp;
    ofstream outfile("Computers.dat");
    outfile.write(reinterpret_cast<char *>(&no_of_models),sizeof(no_of_models));
    for(int i=0;i<10;i++)
    {
        temp=ptr[i];
        outfile.write(ptr[i].c_str(), ptr[i].length()+1);
        
        outfile.write( reinterpret_cast<char *>(&inventory[i]),  sizeof(inventory[i]));
    }
    outfile.write(reinterpret_cast<char *>(&price),sizeof(price));

}
