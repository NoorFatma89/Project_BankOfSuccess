#ifndef ACCOUNTFACTORY_H
#define ACCOUNTFACTORY_H

#include <string>
#include "IAccountImpl.h"
#include "SavingsImpl.h"
#include "CurrentImpl.h"

class AccountImplFactory
{
public:
    static IAccountImpl *createAccount(const string &);
};

#endif