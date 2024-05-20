#ifndef IACCOUNTIMPL_H
#define IACCOUNTIMPL_H

#include "Account.h"

class IAccountImpl
{
public:
    virtual bool open(Account *account)=0;
};

#endif