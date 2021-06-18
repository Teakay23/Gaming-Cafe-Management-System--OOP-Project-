#include "ticketInfo.h"

ticketInfo::ticketInfo(){}

ticketInfo::ticketInfo(Date cur, Time st, Time en, int pr, int se, int bo): currentFile(cur), startFile(st), endFile(en), priceFile(pr), seatFile(se), bookingFile(bo){}

void ticketInfo::writeInfoToFile(string uname)
{
    ofstream outfile("CustomerHistory.dat", ios::binary | ios::app);
    outfile.write(uname.c_str(), uname.length()+1);
    outfile.write(reinterpret_cast<char*> (this), sizeof(*this));
    outfile.close();
}