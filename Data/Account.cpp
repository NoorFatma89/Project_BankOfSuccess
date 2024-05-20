#include "Account.h"

long Account::getAccountNumber()
{
    return accountNumber;
}

void Account::setAccountNumber()
{
    srand(time(NULL));
    this->accountNumber = rand() % 1000 + 1000;
}

string Account::getName()
{
    return name;
}

void Account::setName(string name)
{
    this->name = name;
}

int Account::getPinNumber()
{
    return pinNumber;
}

bool Account::setPinNumber(int pin)
{
    if (pin >= 1000 && pin <= 9999)
    {
        return true;
    }
    else
    {
        return false;
    }
    this->pinNumber = pin;
}

// if ()
//     {
//         this->pinNumber = pin;
//         return true;
//     }
//     else
//     {
//         // If PIN is not 4 digits, throw an exception
//         throw CustomException("PIN number must be a 4-digit number!");
//         return false; // This line is not strictly necessary since we're throwing an exception
//     }

double Account::getBalance()
{
    return balance;
}

void Account::setBalance(double balance)
{
    this->balance = balance;
}

Account::Privilege Account::getPrivilege()
{
    return privilege;
}

void Account::setPrivilege(Privilege privilege)
{
    this->privilege = privilege;
}

bool Account::getIsActive()
{
    return isActive;
}

void Account::setIsActive(bool isActive)
{
    this->isActive = isActive;
}

tm Account::getActivatedDate()
{
    return activatedDate;
}

void Account::setActivatedDate(tm activatedDate)
{
    this->activatedDate = activatedDate;
}

tm Account::getClosedDate()
{
    return closedDate;
}

void Account::setClosedDate(tm closedDate)
{
    this->closedDate = closedDate;
}
