#ifndef SAVINGS_H
#define SAVINGS_H

#include <chrono>
#include "Account.h"
using namespace std;

// Entity Class
// Class that represents a type of account which is for individuals of an account holder in the bank
// Specific information for a Savings account holder is defined in the class
class Savings : public Account
{
private:
    time_t dateOfBirth;
    string gender;
    string phoneNumber;

public:
    string getPhoneNumber();
    void setPhoneNumber(string );
    string getGender();
    void setGender(string );
    time_t getDateOfBirth();
    void setDateOfBirth(time_t );
    int getYearFromDateOfBirth(time_t );
    int getCurrentYear();
};

#endif