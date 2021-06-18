#include"CybernetComputer.h"
#include"RegularEquipment.cpp"
template<class U>
int CybernetComputer<U>::intlength(int a)
{ 
    int count=0;
    again:
    a=a/10;
    count++;
    if(a!=0)
    goto again;
    return count;
}
template<class U>
int CybernetComputer<U>::itemnamelength(U name)
{
    return name.length();
}
template<class U>
void CybernetComputer<U>::displayer()
{
   
Impartial_Tech<U>::extract_file();
nxt;
cout<<"                    __________                                 __________                                    __________               "<<endl; 
cout<<"           ________|          |________               ________|          |________                  ________|          |________      "<<endl; 
cout<<"          |       /   ||||||   \\       |             |       /   ||||||   \\       |                |       /   ||||||   \\       |     "<<endl; 
cout<<"          |     ,'              `.     |             |     ,'              `.     |                |     ,'              `.     |     "<<endl; 
cout<<"          |   ,'                  `.   |             |   ,'                  `.   |                |   ,'                  `.   |     "<<endl; 
cout<<"          | ,'   ||||||||||||||||   `. |             | ,'   ||||||||||||||||   `. |                | ,'   ||||||||||||||||   `. |     "<<endl; 
cout<<"          ,'  /____________________\\  `._            ,'  /____________________\\  `._               ,'  /____________________\\  `._    "<<endl; 
cout<<"         /______________________________\\           /______________________________\\              /______________________________\\   "<<endl; 
cout<<"        |                                |         |                                |            |                                |  "<<endl; 
cout<<"        |                                |         |                                |            |                                |  "<<endl; 
cout<<"        |                                |         |                                |            |                                |  "<<endl; 
cout<<"        |________________________________|         |________________________________|            |________________________________|  "<<endl; 
cout<<"          |____________________------__|             |____________________------__|                |____________________------__|    "<<endl; 
cout<<""<<endl; 
cout<<""<<endl; 
cout<<"                    _________________                                                ___________________________________________________"<<endl;                                            
cout<<"                   /                /|                                               |   <<<<<<<<<<<<<<<INVENTORY  LIST>>>>>>>>>>>>>   |"<<endl;                              
cout<<"                  /                / |                                               |_________________________________________________|"<<endl;                         
cout<<"                 /________________/ /|                                               |-"<<*((U*)(Impartial_Tech<U>::type)+0)<<setfill(' ')<<setw(42-itemnamelength(*((U*)(Impartial_Tech<U>::type)+0)))<<"x"<<Impartial_Tech<U>::inventory[0]<<setfill(' ')<<setw(7-intlength(Impartial_Tech<U>::inventory[0]))<<"|"<<endl;                 
cout<<"              ###|      ____      |//|                                               |                                                 |"<<endl;         
cout<<"             #   |     /   /|     |/.|                                               |-"<<*((U*)(Impartial_Tech<U>::type)+1)<<setfill(' ')<<setw(42-itemnamelength(*((U*)(Impartial_Tech<U>::type)+1)))<<"x"<<Impartial_Tech<U>::inventory[1]<<setfill(' ')<<setw(7-intlength(Impartial_Tech<U>::inventory[1]))<<"|"<<endl;      
cout<<"            #  __|___ /   /.|     |  |_______________                                |                                                 |"<<endl;
cout<<"           #  /      /   //||     |  /              /|                  ___          |-"<<*((U*)(Impartial_Tech<U>::type)+2)<<setfill(' ')<<setw(42-itemnamelength(*((U*)(Impartial_Tech<U>::type)+2)))<<"x"<<Impartial_Tech<U>::inventory[2]<<setfill(' ')<<setw(7-intlength(Impartial_Tech<U>::inventory[2]))<<"|"<<endl;    
cout<<"          #  /      /___// ||     | /              / |                 / \\ \\         |                                                 |"<<endl;
cout<<"          # /______/!   || ||_____|/              /  |                /   \\ \\        |-"<<*((U*)(Impartial_Tech<U>::type)+3)<<setfill(' ')<<setw(42-itemnamelength(*((U*)(Impartial_Tech<U>::type)+3)))<<"x"<<Impartial_Tech<U>::inventory[3]<<setfill(' ')<<setw(7-intlength(Impartial_Tech<U>::inventory[3]))<<"|"<<endl;      
cout<<"          #| . . .  !   || ||                    /  _________________/     \\ \\       |                                                 |"<<endl;
cout<<"          #|  . .   !   || //      ________     /  /\\________________  {   /  }      |-"<<*((U*)(Impartial_Tech<U>::type)+4)<<setfill(' ')<<setw(42-itemnamelength(*((U*)(Impartial_Tech<U>::type)+4)))<<"x"<<Impartial_Tech<U>::inventory[4]<<setfill(' ')<<setw(7-intlength(Impartial_Tech<U>::inventory[4]))<<"|"<<endl;    
cout<<"          /|   .    !   ||//~~~~~~/   0000/    /  / / ______________  {   /  /       |                                                 |"<<endl;
cout<<"         / |        !   |'/      /9  0000/    /  / / /             / {   /  /        |-"<<*((U*)(Impartial_Tech<U>::type)+5)<<setfill(' ')<<setw(42-itemnamelength(*((U*)(Impartial_Tech<U>::type)+5)))<<"x"<<Impartial_Tech<U>::inventory[5]<<setfill(' ')<<setw(7-intlength(Impartial_Tech<U>::inventory[5]))<<"|"<<endl;       
cout<<"        / #\\________!___|/      /9  0000/    /  / / /_____________/___  /  /         |                                                 |"<<endl;
cout<<"       / #     /_____\\/        /9  0000/    /  / / /_  /\\_____________\\/  /          |-"<<*((U*)(Impartial_Tech<U>::type)+6)<<setfill(' ')<<setw(42-itemnamelength(*((U*)(Impartial_Tech<U>::type)+6)))<<"x"<<Impartial_Tech<U>::inventory[6]<<setfill(' ')<<setw(7-intlength(Impartial_Tech<U>::inventory[6]))<<"|"<<endl;      
cout<<"      / #                      ``^^^^^^    /   \\ \\ . ./ / ____________   /           |                                                 |"<<endl;
cout<<"     +=#==================================/     \\ \\ ./ / /.  .  .  \\ /  /            |-"<<*((U*)(Impartial_Tech<U>::type)+7)<<setfill(' ')<<setw(42-itemnamelength(*((U*)(Impartial_Tech<U>::type)+7)))<<"x"<<Impartial_Tech<U>::inventory[7]<<setfill(' ')<<setw(7-intlength(Impartial_Tech<U>::inventory[7]))<<"|"<<endl;    
cout<<"     |#                                   |      \\ \\/ / /___________/  /             |                                                 |"<<endl;
cout<<"     #                                    |_______\\__/________________/              |-"<<*((U*)(Impartial_Tech<U>::type)+8)<<setfill(' ')<<setw(42-itemnamelength(*((U*)(Impartial_Tech<U>::type)+8)))<<"x"<<Impartial_Tech<U>::inventory[8]<<setfill(' ')<<setw(7-intlength(Impartial_Tech<U>::inventory[8]))<<"|"<<endl;       
cout<<"     |                                    |               |  |  / /                  |                                                 |"<<endl;
cout<<"     |                                    |               |  | / /                   |-"<<*((U*)(Impartial_Tech<U>::type)+9)<<setfill(' ')<<setw(42-itemnamelength(*((U*)(Impartial_Tech<U>::type)+9)))<<"x"<<Impartial_Tech<U>::inventory[9]<<setfill(' ')<<setw(7-intlength(Impartial_Tech<U>::inventory[9]))<<"|"<<endl;    
cout<<"     |                                    |       ________|  |/ /________            |_________________________________________________|"<<endl;
cout<<"     |                                    |      /_______/    \\_________/\\           | OVERALL NUMBER OF EQUIPMENT:"<<Impartial_Tech<U>::items<<setfill(' ')<<setw(21-intlength(Impartial_Tech<U>::items))<<"|"<<endl;
cout<<"     |                                    |     /        /  /           \\ )          | AMOUNT FOR REPAIRS AND MAINTENANCE: $"<<Impartial_Tech<U>::price<<setfill(' ')<<setw(10-intlength(Impartial_Tech<U>::price))<<"|"<<endl;
cout<<"     |                                    |    /  ^^^^^^/  / /^^^^^^^^^  \\)          |_________________________________________________|"<<endl;
cout<<"     |                                    |            /  / /        "<<endl; 
cout<<"     |                                    |           /  / /"<<endl; 
cout<<"     |                                    |          /___\\/"<<endl; 
cout<<"     |____________________________________|"<<endl;                     
cout<<" "<<endl; 
cout<<"     ,----------------------------------------------------,                           ,----------------------------------------------------,"<<endl; 
cout<<"     | [][][][][]  [][][][][]  [][][][]  [][__]  [][][][] |                           | [][][][][]  [][][][][]  [][][][]  [][__]  [][][][] |   "<<endl;  
cout<<"     |                                                    |                           |                                                    |   "<<endl;   
cout<<"     |  [][][][][][][][][][][][][][_]    [][][]  [][][][] |                           |  [][][][][][][][][][][][][][_]    [][][]  [][][][] |   "<<endl;   
cout<<"     |  [_][][][][][][][][][][][][][ |   [][][]  [][][][] |                           |  [_][][][][][][][][][][][][][ |   [][][]  [][][][] |   "<<endl;   
cout<<"     | [][_][][][][][][][][][][][][]||     []    [][][][] |                           | [][_][][][][][][][][][][][][]||     []    [][][][] |  "<<endl;    
cout<<"     | [__][][][][][][][][][][][][__]    [][][]  [][][]|| |                           | [__][][][][][][][][][][][][__]    [][][]  [][][]|| |   "<<endl;   
cout<<"     |   [__][________________][__]              [__][]|| |                           |   [__][________________][__]              [__][]|| |   "<<endl;   
cout<<"     `----------------------------------------------------'                           `----------------------------------------------------' "<<endl; 




}
