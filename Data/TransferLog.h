#ifndef TRANSFER_H
#define TRANSFER_H

#include <map>

class TransferLog
{
private:
    // Here I have a property to store the transfers done for an account
    double transferredAmount;

    // Collection - Map - Key Value (long, double)
    std::map<long, double> mp;

public:
    TransferLog();
    void addToLog(long , double );
    double getTransferAmountFromLog();
    bool isMaxLimitExeeded();
};

#endif