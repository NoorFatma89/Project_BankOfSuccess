#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <ctime>
using namespace std;

// Entity Class
// Class that represents an account of an account holder in the bank
// Common information across accounts is defined in the class
class Account
{
public: 
    // creating an enumeration Privilege to indicate the type of the customer
    enum Privilege
    {
        PREMIUM,
        GOLD,
        SILVER
    };

private:
    long accountNumber;
    string name;
    int pinNumber;
    double balance;
    Privilege privilege;
    bool isActive;
    tm activatedDate;
    tm closedDate;
    int age;

public:
    long getAccountNumber();
    virtual ~Account() {};
    void setAccountNumber();
    string getName();
    void setName(string );
    int getPinNumber();
    bool setPinNumber(int );
    double getBalance();
    void setBalance(double );
    Privilege getPrivilege();
    void setPrivilege(Privilege );
    bool getIsActive();
    void setIsActive(bool );
    tm getActivatedDate();
    void setActivatedDate(tm );
    tm getClosedDate();
    void setClosedDate(tm);
};

#endif