#include"Impartial_Tech.h"

template<class U> 
class CybernetComputer:public Impartial_Tech<U>
{   
    public:
    void displayer();
    int intlength(int);
    int itemnamelength(U name);

};



template class CybernetComputer<string>;