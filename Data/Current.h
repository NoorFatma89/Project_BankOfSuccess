#ifndef CURRENT_H
#define CURRENT_H

#include <string>
#include "Account.h"

using namespace std;


// Entity Class
//  Class that represents a type of account which is for companies
//  Specific information for a Current account holder is defined in the class
class Current : public Account
{
private:
    string registrationNo;
    string companyName;
    string websiteURL;

public:
    string getRegistrationNumber();
    void setRegistrationNumber(string );
    string getWebsiteURL();
    void setWebsiteURL(string );
    string getCompanyName();
    void setCompanyName(string );
};

#endif