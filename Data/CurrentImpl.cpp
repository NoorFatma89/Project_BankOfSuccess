#include "CurrentImpl.h"

bool CurrentImpl::open(Account *account)
{
    bool isOpen = false;

    // Logic to open current account
    Current currentAccount = dynamic_cast<Current &>(*account);
    if (!currentAccount.getRegistrationNumber().empty())
    {
        isOpen = true;
    }
    else
    {
        throw CustomException("You are not eligible");
    }

    return isOpen;
}
