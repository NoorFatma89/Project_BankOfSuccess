#include "TransferLog.h"

TransferLog::TransferLog() : transferredAmount(0) {}

// Method to Log the transfer
void TransferLog::addToLog(long accountNo, double amount)
{
    transferredAmount += amount;
    mp[accountNo] = amount;
}

// Method to get the transfers done : how much transfer is done already
double TransferLog::getTransferAmountFromLog()
{
    return transferredAmount;
}

// method to check Is max limit Exeeded
bool TransferLog::isMaxLimitExeeded()
{
    if (getTransferAmountFromLog() > 100000)
        return true;
    else
        return false;
}
