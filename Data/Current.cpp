#include "Current.h"

string Current::getRegistrationNumber()
{
    return registrationNo;
}

void Current::setRegistrationNumber(string registrationNo)
{
    this->registrationNo = registrationNo;
}

string Current::getWebsiteURL()
{
    return this->websiteURL;
}

void Current::setWebsiteURL(string websiteURL)
{
    this->websiteURL = websiteURL;
}

string Current::getCompanyName()
{
    return this->companyName;
}

void Current::setCompanyName(string companyName)
{
    this->companyName = companyName;
}