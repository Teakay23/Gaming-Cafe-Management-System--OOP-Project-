#pragma once
#include"Impartial_Tech.h"
template<class U>
class RegularEquipment:public Impartial_Tech<U>
{
    public:
    void get_data();
    void displayer();
    void modelsetter(int *);
    void extract_file();
    int intlength(int);
    int itemnamelength(U name);
};
template class RegularEquipment<string>;