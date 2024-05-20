#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

// #include <iostream>
// #include <string>
#include "../Exception/CustomException.h"
#include "../Data/Account.h"
#include "../Data/TransferLog.h"
#include "../Log/Logger.h"
// #include "../Data/AccountImplFactory.h"
// #include "../Data/IAccountImpl.h"

class AccountManager
{
private:
    // Logger object for logging
    Logger *logger;

public:
    AccountManager();
    AccountManager(Logger* logger);
    bool deposit(Account, double, int);
    bool withdraw(Account, double, int);
    bool transfer(Account, Account, double, int);
    bool close(Account, long, int);
};

#endif