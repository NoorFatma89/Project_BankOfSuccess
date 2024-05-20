#ifndef SAVINGSIMPL_H
#define SAVINGSIMPL_H

#include "IAccountImpl.h"
#include "../Exception/CustomException.h"
#include "Savings.h"


class SavingsImpl : public IAccountImpl
{
public:
    virtual bool open(Account *account) override;
};

#endif