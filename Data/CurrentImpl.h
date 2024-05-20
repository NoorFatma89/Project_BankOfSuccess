#ifndef CURRENTIMPL_H
#define CURRENTIMPL_H

#include "IAccountImpl.h"
#include "../Exception/CustomException.h"
#include "Current.h"

class CurrentImpl : public IAccountImpl
{
public:
    virtual bool open(Account *) override;
};

#endif