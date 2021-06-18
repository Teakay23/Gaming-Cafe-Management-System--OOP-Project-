#include "Impartial_Tech.h"
#include"RegularEquipment.h"
#include"CybernetComputer.h"


int main()
{
    // string a[]={"SORX11111", "Speggie9998", "Schochnee","Commjuck 9000", "Draxer09997"};
    // int b[]={8,89,3,6,3};
    // CybernetComputer <string>Computer;
    // Computer.modelsetter(a,b,5);
    // clear;
    // Computer.displayer();
    // CybernetComputer<string>Computer;
    // Computer.get_data();
    // clear;
    // Computer.displayer();

// clear;
//     string c[]={"9", "SaxaT", "B0"};
//     int d[]={7,4,56};
//     AudioSupport <string>Router;
//     Router.modelsetter(c,d,3);
//     Router.displayer();
// int c[]={1,2,3,4,5,6,7,8,9,10,11,12};
//     RegularEquipment <string>R1;
//     // R1.modelsetter(c);
//     R1.displayer();

Impartial_Tech<string>*I=new RegularEquipment<string>;
I->displayer();
I=new CybernetComputer<string>;
I->displayer();
}