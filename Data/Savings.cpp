#include "Savings.h"

string Savings::getPhoneNumber()
{
    return this->phoneNumber;
}

void Savings::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

string Savings::getGender()
{
    return this->gender;
}

void Savings::setGender(string gender)
{
    this->gender = gender;
}

time_t Savings::getDateOfBirth()
{
    return this->dateOfBirth;
}

void Savings::setDateOfBirth(time_t dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

//method to get year from date of birth
int Savings::getYearFromDateOfBirth(time_t dob)
{
    struct tm* tmPtr = localtime(&dob);
    return tmPtr->tm_year + 1900; // tm_year is years since 1900
}

//method to get Current Year
int Savings::getCurrentYear()
{
    // Get the current time point
    auto now = std::chrono::system_clock::now();

    // Convert the time point to a time since epoch
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // Convert the time since epoch to a tm structure (time information)
    std::tm* time_info = std::localtime(&now_time);

    // Extract the current year from the tm structure
    int current_year = time_info->tm_year + 1900;

    return current_year;
}
