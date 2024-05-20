#include "AccountImplFactory.h"

IAccountImpl *AccountImplFactory::createAccount(const string &accountType)
{
    if (accountType == "SAVINGS")
        return new SavingsImpl();
    else if (accountType == "CURRENT")
        return new CurrentImpl();
    else
        return nullptr;
}
